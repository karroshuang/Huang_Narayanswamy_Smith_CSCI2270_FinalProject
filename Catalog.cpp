#include "Catalog.h"
#include <iostream>
#include <vector>

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
        while(temp->next != NULL)
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
            cout<<"Category"<<": "<<temp->category<<endl;
            while(temp->next != NULL)
            {
                cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<", "<<"Quantity:"<<temp->quantity<<endl;
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
        while(temp->next != NULL)
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
            cout<<"Category"<<": "<<temp->category<<endl;
            while(temp->next != NULL)
            {
                if(temp->price < priceRange)
                {
                    cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<", "<<"Quantity:"<<temp->quantity<<endl;
                }
            }
        }
    }
}

void Catalog::printCatalogByCategory(string category)
{
    int counter=0;
    item *temp = new item;
    for(int x = 0; x < tableSize; x++)
    {
        temp = itemCatalog[x];
        while(temp->next != NULL)
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
                cout<<"Category"<<": "<<temp->category<<endl;
                while(temp->next != NULL)
                {
                        cout<<"Item:"<<temp->name<<", "<<"Price:"<<temp->price<<", "<<"Quantity:"<<temp->quantity<<endl;
                }
            }
        }
    }
}

void printCategories()
{
    for(int x=0; x < tableSize; x++)
    {
        cout<<itemCatelog[x]->category<<end;
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


        getline(ss,temp_data,','); //getting quantity
        in_quantity = atoi(temp_data.c_str()); //converting quant to int

        //insertItem(in_category,in_name,in_price,in_quantity);
    }
}



