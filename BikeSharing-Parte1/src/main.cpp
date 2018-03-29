#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
    Parser p;

    vector <Node> nodes = p.readNodes("BikeSharing-Parte1\\Nodes.txt");
    vector <Street> streets = p.readStreets("BikeSharing-Parte1\\Streets.txt");
    vector <Relation> relations = p.readRelations("BikeSharing-Parte1\\Relations.txt");

    for (int i = 0; i < 10 ; ++i) {

        cout << relations.at(i).getRoadID() << endl;
    }
    return 0;

}
