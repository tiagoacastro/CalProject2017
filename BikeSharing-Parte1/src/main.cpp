#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
    Parser p;

    vector <Node> nodes = p.readNodes("C:\\Users\\jonas\\Desktop\\CAL-PROJECT\\BikeSharing-Parte1\\Nodes.txt");
    vector <Street> streets = p.readStreets("C:\\Users\\jonas\\Desktop\\CAL-PROJECT\\BikeSharing-Parte1\\Streets.txt");


    cout << "done";

    return 0;

}
