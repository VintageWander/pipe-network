#include <Tube.hpp>
#include <cmath>

namespace cie::pipenetwork {
    //constructor: aggregates node1 and node2 information via pointers and diameter data
    Tube::Tube( Node* node1, Node* node2, double diameter ) : node1_( node1 ), node2_( node2 ), diameter_( diameter ) {}

    //calculates and returns length of tube based on data aggregated from node instances
    double
    Tube::length() const {
        double x_distance = node1_->x() - node2_->x();                            //calculates x distance between node1 and node2
        double y_distance = node1_->y() - node2_->y();                            //calculates x distance between node1 and node2
        double length = sqrt( x_distance * x_distance + y_distance * y_distance );//pythagorean theorem
        return length;
    }

    //calculates and returns permeability (B_i) of tube
    double
    Tube::permeability() const {
        const double pi = 3.141592653588979323846;// Value of pi
        const double g = 9.81;                    // Gravity
        const double nu = pow( 10, -6 );          // Viscosity

        //double diameter = diameter();
        double length = Tube::length();                                       // Get the tube length by using the pre-defined length function
        double B_i = ( pi * g * pow( diameter_, 4 ) ) / ( 128 * nu * length );// Given formula for permeability
        return B_i;
    }

    // Pointer to node1
    const Node*
    Tube::node1() const {
        return node1_;
    }

    // Pointer to node2
    const Node*
    Tube::node2() const {
        return node2_;
    }

    // Diameter of tube
    double
    Tube::diameter() const {
        return diameter_;
    }
}// namespace cie::pipenetwork
