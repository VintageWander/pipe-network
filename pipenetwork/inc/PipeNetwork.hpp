#include <Node.hpp>
#include <Tube.hpp>
#include <string>
#include <vector>

#ifndef PIPENETWORK
#define PIPENETWORK

namespace cie::pipenetwork {
    class PipeNetwork {
    public:
        PipeNetwork( const std::string& filename );               // Constructor
        ~PipeNetwork();                                           // Destructor
        std::vector<double> computeFluxes() const;                // Compute fluxes through each tube function (final solution)
        void inputLog();                                          // Function to print out received input data to console
        void resultLog() const;                                   // Function to print out computed solution to console
        void resultToFile( const std::string& currentPath ) const;// Function to write computed solution to file to the current path

    private:
        const std::string& filename_;// Input file name
        int nodesAmount_{};          // Number of nodes_ present in system
        int tubesAmount_{};          // Number of tubes_ present in system
        std::vector<Node*> nodes_;   // Vector storing pointers to all instances of nodes_ in system
        std::vector<Tube*> tubes_;   // Vector storing pointers to all instances of tubes_ in system
    };
}// namespace cie::pipenetwork

#endif
