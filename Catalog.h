#ifndef CATALOG_H
#define CATALOG_H

using namespace std;

struct item{
	std::string name;
	std::string category
	int price;
	item *next;
    item *previous;

	item(){};
	item(std::string in_category, std::string in_name, int in_price,)
	{
		name = in_title;
		category = in_category;
		price = in_year;
		next = NULL;
		previous = NULL;
	}
};


class Catalog
{
	public:
		Catalog();
		~Catalog();
		void printCatalog();
		void printCatalogByPriceRange(int priceRange);
		void printCategories();
		void insertItem(std::string name, int year);
		void deleteItem(std::string name);
		void findItem(std::string name);
		void printShoppingCart();
		void checkOut();

	private:
		int hashSum(std::string x, int s);
		int tableSize = 10;
		item* itemCatalog[10];

};

#endif // CATALOG_H
