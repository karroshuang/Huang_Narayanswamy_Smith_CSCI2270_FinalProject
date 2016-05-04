#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

struct item{ //item struct, the struct used for every item in the catalog
	string name; //product name
	string category;
	int price;
	item *next; //in hashtable linked list, next and previous items
    item *previous;

	item(){};
	item(string in_category, string in_name, int in_price) // item constructor
	{
		name = in_name;
		category = in_category;
		price = in_price;
		next = NULL;
		previous = NULL;
	}
};


class Catalog
{
	public:
		Catalog(); //construct
		~Catalog(); //destruct
		void readInItems(const char *filname);
		void printCatalog();
		void printCatalogByPriceRange(int priceRange);
		void printCategories();
		void insertItem(string category, string name, int price);
		void deleteItem(string name, string category);
		void findItem(string name, string category);
		void printShoppingCart();
		void addToCart(string category, string name);
		void removeFromCart(string name);
		int checkOut(int budget);
	private:
		int hashSum(string x);
		int tableSize = 10; //set size of hashtable
		item* itemCatalog[10]; //name of hashtable
        vector<item*> shoppingCart; //vector where item about to be bought are stored
};

#endif // CATALOG_H

