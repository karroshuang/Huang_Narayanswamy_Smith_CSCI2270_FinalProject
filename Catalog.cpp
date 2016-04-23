#include "Catalog.h"

using namespace std;

Catalog::Catalog()
{
    //ctor
}

Catalog::~Catalog()
{
    //dtor
}

void Catalog::printCatalog()
{
    /*item *temp = itemCatalog[x];
    int counter=0;
    for(int x = 0; x < tableSize; x++)
    {
        while(temp.next != NULL)
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
            cout<<"Category"<<": "<<temp.category<<endl;
            while(temp->next != NULL)
            {
                cout<<"Item:"<<temp.name<<", "<<"Price:"<<temp.price<<endl;
            }
        }
    }
    */
}

void Catalog::insertItem(string category, string name, int quantity, int price)
{
    item* Item = new item(category, name, price, quantity); //Create instance of item
    if(Item->quantity < 1){ //User put in an incorrect quantity
        cout<<"Quantity must be greater than or equal to 1"<<endl;
        return;
    }
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
                    if(tmp->quantity > 1){ //if quantity is greater than 1, then reduce item quantity  by 1
                        bool found = true;
                        tmp->quantity--;
                        return;
                    }
                    else{ //if item quantity is 1, then remove the item from hash table
                        bool found = true;
                        if(tmp->previous == NULL && tmp->next == NULL){ //if movie is the first and only thing in the array
                            itemCatalog[index] = NULL;
                            return;
                        }
                        else if(tmp->previous == NULL && tmp->next != NULL){ //if first thing in chain
                            itemCatalog[index] = tmp->next;
                            itemCatalog[index]->previous = NULL;
                            delete tmp;
                            return;
                        }
                        else if(tmp->previous != NULL && tmp->next == NULL){ //last element in the chain
                            tmp->previous->next = NULL;
                            delete tmp;
                            return;
                        }
                        else{ //element in middle of chain
                            tmp -> previous -> next = tmp -> next;
                            tmp -> next -> previous = tmp -> previous;
                            delete tmp;
                            return;
                        }
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
                cout << tmp->category << ":" << tmp->name << ":" << tmp->price << ":" << tmp->quantity<<endl;
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
