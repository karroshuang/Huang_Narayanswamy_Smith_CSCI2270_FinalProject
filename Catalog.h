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

struct item{
	string name;
	string category;
	int price;
	item *next;
    item *previous;

	item(){};
	item(string in_category, string in_name, int in_price)
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
		Catalog();
		~Catalog();
		void readInItems(char *filname);
		void printCatalog();
		void printCatalogByPriceRange(int priceRange);
		void printCatalogByCategory(string category);
		void printCategories();
		void insertItem(string category, string name, int price);
		void deleteItem(string name, string category);
		void findItem(string name, string category);
		void printShoppingCart();
		void addToCart(string category, string name);
		void removeFromCart(string category, string name);
		int checkOut(int budget);
	private:
		int hashSum(string x);
		int tableSize = 10;
		item* itemCatalog[10];
        vector<item*> shoppingCart;
};

#endif // CATALOG_H
