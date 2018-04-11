#include "Parser.h"
#include "BikeCompany.h"
#include "menu.h"
using namespace std;

int main()
{
    Parser p;
    vector <SharingSpot> sharingSpots;
    vector <Node> nodes = p.readNodes("Nodes.txt");
    vector <Street> streets = p.readStreets("Streets.txt");
    p.readRelations("Relations.txt",streets,nodes, sharingSpots);
    User user = askUser();

    BikeCompany company(nodes, streets, sharingSpots, user); //Not working cause every street has idNodeInicial = 4 which doesn't exist.

    startMenu(company);

    return 0;
}
