#include "Parser.h"
#include "BikeCompany.h"
#include "Utilities.h"
#include "graph.h"
using namespace std;

User askUser(){
    int choice;
    string info;
    cout << "Choose a Payment Method: " << endl
    << "1: Credit Card" << endl
    << "2: PayPal" << endl;
    while(true) {
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid choice, choose one of the payment methods (1 or 2)" << endl;
            //Clearing error flag and cin buffer
            Utilities::clearCinBuffer();
        } else {
            if (choice == 1 || choice == 2) {
                break;
            }else {
                cout << "Invalid choice, choose one of the payment methods (1 or 2)" << endl;
                //Clearing error flag and cin buffer
                Utilities::clearCinBuffer();
            }
        }
    }
    cout << "Insert your payment Information: " << endl;
    Utilities::clearCinBuffer();
    switch(choice) {
        case 1:
            while (true) {
                getline(cin, info);
                if (cin.fail()) {
                    cout << "Invalid Creditcard Number, must have 16 digits" << endl;
                    //Clearing error flag and cin buffer
                    Utilities::clearCinBuffer();
                } else {
                    //if cin didn't fail we have a good input so we can check the input and if it's acceptable, break the loop
                    Utilities::trimString(info);
                    if (Utilities::isNumber(info) && info.size() == 16)
                        break;
                    else {
                        cout << "Invalid Creditcard Number, must have 16 digits" << endl;
                    }
                }
            }
            return User(PaymentMethod::CreditCard, info);
        case 2:
            while (true) {
                getline(cin, info);
                if (cin.fail()) {
                    cout << "Invalid PayPal e-mail, must be of format ~~~@~~~.~~~~" << endl;
                    //Clearing error flag and cin buffer
                    Utilities::clearCinBuffer();
                } else {
                    //if cin didn't fail we have a good input so we can check the input and if it's acceptable, break the loop
                    Utilities::trimString(info);
                    if (Utilities::isEmail(info))
                        break;
                    else {
                        cout << "Invalid PayPal e-mail, must be of format ~~~@~~~.~~~~" << endl;
                    }
                }
            }
            return User(PaymentMethod::PayPal, info);
    }
    return User();
}

int main()
{
    Parser p;
    vector <SharingSpot> sharingSpots;
    //vector <Node> nodes = p.readNodes("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Nodes.txt", sharingSpots);
    //vector <Street> streets = p.readStreets("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Streets.txt");
    //p.readRelations("C:\\Users\\jonas\\Desktop\\CAL-PROJ\\BikeSharing-Parte1\\Relations.txt", streets,nodes);
    //vector <Node> nodes = p.readNodes("Nodes.txt", sharingSpots);
    //vector <Street> streets = p.readStreets("Streets.txt");
   // p.readRelations("Relations.txt",streets,nodes);
    //User user;// = askUser();

    //for(int i = 0; i< streets.size();i++)
      //  cout << streets.at(i).getElevation() << endl;

   // cout << nodes[0].getLongitude() << "   " << nodes[0].getLatitude() << endl;

  // BikeCompany company(nodes, streets, sharingSpots, user); //Not working cause every street has idNodeInicial = 4 which doesn't exist.

    //company.printGraph();
    //company.getNearestSharingSpot(nodes[0]);


    //    company.printGraph();
//    Graph <Node> g = company.getGraph();
//    g.dijkstraShortestPath(Node (258723347));
//    vector <Node> v = g.getPath(Node (258723347), Node (1605526218));

    return 0;
}
