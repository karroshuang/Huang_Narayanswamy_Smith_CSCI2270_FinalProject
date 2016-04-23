/*Karros Huang, Girish Narayanswamy, Chase Smith
CSCI 2270- Assignment 12
Prof. Rhonda Hoenigman
TA: Amber Womack
SID: 102359450*/

#include "Catalog.h"

using namespace std;


int main()
{
    Catalog table = Catalog();

    string itemName;
    string itemPriceString;
    int itemPrice;

    int numchoice = 0;
    string choice;

    bool buyerSeller;

    cout<<"Are you a buyer or a seller?"<<endl;
    cout<<"1. Buyer"<<endl;
    cout<<"2. Seller"<<endl;

    getline(cin,choice);
    numchoice = atoi(choice.c_str());

    if(numchoice == 1){
        buyerSeller = true; //BUYER
        cout<<"Welcome buyer!"<<endl;
        cout<<"Please input the amount you are willing to spend (integer value)"<<endl;
    }
    else{
        buyerSeller = false; //SELLER
        cout<<"Welcome seller!"<<endl;
    }

    //BUYER'S MENU
    while(numchoice != 5 && buyerSeller == true) { //choices 1-7

        cout<<"======Buyer's Main Menu======"<<endl;
        cout<<"1. Print catalog"<<endl;
        cout<<"2. Print catalog by budget"<<endl;
        cout<<"3. Print categories
        cout<<"3. Search item"<<endl;
        cout<<"4. Add item to shopping cart"<<endl;
        cout<<"5. Remove item from shopping cart"<<endl;
        cout<<"6. Print shopping cart"<<endl;
        cout<<"6. Check out"<<endl;
        cout<<"7. Quit"<<endl;


        getline(cin, choice); //getting choice
        numchoice = atoi(choice.c_str()); //converting to int from string

        //choices 1-4
        if(numchoice == 1) {


        }

        else if (numchoice == 2) {

        }

        else if (numchoice == 3) {


        }

        else if (numchoice == 4) { //print table contents


        }

        else if (numchoice == 7) { //quit
            cout<<"Goodbye!"<<endl;
            return 0;
        }

        else { //not correct input
            cout<<"Not valid input"<<endl;
        }
    }

    //SELLER'S MENU
    while(numchoice != 5 && buyerSeller == false) { //choices 1-4

        cout<<"======Seller's Main Menu======"<<endl;
        cout<<"1. Print catalog"<<endl;
        cout<<"2. Add item"<<endl;
        cout<<"3. Remove item"<<endl;
        cout<<"4. Search item"<<endl;
        cout<<"5. Quit"<<endl;


        getline(cin, choice); //getting choice
        numchoice = atoi(choice.c_str()); //converting to int from string

        //choices 1-4
        if(numchoice == 1) {


        }

        else if (numchoice == 2) {

        }

        else if (numchoice == 3) {


        }

        else if (numchoice == 4) { //print table contents


        }

        else if (numchoice == 5) { //quit
            cout<<"Goodbye!"<<endl;
            return 0;
        }

        else { //not correct input
            cout<<"Not valid input"<<endl;
        }
    }

    return 0;

}
