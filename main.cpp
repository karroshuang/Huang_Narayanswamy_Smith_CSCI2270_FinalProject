/*Karros Huang, Girish Narayanswamy, Chase Smith
CSCI 2270- Assignment 12
Prof. Rhonda Hoenigman
TA: Amber Womack
SID: 102359450*/

#include "Catalog.h"

using namespace std;


//Tristan: Addition to buyer option. Allows for user to add money while they are still purchasing items in the catalog.
//This allows for the user to edit their spending money without having to exit the program.
int addtocurrentwallet(int wallet){
    int walletaddition;
    string addtowallet;
    cout<< "How much money would you like to add to your budget?"<<endl;

    getline(cin,addtowallet);
    walletaddition = atoi(addtowallet.c_str());

    wallet=wallet+walletaddition;

    return wallet;

}

int main(int argc, char* argv[]) {

    Catalog table = Catalog();//initializing Empty Catalog to be filled

    char *filename; //initializing catalog

    /*Initializing Item Characteristics to read in for functions*/
    string itemName;
    string itemPriceString;
    string itemcategory;
    int itemPrice;
    string stringwallet;
    int wallet;

    /*Menu Navigation Variables*/
    int numchoice1 = 0;
    int numchoice2 = 0;
    string choice;
    bool buyerSeller;

    /*Reading in Text File into the Hash Table*/
    if(argc > 1) {
        filename = argv[1];
    }
    else{
        filename = "items.txt";
    }
    table.readInItems(filename); //initialize catalog with items from items.txt

    /*Displaying Navigation Menu for the User*/
    while(numchoice2 != 3) {  //first choice, buyer or seller?
        cout<<"Are you a buyer or a seller?"<<endl;
        cout<<"1. Buyer"<<endl;
        cout<<"2. Seller"<<endl;
        cout<<"3. Quit"<<endl;

        getline(cin,choice);
        numchoice1 = atoi(choice.c_str());

        if(numchoice1 == 1){ //User has chosen Buyer
            cout<<"Welcome buyer!"<<endl;
            buyerSeller = true; //BUYER
            while(1){ //Inputting Wallet Amount
                cout<<"Please input the amount you are willing to spend (integer value)"<<endl;
                getline(cin,stringwallet);
                wallet = atoi(stringwallet.c_str());
                if(wallet < 0 || wallet > 2147483648){
                    cout<<"Cannot Have Negative $$$ or Value Exceeding 32 Bit Integers"<<endl;
                }
                else{
                    break;
                }
            }
        }
        else if(numchoice1 == 2){//User has chosen Seller
            buyerSeller = false; //SELLER
            cout<<"Welcome seller!"<<endl;
        }
        else{//User has Quit the Program
            cout<<"Good Bye!"<<endl;
            return 0;
        }

        /*BUYER'S MENU*/
        while(numchoice2 != 10 && buyerSeller == true) { //choices 1-7
            cout<<endl;
            cout<<"======Buyer's Main Menu======"<<endl;
            cout<<"Current Wallet: $"<<wallet<<endl;
            cout<<"1. Print catalog"<<endl;
            cout<<"2. Print catalog by budget"<<endl;
            cout<<"3. Print categories"<<endl;
            cout<<"4. Search item"<<endl;
            cout<<"5. Add item to shopping cart"<<endl;
            cout<<"6. Remove item from shopping cart"<<endl;
            cout<<"7. Print shopping cart"<<endl;
            cout<<"8. Check out"<<endl;
            cout<<"9. Want to spend more money? Add more money to your budget here."<<endl;
            cout<<"10. Quit"<<endl;

            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) { //Print Catalog
                table.printCatalog();
            }

            else if (numchoice2 == 2) { //Print Catalog by Budget
                table.printCatalogByPriceRange(wallet);
            }

            else if (numchoice2 == 3) { //Print Categories
                table.printCategories();
            }

            else if(numchoice2 == 4) {//search for item
                cout<<"Search Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Search Item Category."<<endl;
                getline(cin, itemcategory);
                table.findItem(itemName, itemcategory);
            }
            else if (numchoice2 == 5) { //Add Item to shopping cart
                cout<<"Insert Item Name to be Added to Shopping Cart"<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                table.addToCart(itemcategory, itemName);
            }

            else if (numchoice2 == 6) { //Remove Item from Shopping Cart
                cout<<"Insert Item Name to be Removed From Shopping Cart"<<endl;
                getline(cin, itemName);
                table.removeFromCart(itemName);
            }

            else if (numchoice2 == 7) { //Print Shopping Cart
                table.printShoppingCart();
            }

            else if (numchoice2 == 8) {//Checkout
                wallet = table.checkOut(wallet);
            }

            else if(numchoice2 == 9){
                wallet=addtocurrentwallet(wallet);
            }

            else if(numchoice2 == 10){ //quit to Buyer/Seller Menu
                break;
            }

            else{ //not correct input
                cout<<"Not valid input"<<endl;
            }
        }

        /*SELLER'S MENU*/
        while(numchoice2 != 5 && buyerSeller == false) { //choices 1-4
            cout<<endl;
            cout<<"======Seller's Main Menu======"<<endl;
            cout<<"1. Print catalog"<<endl;
            cout<<"2. Add item"<<endl;
            cout<<"3. Remove item"<<endl;
            cout<<"4. Search item"<<endl;
            cout<<"5. Quit"<<endl;

            getline(cin, choice); //getting choice
            numchoice2 = atoi(choice.c_str()); //converting to int from string

            //choices 1-4
            if(numchoice2 == 1) {//Print Entire Catalog
                table.printCatalog();
            }

            else if (numchoice2 == 2) {//Insert an item to the hash table
                cout<<"Insert Item Name."<<endl;
                getline(cin, itemName);
                cout<<"Insert Item Category."<<endl;
                getline(cin, itemcategory);
                cout<<"Insert Item Price."<<endl;
                getline(cin, itemPriceString);
                itemPrice = atoi(itemPriceString.c_str());
                table.insertItem(itemcategory, itemName, itemPrice);
            }

            else if (numchoice2 == 3) {//Deleting an item from the hash table
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

            else if (numchoice2 == 5) { //quit and return to Buyer/Seller Menu
                break;
            }

            else { //not correct input
                cout<<"Not valid input"<<endl;
            }
        }
        numchoice2 = 0; //Resetting the Choices back to 0 so the User can select being a Buyer or Seller Again
        numchoice1 = 0;

    }
    cout<<"Good Bye!"<<endl; //User input "3" in Buyer/Seller Menu and Program has ended
    return 0;

}


