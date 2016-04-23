/*Karros Huang, Girish Narayanswamy, Chase Smith
CSCI 2270- Assignment 12
Prof. Rhonda Hoenigman
TA: Amber Womack
SID: 102359450*/

#include "Catalog.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    vector<item> shoppingCart; //shopping cart
    Catalog table = Catalog(); //catalog declared

    char *filename; //initializing catalog

    string itemName; //item characteristics
    string itemPriceString;
    int itemPrice;

    string walletString;
    int wallet;

    int numchoice1 = 0; //menu navigation variables
    int numchoice2 = 0;
    string choice;
    bool buyerSeller;


    if(argc > 1) {
        filename = argv[1];
    }
    else{
        filename = "items.txt";
    }

    table.readInItems(filename); //initialize catalog with items from items.txt

    while(numchoice2 != 3) {

        cout<<"Are you a buyer or a seller?"<<endl;
        cout<<"1. Buyer"<<endl;
        cout<<"2. Seller"<<endl;
        cout<<"3. Quit"<<endl;

        getline(cin,choice);
        numchoice1 = atoi(choice.c_str());

        if(numchoice1 == 1){
            buyerSeller = true; //BUYER
            cout<<"Welcome buyer!"<<endl;
            cout<<"Please input the amount you are willing to spend (integer value)"<<endl;
            getline(cin,walletString);
            wallet = atoi(walletString.c_str());
        }
        else if(numchoice1 == 2){
            buyerSeller = false; //SELLER
            cout<<"Welcome seller!"<<endl;
        }
        else{
            return 0;
        }

        //BUYER'S MENU
        while(numchoice2 != 5 && buyerSeller == true) { //choices 1-7

            cout<<"======Buyer's Main Menu======"<<endl;
            cout<<"Current Wallet: $"<<wallet<<endl;
            cout<<"1. Print catalog"<<endl;
            cout<<"2. Print catalog by budget"<<endl;
            cout<<"3. Print categories"<<endl;
            cout<<"3. Search item"<<endl;
            cout<<"4. Add item to shopping cart"<<endl;
            cout<<"5. Remove item from shopping cart"<<endl;
            cout<<"6. Print shopping cart"<<endl;
            cout<<"6. Check out"<<endl;
            cout<<"7. Quit"<<endl;


            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) {


            }

            else if (numchoice2 == 2) {

            }

            else if (numchoice2 == 3) {


            }

            else if (numchoice2 == 4) { //print table contents


            }

            else if (numchoice2 == 5) { //print table contents


            }

            else if (numchoice2 == 6) { //print table contents


            }

            else if (numchoice2 == 7) { //quit
                cout<<"Goodbye!"<<endl;
                break;
            }

            else { //not correct input
                cout<<"Not valid input"<<endl;
            }
        }

        //SELLER'S MENU
        while(numchoice2 != 6 && buyerSeller == false) { //choices 1-4

            cout<<"======Seller's Main Menu======"<<endl;
            cout<<"1. Print catalog"<<endl;
            cout<<"2. Add item"<<endl;
            cout<<"3. Remove item"<<endl;
            cout<<"4. Search item"<<endl;
            cout<<"5. Add additional items from text file"<<endl;
            cout<<"6. Quit"<<endl;


            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) {


            }

            else if (numchoice2 == 2) {

            }

            else if (numchoice2 == 3) {


            }

            else if (numchoice2 == 4) { //print table contents


            }

            else if (numchoice2 == 5) { //print table contents


            }

            else if (numchoice2 == 6) { //quit
                cout<<"Goodbye!"<<endl;
                break;
            }

            else { //not correct input
                cout<<"Not valid input"<<endl;
            }
        }

    }

    return 0;

}

