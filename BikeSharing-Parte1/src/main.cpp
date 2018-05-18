#include "Parser.h"
#include "BikeCompany.h"
#include "menu.h"
using namespace std;

#define nodesFile "NodesV2.txt"
#define streetsFile "StreetsV2.txt"
#define relationsFile "RelationsV2.txt"

int main()
{
    Parser p;
    vector <SharingSpot> sharingSpots;
    vector <Node> nodes = p.readNodes(nodesFile);
    vector <Street> streets = p.readStreets(streetsFile);
    p.readRelations(relationsFile,streets,nodes, sharingSpots);
    User user = askUser();

    BikeCompany company(nodes, streets, sharingSpots, user);

    Utilities::clearScreen();
    startMenu(company);

    return 0;
}
