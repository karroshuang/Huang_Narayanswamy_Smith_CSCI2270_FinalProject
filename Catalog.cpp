#include "Catalog.h"
#include <iostream>
#include <vector>

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

}
