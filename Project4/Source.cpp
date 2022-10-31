#include <iostream>
using namespace std;

class Product {

	int id; char* name; char* description; double price; short discount;
public:
	Product() : id(0), name(nullptr), description(nullptr), price(0), discount(0) {
	}

	Product(int id) : Product() {
		this->id = id;
	}

	Product(int id, const char* name) : Product(id) {
		SetName(name);
	}

	Product(int id, const char* name, const char* description) : Product(id, name) {
		SetDescription(description);
	}

	Product(int id, const char* name, const char* description, double price) : Product(id, name, description) {
		this->price = price;
	}

	Product(int id, const char* name, const char* description, double price, short discount) : Product(id, name, description, price) {
		this->discount = discount;
	}
	void SetName(const char* name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetDescription(const char* description) {
		delete this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	double GetPriceWithDiscount() {
		double tempprice;
		tempprice = price - ((price) / discount);
		return tempprice;
	}

	int GetId() {
		return id;
	}
	void ShowProduct() {
		cout << "Product Id: " << id << endl;
		if (name != nullptr)
		{
			cout << "Product Name: " << name << endl;
		}
		else
			cout << "Product Name: " << "No name" << endl;
		if (description != nullptr)
		{
			cout << "Product Description: " << description << endl;
		}
		else
			cout << "Product Description: " << "No description" << endl;
		cout << "Product Price: " << price << " $" << endl;
		cout << "Product Discount: " << discount << " %" << endl;
	}
};
class Stock {
	char* name;
	int ProductCount = 3;
	Product* stock = new Product[ProductCount]{
		{1, "apple" , "Fruit", 23.5, 10},
		{2, "banana" , "Fruit", 15, 5},
		{3, "grape" , "Fruit", 40, 10}
	};
public:
	Stock() {
		for (int i = 0; i < ProductCount; i++)
		{
			stock[i] = Product();
		}
	}
	void Print() {
		for (int i = 0; i < ProductCount; i++)
		{
			stock[i].ShowProduct();
		}
	}
	Product GetProduct(int id) {
		for (int i = 0; i < ProductCount; i++) {
			if (stock[i].GetId() == id) {
				return stock[i];
			}
			else
				cout << "There is no product with this id";
		}
	}
};

int main() {
	Stock fruits;
	fruits.Print();
}