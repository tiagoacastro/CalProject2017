#include "menu.h"

User askUser() {
    Utilities::clearScreen();
    int choice;
    string info;
    while (true) {
        cout << "Choose a Payment Method: " << endl
             << "1: Credit Card" << endl
             << "2: PayPal" << endl;
        cin >> choice;
        if (cin.fail()) {
            Utilities::clearScreen();
            cout << "Invalid choice, choose one of the payment methods (1 or 2)" << endl;
            //Clearing error flag and cin buffer
            Utilities::clearCinBuffer();
        } else {
            if (choice == 1 || choice == 2) {
                break;
            } else {
                Utilities::clearScreen();
                cout << "Invalid choice, choose one of the payment methods (1 or 2)" << endl;
                //Clearing error flag and cin buffer
                Utilities::clearCinBuffer();
            }
        }
    }
    Utilities::clearScreen();
    bool stop = true;
    Utilities::clearCinBuffer();
    while (stop) {
        cout << "Insert your payment Information: " << endl;
        switch (choice) {
            case 1:
                getline(cin, info);
                if (cin.fail()) {
                    Utilities::clearScreen();
                    cout << "Invalid Creditcard Number, must have 16 digits" << endl;
                    //Clearing error flag and cin buffer
                    Utilities::clearCinBuffer();
                } else {
                    //if cin didn't fail we have a good input so we can check the input and if it's acceptable, break the loop
                    Utilities::trimString(info);
                    if (Utilities::isNumber(info) && info.size() == 16)
                        stop = false;
                    else {
                        Utilities::clearScreen();
                        cout << "Invalid Creditcard Number, must have 16 digits" << endl;
                    }
                }
                break;
            case 2:
                getline(cin, info);
                if (cin.fail()) {
                    Utilities::clearScreen();
                    cout << "Invalid PayPal e-mail, must be of format ~~~@~~~.~~~~" << endl;
                    //Clearing error flag and cin buffer
                    Utilities::clearCinBuffer();
                } else {
                    //if cin didn't fail we have a good input so we can check the input and if it's acceptable, break the loop
                    Utilities::trimString(info);
                    if (Utilities::isEmail(info))
                        stop = false;
                    else {
                        Utilities::clearScreen();
                        cout << "Invalid PayPal e-mail, must be of format ~~~@~~~.~~~~" << endl;
                    }
                }
                break;
        }
    }
    switch(choice) {
        case 1:
            return User(PaymentMethod::CreditCard, info);
        case 2:
            return User(PaymentMethod::PayPal, info);
    }
}

void startMenu(BikeCompany &company){
    string choice;
    bool ok;
    while(true) {
        Utilities::clearScreen();
        ok = false;
        cout << "1-\tCalculate Path" << endl
             << "2-\tView Graph" << endl
             << "3-\tExit" << endl
             << endl << "Input:" << endl;
        getline(cin, choice);
        if (cin.fail()) {
            Utilities::clearCinBuffer();
        } else {
            Utilities::trimString(choice);
            if(choice == "1" || choice == "2" || choice == "3")
                ok = true;
        }
        if(ok)
            switch(stoi(choice)){
                case 1:
                    choice1(company);
                    break;
                case 2:
                    Utilities::clearScreen();
                    cout << "press enter to continue";
                    company.printGraph();
                    break;
                case 3:
                    exit(0);
                default:
                    break;
            }
    }
}

void choice1(BikeCompany &company){
    string choice;
    bool ok, stop = false;
    while(true) {
        Utilities::clearScreen();
        ok = false;
        cout << "1-\tShortest Path" << endl
             << "2-\tCheapest Path" << endl
             << "3-\tReturn" << endl
             << endl << "Input:" << endl;
        getline(cin, choice);
        if (cin.fail()) {
            Utilities::clearCinBuffer();
        } else {
            Utilities::trimString(choice);
            if(choice == "1" || choice == "2" || choice == "3")
                ok = true;
        }
        if(ok)
            switch(stoi(choice)){
                case 1:
                    shortestPath(company);
                    break;
                case 2:
                    cheapestPath(company);
                    break;
                case 3:
                    stop = true;
                default:
                    break;
            }
        if(stop)
            break;
    }
}

void shortestPath(BikeCompany &company){
    string choice;
    Utilities::clearScreen();
    while(true){
        cout << "What is the node where you are located?" << endl;
        getline(cin, choice);
        if (cin.fail()) {
            Utilities::clearScreen();
            cout << "Node not valid" << endl;
            Utilities::clearCinBuffer();
        } else {
            Utilities::trimString(choice);
            if (Utilities::isNumber(choice)){
                if (stoi(choice) < company.getNodes().size() && stoi(choice) > 0)
                    break;
            }else{
                Utilities::clearScreen();
                cout << "Node not valid" << endl;
            }
        }
    }
    Utilities::clearScreen();
    cout << "press enter to continue" << endl;
    company.getNearestSharingSpot(company.findNodeById(stoi(choice)));
}

void cheapestPath(BikeCompany &company){
    /*
    string choice;
    Utilities::clearScreen();
    while(true){
        cout << "What is the node where you are located?" << endl;
        getline(cin, choice);
        if (cin.fail()) {
            Utilities::clearScreen();
            cout << "Node not valid" << endl;
            Utilities::clearCinBuffer();
        } else {
            Utilities::trimString(choice);
            if (Utilities::isNumber(choice)){
                if (stoi(choice) < company.getNodes().size() && stoi(choice) > 0)
                    break;
            }else{
                Utilities::clearScreen();
                cout << "Node not valid" << endl;
            }
        }
    }
    Utilities::clearScreen();
    cout << "press enter to continue" << endl;
    company.getCheapestSharingSpot(company.findNodeById(stoi(choice)));
     */
}
