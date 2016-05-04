#include "Catalog.h"

using namespace std;

Catalog::Catalog() //initialize array to NULL
{
    for(int i = 0; i < 10; i++){
        itemCatalog[i] = NULL;
    }
    //ctor
}

Catalog::~Catalog()
{
    //dtor
}

void Catalog::printCatalog() //prints the entire catalog, first by category and then each item in the category
{
	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 }; //changes case number to blue
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 }; //changes text back to white
    int counter=0; //makes sure there are more than 0 items in catalog
    item *temp = new item;
    for(int x = 0; x < tableSize; x++){ //checks to see if the array is empty
        temp = itemCatalog[x];
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
    }
    if(counter == 0){
        cout<<"Catalog Empty"<<endl; //if counter is still 0 catalog is empty
    }
    else{
        for(int x = 0; x < tableSize; x++){ //if not empty iterates through hash table and prints ALL items
            temp = itemCatalog[x];
            if(temp != NULL){
                cout<<endl;
                cout<<blue<<"Category"<<": "<<temp->category<<normal<<endl; //prints out the category name only once
                while(temp != NULL){
                    cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<endl;
                    temp = temp->next;
                }
            }
        }
    }
}

void Catalog::printCatalogByPriceRange(int priceRange) //prints the same as the printFunction but by price
{
	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 }; //changes case number to blue
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 }; //changes text back to white
    int counter=0;
    item *temp = new item;
    for(int x = 0; x < tableSize; x++)
    {
        temp = itemCatalog[x];
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
    }
    if(counter == 0)
    {
        cout<<"Catalog Empty"<<endl;
    }
    else
    {  
        for(int x = 0; x < tableSize; x++)
        {
            bool cantAfford = true;
            temp = itemCatalog[x];
            if(temp != NULL){
                cout<<endl;
                cout<<blue<<"Category"<<": "<<temp->category<<normal<<endl;
                while(temp != NULL)
                {
                    if(temp->price < priceRange) //prints if under budget
                    {
                        cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<endl;
                        cantAfford = false;
                    }
                    temp = temp->next;
                }
                if(cantAfford) {
                    cout << "Can't afford anything in this category" << endl;
                }
            }
        }
    }
    return;
}

void Catalog::insertItem(string category, string name, int price)  //used when sellers add items to the array or items are removed from cart
{
    item* Item = new item(category, name, price); //Create instance of item
    int index = hashSum(Item->category); //getting array index
    if(index == -1){ //User put in an invalid category
        cout<<"Invalid Category"<<endl;
        return;
    }

    /*Adding In item into hash table*/
    if(itemCatalog[index] == NULL){
        itemCatalog[index] = Item;
        itemCatalog[index]->previous = NULL;
        itemCatalog[index]->next = NULL;
    }
    else{
        /*Iterate temp to the end of the chain*/
        item* tmp = itemCatalog[index];
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        /*Re-assign pointers to insert movie*/
        tmp->next = Item;
        Item->previous = tmp;
        Item->next = NULL;
    }
}

void Catalog::deleteItem(string name, string category)
{
    bool found = false; //item hasn't been found yet
    int index = hashSum(category); //Finding hash table index
    if(index == -1){ //User put in an invalid category
        cout<<"Invalid Category"<<endl;
        return;
    }
    /*finding item*/
    if(itemCatalog[index] != NULL){
        item* tmp = itemCatalog[index];
        while(tmp != NULL){
            if(tmp->name == name){ //item has been found
                /*Deleting Item*/
                bool found = true;
                if(tmp->previous == NULL && tmp->next == NULL){ //if movie is the first and only thing in the array
                    itemCatalog[index] = NULL;
                    return;
                }
                else if(tmp->previous == NULL && tmp->next != NULL){ //if first thing in chain
                    itemCatalog[index] = tmp->next;
                    itemCatalog[index]->previous = NULL;
                    //delete tmp;
                    return;
                }
                else if(tmp->previous != NULL && tmp->next == NULL){ //last element in the chain
                    tmp->previous->next = NULL;
                    //delete tmp;
                    return;
                }
                else{ //element in middle of chain
                    tmp -> previous -> next = tmp -> next;
                    tmp -> next -> previous = tmp -> previous;
                    //delete tmp;
                    return;
                }
            }
            tmp = tmp->next;
        }
        if(found == false){ //item hasnt been found
            cout<<"Item not found."<<endl;
        }
    }
}

void Catalog::findItem(string name, string category)
{
    int index = hashSum(category);//Acquiring index
    if(index == -1){ //User put in an invalid category
        cout<<"Invalid Category"<<endl;
        return;
    }
    if(itemCatalog[index] != NULL){
        item *tmp = itemCatalog[index]; //makes walker to move through table to find item
        while(tmp != NULL){
            if(tmp->name == name){
                cout << "Item: "<< tmp->name << ", Category: "<< tmp->category << ", Price: "<<tmp->price<<endl;
                return;
            }
            else{
            tmp = tmp->next;
            }
        }
    }
    cout << "item not found" << endl; //if does not return earlier means item was not found in catalog
    return;
}

