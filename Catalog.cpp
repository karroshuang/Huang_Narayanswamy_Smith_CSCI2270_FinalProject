#include "catalog.h"

using namespace std;

Catalog::Catalog()
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

void Catalog::printCatalog()
{
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
            temp = itemCatalog[x];
            cout<<endl;
            cout<<"Category"<<": "<<temp->category<<endl;
            while(temp != NULL)
            {
                cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<endl;
                temp = temp->next;
            }
        }
    }
}

void Catalog::printCatalogByPriceRange(int priceRange)
{
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
            temp = itemCatalog[x];
            cout<<endl;
            cout<<"Category"<<": "<<temp->category<<endl;
            while(temp != NULL)
            {
                if(temp->price < priceRange)
                {
                    cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<endl;
                    temp = temp->next;
                }
            }
        }
    }
    return;
}

void Catalog::printCatalogByCategory(string category)
{
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
            temp = itemCatalog[x];
            if(temp->category == category)
            {
                cout<<endl;
                cout<<"Category"<<": "<<temp->category<<endl;
                while(temp != NULL)
                {
                        cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<endl;
                        temp =temp->next;
                }
            }
        }
    }

}

void Catalog::insertItem(string category, string name, int price)
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
        item *tmp = itemCatalog[index];
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
    cout << "item not found" << endl;
    return;
}

int Catalog::hashSum(string x)
{
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
    else{
        return -1;
    }

}

void Catalog::printCategories()
{
    for(int x=0; x < tableSize; x++)
    {
        cout<<itemCatalog[x]->category<<endl;
    }
}

void Catalog::readInItems(char* filename)
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

            if(tmp->name == name){
                cout <<tmp->name<<" added to shopping cart"<<endl;
                shoppingCart.push_back(tmp);
                deleteItem(name,category);
                return;
            }

            else{
                tmp = tmp->next;
            }
        }
    }

    cout << "Item not found" << endl;
}

void Catalog::removeFromCart(string category, string name)
{
    for(int i = 0; i < shoppingCart.size(); i++){

        if(shoppingCart[i]->name == name){
            insertItem(shoppingCart[i]->category,shoppingCart[i]->name, shoppingCart[i]->price);
            shoppingCart.erase(shoppingCart.begin()+i);
            return;
        }

    }

    cout << "Item not found in shopping cart" << endl;
}

int Catalog::checkOut(int budget)
{
    for(int i = 0; i < shoppingCart.size(); i++){
        budget = budget - shoppingCart[i]->price;
        if(budget < 0){
            budget = budget + shoppingCart[i]->price;
            cout<<"insufficient funds to purchase "<<shoppingCart[i]->name<<endl;
            cout<<"you are being sent back to the buyer's menu"<<endl;
            return budget;
        }

        else{
            cout<<"Purchasing "<<shoppingCart[i]->name<<" for: "<<shoppingCart[i]->price<<endl;
            shoppingCart.erase(shoppingCart.begin()+i);
            delete shoppingCart[i];
        }

    }
    return budget;
}

void Catalog::printShoppingCart()
{
    for(int x = 0; x < shoppingCart.size();x++)
    {
        cout<<"Item: "<<shoppingCart[x]->name<<", Price: "<<shoppingCart[x]->price<<endl;

    }
}
