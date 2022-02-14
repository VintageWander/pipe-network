#ifndef NODE
#define NODE

namespace cie::pipenetwork {
    //node class
    class Node {
    public:
        Node( double x, double y, double flow, int id );// Constructor
        double x() const;                               // function to get x coordinate
        double y() const;                               // function to get y coordinate
        double flow() const;                            // function to get flux
        int id() const;                                 // function to get node ID
    private:
        double x_;   // x coordinate of node
        double y_;   // y coordinate of node
        double flow_;// flux through node
        int id_;     // ID of each node to identify it
    };
}// namespace cie::pipenetwork
#endif