int Catalog::hashSum(string x) //basic hashSum function that separates things by categories, each array index is a category
{//all of the different possible categories
    if(x == "Sports"){
        return 0;
    }
    else if(x == "Men's Clothing"){
        return 1;
    }
    else if(x == "Women's Clothing"){
        return 2;
    }
    else if(x == "Electronics"){
        return 3;
    }
    else if(x == "Food"){
        return 4;
    }
    else if(x == "Movies"){
        return 5;
    }
    else if(x == "Games"){
        return 6;
    }
    else if(x == "Books"){
        return 7;
    }
    else if(x == "Arts and Crafts"){
        return 8;
    }
    else if(x == "Health and Beauty"){
        return 9;
    }
    else{ //else invalid input
        return -1;
    }

}

void Catalog::printCategories() //prints the categories
{
	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 }; //changes case number to blue
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 }; //changes text back to white
    bool emptycatalog = true;
    cout<<" "<<endl;
    cout<<"Categories:"<<endl;
    for(int x=0; x < tableSize; x++) //iterates through the hashtable
    {
        if(itemCatalog[x] != NULL){
            emptycatalog = false;
            cout<<blue<<itemCatalog[x]->category<<normal<<endl;
        }
    }
    if(emptycatalog){
        cout<<"Catalog is Empty"<<endl; //catalog empty
    }
}

void Catalog::readInItems(const char* filename) //initial function that puts things in the array so the buyer or seller has something to wprk with
{
    string data; //used for string stream
    ifstream itemList; //text file stream

    itemList.open(filename);


    //CHECKS IF FILE OPENED CORRECTLY
    if(itemList.bad()) {
        itemList.close();
        cout<<"File could not be opened"<<endl;
        return;
    }

    while(getline(itemList, data)) {

        string in_category;
        string in_name;
        int in_price;
        int in_quantity;

        stringstream ss(data); //create a string stream variable from the string data
        string temp_data;

        getline(ss,temp_data,','); //getting category
        in_category = temp_data;


        getline(ss,temp_data,','); //getting name
        in_name = temp_data;


        getline(ss,temp_data,','); //getting price
        in_price = atoi(temp_data.c_str()); //converting price to int

        insertItem(in_category,in_name,in_price);
    }
    itemList.close();
}

void Catalog::addToCart(string category, string name)
{
    int index = hashSum(category);//Acquiring index

    if(index == -1){ //User put in an invalid category
        cout<<"Invalid Category"<<endl;
        return;
    }

    if(itemCatalog[index] != NULL){

        item *tmp = itemCatalog[index];

        while(tmp != NULL){

            if(tmp->name == name){ //adds the found item to cart
                cout <<tmp->name<<" added to shopping cart"<<endl;
                shoppingCart.push_back(tmp); //added to cart
                deleteItem(name,category); //removed from table
                return;
            }

            else{
                tmp = tmp->next;
            }
        }
    }

    cout << "Item not found" << endl; //not found
}

void Catalog::removeFromCart(string name) //removing an item from the shopping cart
{
    for(int i = 0; i < shoppingCart.size(); i++){

        if(shoppingCart[i]->name == name){
            insertItem(shoppingCart[i]->category,shoppingCart[i]->name, shoppingCart[i]->price); //added back to catalog
            shoppingCart.erase(shoppingCart.begin()+i); //removed from vector
            return;
        }

    }

    cout << "Item not found in shopping cart" << endl;
}

int Catalog::checkOut(int budget) //checks out items, item by item. If there isn't enough money the buyer is sent back with their remaining funds
{
    if(shoppingCart.empty()){
        cout<<"Shopping Cart is Empty"<<endl;
    }
    else{
        while(!shoppingCart.empty()){ //keeps moveing through the shopping cart and continuously grabs the first (front) of the vector
            budget = budget - shoppingCart[0]->price;
            if(budget < 0){ //if over-goes budget
                budget = budget + shoppingCart[0]->price;
                cout<<"insufficient funds to purchase "<<shoppingCart[0]->name<<endl;
                cout<<"this item is now being removed from your cart and will be placed back on the shelf"<<endl;
                insertItem(shoppingCart[0]->category,shoppingCart[0]->name, shoppingCart[0]->price);
                shoppingCart.erase(shoppingCart.begin());
            }
            else{
                cout<<"Purchasing "<<shoppingCart[0]->name<<" for: "<<shoppingCart[0]->price<<endl;
                shoppingCart.erase(shoppingCart.begin()); //else removes from shopping cart and purchased
            }

        }
    }
    return budget;
}

void Catalog::printShoppingCart() //iterates through the vector that makes up the shopping cart
{
    if(shoppingCart.empty()){
        cout<<"Shopping Cart is Empty"<<endl;
    }
    else{
        for(int x = 0; x < shoppingCart.size();x++) //goes through cart and print current inventory
        {
            cout<<"Item: "<<shoppingCart[x]->name<<", Price: "<<shoppingCart[x]->price<<endl;

        }
    }
}
