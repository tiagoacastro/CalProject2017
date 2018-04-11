#include "Parser.h"
#include "BikeCompany.h"
#include "menu.h"
using namespace std;

int main()
{
    Parser p;
    vector <SharingSpot> sharingSpots;
    //vector <Node> nodes = p.readNodes("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Nodes.txt", sharingSpots);
    //vector <Street> streets = p.readStreets("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Streets.txt");
    //p.readRelations("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Relations.txt", streets,nodes);
//    vector <Node> nodes = p.readNodes("C:\\Users\\tiago\\Desktop\\Faculdade\\CAL\\CalProject2017\\BikeSharing-Parte1\\Nodes.txt", sharingSpots);
//    vector <Street> streets = p.readStreets("C:\\Users\\tiago\\Desktop\\Faculdade\\CAL\\CalProject2017\\BikeSharing-Parte1\\Streets.txt");
//    p.readRelations("C:\\Users\\tiago\\Desktop\\Faculdade\\CAL\\CalProject2017\\BikeSharing-Parte1\\Relations.txt", streets,nodes);
    vector <Node> nodes = p.readNodes("Nodes.txt");
    vector <Street> streets = p.readStreets("Streets.txt");
    p.readRelations("Relations.txt",streets,nodes, sharingSpots);
    User user = askUser();

    BikeCompany company(nodes, streets, sharingSpots, user); //Not working cause every street has idNodeInicial = 4 which doesn't exist.

    startMenu(company);

    //company.getNearestSharingSpot(nodes[68]);


    //    company.printGraph();
    //    Graph <Node> g = company.getGraph();
    //    g.dijkstraShortestPath(Node (258723347));
    //    vector <Node> v = g.getPath(Node (258723347), Node (1605526218));

    return 0;
}
