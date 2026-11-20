#include <iostream>
#include "Location.h"
using namespace std;

int main()
{
    cout << boolalpha;

    Location* hub = new Location("L01", PACKING, "Packing_North");
    Location* second = new Location("L02", RACK, "Rack_Zone_A1");
    Location* third = new Location("L03", RACK, "Rack_Zone_A2");
    Location* fourth = new Location("L04", RACK, "Rack_Zone_A3");

    hub->addEdge(second, 3, OPEN);
    hub->addEdge(third, 5, OPEN);
    hub->addEdge(fourth, 6, OPEN);
    cout << "Edges after adding three: " << hub->countEdges() << endl;
    cout << "First edge points to: " << hub->getFirstEdge()->destination->getID() << endl;

    cout << "Remove middle L03: " << hub->removeEdge("L03") << endl;
    cout << "Edges: " << hub->countEdges() << endl;
    cout << "L03 still found: " << (hub->findEdge("L03") != NULL) << endl;
    cout << "L04 still found: " << (hub->findEdge("L04") != NULL) << endl;
    cout << "L02 still found: " << (hub->findEdge("L02") != NULL) << endl;

    cout << "Remove first L04: " << hub->removeEdge("L04") << endl;
    cout << "Edges: " << hub->countEdges() << endl;
    cout << "L04 still found: " << (hub->findEdge("L04") != NULL) << endl;
    cout << "L02 still found: " << (hub->findEdge("L02") != NULL) << endl;

    cout << "Remove last L02: " << hub->removeEdge("L02") << endl;
    cout << "Edges: " << hub->countEdges() << endl;
    cout << "First edge is NULL: " << (hub->getFirstEdge() == NULL) << endl;

    cout << "Remove from empty list: " << hub->removeEdge("L02") << endl;

    delete hub;
    delete second;
    delete third;
    delete fourth;

    cout << "Finished without crashing" << endl;
    return 0;
}