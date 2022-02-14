#include "PipeNetwork.hpp"
#include "linalg.hpp"
#include <fstream>
#include <iostream>

namespace cie::pipenetwork {
    PipeNetwork::PipeNetwork( const std::string& filename ) : filename_( filename ) {
        // All the reading from the input file is done within the constructor.

        // Read the file from the filename path
        std::ifstream filename1( filename_ );

        // Check if the file is open
        if ( filename1.is_open() ) {
            // Read the file line by line
            // The first line is the amount of nodes
            filename1 >> nodesAmount_;
            // The second line is the amount of tubes
            filename1 >> tubesAmount_;

            // Declare temporary variables to store node values from the .txt file
            double x;
            double y;
            double flux;

            // Reserve spaces equivalent to the amount of nodes for the nodes vector
            nodes_.reserve( nodesAmount_ );
            // Reserve spaces equivalent to the amount of tubes for the tubes vector
            tubes_.reserve( tubesAmount_ );

            // Read node data from .txt file
            for ( int i = 0; i < nodesAmount_; ++i ) {
                filename1 >> x;   // x coordinate
                filename1 >> y;   // y coordinate
                filename1 >> flux;// flux through node

                // Create a new node on the heap with the values from the .txt file
                Node* newNodePtr = new Node( x, y, flux, i );

                // Then push the new pointer to the nodes vector
                // Since the nodes vector is a vector of pointers
                nodes_.push_back( newNodePtr );
            }

            // Declare temporary variables to store tube values from the .txt file
            int node_1;     // Which node defines one end of the tube
            int node_2;     // Which node defines other end of the tube
            double diameter;// Diameter of tube

            // Read tube data from .txt file
            for ( int i = 0; i < tubesAmount_; ++i ) {
                filename1 >> node_1;  // Read the first node connected with current tube
                filename1 >> node_2;  // Read the second node connected with current tube
                filename1 >> diameter;// Read the diameter of the tube

                // Create a new tube on the heap with the values from the .txt file
                Tube* newTubePtr = new Tube( nodes_[ node_1 ], nodes_[ node_2 ], diameter );

                // Then push the new pointer to the tubes vector
                // Since the tubes vector is a vector of pointers
                tubes_.push_back( newTubePtr );
            }
            // Close the file
            filename1.close();
        } else {
            // If the file is not found or can't be opened
            std::cout << "error: could not open file" << std::endl;
        }
    }

    // Destructor
    PipeNetwork::~PipeNetwork() {
        // Since the pointers in the nodes vector and the tube vector has its own memory block on the heap
        // We have to loop over each pointer in the vector and delete it

        // Because this is a destructor, when the program finishes, all the heap memory blocks will be deleted
        for ( int i = 0; i < nodesAmount_; ++i ) {
            delete nodes_[ i ];
        }
        for ( int i = 0; i < tubesAmount_; ++i ) {
            delete tubes_[ i ];
        }
    }

