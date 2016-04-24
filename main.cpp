/*Karros Huang, Girish Narayanswamy, Chase Smith
CSCI 2270- Assignment 12
Prof. Rhonda Hoenigman
TA: Amber Womack
SID: 102359450*/

#include "Catalog.h"

using namespace std;

int main(int argc, char* argv[]) {

    Catalog table = Catalog();

    char *filename; //initializing catalog

    /*Item Characteristics*/
    string itemName;
    string itemPriceString;
    string itemcategory;
    int itemPrice;

    string stringwallet;
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
            cout<<"Welcome buyer!"<<endl;
            buyerSeller = true; //BUYER
            while(1){
                cout<<"Please input the amount you are willing to spend (integer value)"<<endl;
                getline(cin,stringwallet);
                wallet = atoi(stringwallet.c_str());
                if(wallet < 0 || wallet > 2147483648){
                    cout<<"Invalid Money Input"<<endl;
                }
                else{
                    break;
                }
            }
        }
        else if(numchoice1 == 2){
            buyerSeller = false; //SELLER
            cout<<"Welcome seller!"<<endl;
        }
        else{
            return 0;
        }

        //BUYER'S MENU
        while(numchoice2 != 8 && buyerSeller == true) { //choices 1-7

            cout<<"======Buyer's Main Menu======"<<endl;
            cout<<"Current Wallet: $"<<wallet<<endl;
            cout<<"1. Print catalog"<<endl;
            cout<<"2. Print catalog by budget"<<endl;
            cout<<"3. Print categories"<<endl;
            cout<<"3. Search item"<<endl;
            cout<<"4. Add item to shopping cart"<<endl;
            cout<<"5. Remove item from shopping cart"<<endl;
            cout<<"6. Print shopping cart"<<endl;
            cout<<"7. Check out"<<endl;
            cout<<"8. Quit"<<endl;

            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) { //Print Catalog
                table.printCatalog();
            }

            else if (numchoice2 == 2) { //Print Catalog by Budget
                table.printCatalogByPriceRange(wallet);
            }

            else if (numchoice2 == 3) { //Print Catagories
                table.printCategories();
            }

            else if (numchoice2 == 4) { //Add Item to shopping cart
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                table.addToCart(itemcategory, itemName);
            }

            else if (numchoice2 == 5) { //Remove Item from Shopping Cart
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                table.removeFromCart(itemcategory, itemName);
            }

            else if (numchoice2 == 6) { //Print Shopping Cart
                table.printShoppingCart();
            }

            else if (numchoice2 == 7) { //quit
                wallet = table.checkOut(wallet);
            }

            else if(numchoice2 == 8){
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
            cout<<"5. Quit"<<endl;

            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) {
                table.printCatalog();
            }

            else if (numchoice2 == 2) {
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                cout<<"Insert Item Price."<<endl;
                cin>>itemPrice;
                table.insertItem(itemcategory, itemName, itemPrice);
            }

            else if (numchoice2 == 3) {
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                table.deleteItem(itemName, itemcategory);

            }

            else if (numchoice2 == 4) { //print table contents
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                table.findItem(itemName, itemcategory);

            }

            else if (numchoice2 == 5) { //quit
                break;
            }

            else { //not correct input
                cout<<"Not valid input"<<endl;
            }
        }
        numchoice2 = 0;
        numchoice1 = 0;

    }

    return 0;

}

