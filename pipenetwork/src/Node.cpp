#include "Node.hpp"

namespace cie::pipenetwork {
    //constructor
    Node::Node( double x, double y, double flow, int id ) : x_( x ), y_( y ), flow_( flow ), id_( id ) {}
    // x coordinate
    double
    Node::x() const {
        return x_;
    }
    // y coordinate
    double
    Node::y() const {
        return y_;
    }
    // flux through node
    double
    Node::flow() const {
        return flow_;
    }
    // ID of node
    int
    Node::id() const {
        return id_;
    }
}// namespace cie::pipenetwork