    // Function to compute fluxes through each pipe, based on node and tube data
    std::vector<double>
    PipeNetwork::computeFluxes() const {
        // Create zero-initialized permeability matrix B (#nodes_ x #nodes_) using linear algebra library function
        cie::linalg::Matrix B( nodesAmount_, nodesAmount_ );

        // ∀ tubes i:
        for ( int i = 0; i < tubesAmount_; ++i )//loop over all tubes_
        {
            // Get id1 and id2 of the two bounding nodes
            int nodeID1 = tubes_[ i ]->node1()->id();// Get id of node1
            int nodeID2 = tubes_[ i ]->node2()->id();// Get id of node2

            // Compute permeability factor B_i
            double B_i = tubes_[ i ]->permeability();//store permeability from tubes_ vector

            // Assemble B_i into the B matrix:
            B( nodeID1, nodeID1 ) += B_i;//Add permeability to B matrix in position node1, node1
            B( nodeID2, nodeID2 ) += B_i;//Add permeability to B matrix in position node2, node2
            B( nodeID1, nodeID2 ) -= B_i;//Subtract permeability from B matrix in position node1, node2
            B( nodeID2, nodeID1 ) -= B_i;//Subtract permeability from B matrix in position node2, node1
        }

        // Create load vector Q and initialize vector load_Q of size based on amount of nodes_
        //load_Q represents volumetric flow rate
        std::vector<double> load_Q( nodesAmount_ );

        // ∀ nodes i:
        for ( int i = 0; i < nodesAmount_; ++i )// Initialize load_Q vector with flow stored in nodes_ vector
        {
            // Q[i] = -Q_in[i] (the given (in-/out) flow value)
            load_Q[ i ] = -1 * nodes_[ i ]->flow();
        }

        // for i = 1 ... number nodes:
        for ( int i = 0; i < nodesAmount_; ++i ) {
            // set boundary conditions. this is needed because all formulas are based
            // on the difference in hydraulic head. Absolute value is not specified.

            B( i, 0 ) = 0;// Setting the height of node 1 to 0
            B( 0, i ) = 0;
        }

        B( 0, 0 ) = 1;  // More boundary conditions
        load_Q[ 0 ] = 0;// More boundary conditions

        // Create vector head (hydraulic head) with size of nodesAmount_
        std::vector<double> head( nodesAmount_ );

        // Solve linear equation system to get head vector h
        // Use linalg function to compute head. Bh = load_Q
        head = cie::linalg::solve( B, load_Q );

        // Create zero-initialized vector of fluxes q
        // This is what is needed to compute and output
        std::vector<double> fluxes_q( tubesAmount_ );

        // ∀ tubes i:
        for ( int i = 0; i < tubesAmount_; ++i ) {
            int nodeID1 = tubes_[ i ]->node1()->id();// Take the ID of node1 associated with current tube
            int nodeID2 = tubes_[ i ]->node2()->id();// Take the ID of node2 associated with current tube
            // extract the entries h1 and h2 at the ids of the two bounding nodes from h
            double h1 = head[ nodeID1 ];             // Take the head of node1
            double h2 = head[ nodeID2 ];             // Take the head of node2
            double B_i = tubes_[ i ]->permeability();// Calculate the permeability of current tube
            fluxes_q[ i ] = B_i * ( h1 - h2 );       // Calculate to get the flux of current tube and store in the fluxes_q vector
        }
        // Return the vector of fluxes
        return fluxes_q;
    }

    //function to output input data read from txt file
    void
    PipeNetwork::inputLog() {
        // This function is called after the constructor to output the received input data read from the input file
        std::cout << "Retrieved inputs: " << std::endl;
        std::cout << "Amount of nodes: " << nodesAmount_ << std::endl;
        std::cout << "Amount of tubes: " << tubesAmount_ << std::endl;

        // Print out the nodes
        for ( int i = 0; i < nodesAmount_; ++i ) {
            std::cout << "Node " << i << ": ";
            std::cout << "x = " << nodes_[ i ]->x() << ", y = " << nodes_[ i ]->y() << ", flux = " << nodes_[ i ]->flow() << std::endl;
        }

        // Print out the tubes
        for ( int i = 0; i < tubesAmount_; ++i ) {
            std::cout << "Tube " << i << ": ";
            std::cout << "Node 1 data = " << tubes_[ i ]->node1()->id() << ", Node 2 data = " << tubes_[ i ]->node2()->id() << ", Diameter = " << tubes_[ i ]->diameter() << std::endl;
        }
    }

    // Print the result of fluxes calculation to the console
    void
    PipeNetwork::resultLog() const {
        std::cout << std::endl;
        std::cout << "The results are: " << std::endl;

        std::vector<double> fluxes_q = cie::pipenetwork::PipeNetwork::computeFluxes();// Call compute fluxes function and store it in fluxes_q
        for ( int i = 0; i < tubesAmount_; ++i ) {                                    // Loop over fluxes_q and output results to console
            std::cout << "flux[" << i << "] = " << fluxes_q[ i ] << std::endl;
        }
    }

    // Print the result of fluxes calculation to a file called "pipedata.txt" in the provided path
    void
    PipeNetwork::resultToFile( const std::string& currentPath ) const {
        std::cout << std::endl;
        std::cout << "Creating an output file..." << std::endl;
        // Create a new file called "pipedata.txt" in the provided path
        std::ofstream outfile( currentPath + "/pipedata.txt" );
        std::cout << "Create complete." << std::endl;
        std::cout << "Calculating fluxes..." << std::endl;
        std::vector<double> fluxes_q = cie::pipenetwork::PipeNetwork::computeFluxes();
        std::cout << "Calculation complete." << std::endl;
        std::cout << "Writing to file..." << std::endl;
        for ( int i = 0; i < tubesAmount_; ++i ) {
            outfile << "flux[" << i << "] = " << fluxes_q[ i ] << std::endl;
        }
        outfile.close();
        std::cout << "Write to file complete!" << std::endl;
    }
}// namespace cie::pipenetwork