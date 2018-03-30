#include "Parser.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

int main()
{
    Parser p;

    vector <Node> nodes = p.readNodes("BikeSharing-Parte1\\Nodes.txt");
    vector <Street> streets = p.readStreets("BikeSharing-Parte1\\Streets.txt");
    vector <Relation> relations = p.readRelations("BikeSharing-Parte1\\Relations.txt");
    
    return 0;

}
