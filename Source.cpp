#include <iostream>
#include <string>
using namespace std;


//  ****  Parent Class  ****  //

class Item {
private:
	int itemNumber;
	double price;
public:
	Item() {  // ** Default Constructor ** //
		itemNumber = 0;
		price = 0.0;
	}
	Item(int, double);  // ** Constructor Declaration ** //

	int getItem() { return itemNumber; };   // **Access Methods ** //
	void setItem(int n) { itemNumber = n; };
	double getPrice() { return price; };
	void setPrice(double p) { price = p; };

	void display();

	~Item() {
	}; // ** Destructor ** //
};

Item::Item(int in, double pr) {
	itemNumber = in; price = pr;
}
void Item::display() {
	cout << "\nItem number: " << itemNumber << "\nPrice: " << price << endl;
}


// **** Child Class **** //

class Pizza : public Item {
private:
	char size;
	string topping;
public:
	Pizza() {    // ** Default Constructor ** //
		size = 'M';
		topping = "NO";
	}
	Pizza(int, double, char, string);  // ** Constructor Declaration ** //

	char getSize() { return size; }; // **Access Methods ** //
	void setSize(char s) { size = s; };
	string getTopping() { return topping; };
	void setTopping(string t) { topping = t; };

	void display();

	~Pizza() {
	}; // ** Destructor ** //
};

Pizza::Pizza(int in, double pr, char si, string to) : Item(in, pr) {
	size = si; topping = to;
}

void Pizza::display() {
	cout << "\n  Pizza: "
		<< "\nItem number: " << getItem()
		<< "\nPrice: " << getPrice() << " BGN"
		<< "\nSize: " << size
		<< "\nTopping Sauce: " << topping
		<< endl;
}


//  ****  Main Function  ****  //

int main() {
	Pizza Orders[50];
	int PizzaItem;
	char PizzaSize;
	string ToppingSauce;
	double PizzaPrice = 0.0;
	int N, i;
	double price, VAT, total;

	// ** Input Number of Pizzas' ** //

	N = 0;

	do {
		cout << "\nEnter the amount of wanted pizzas (1-50): ";
		cin >> N;

		if (N < 1 || N > 50) {
			cout << "\nInvalid amount! Please try again." << endl;
		}

	} while (N < 1 || N > 50);


	// ** Input Information about the Pizzas ** //

	for (i = 0; i < N; i++) {

		// ** Enter item number ** //
		do {
			cout << "\nThe item number of the pizza: ";
			cin >> PizzaItem;

			if (PizzaItem < 1) {
				cout << "\nInvalid number! Please try again." << endl;
			}

		} while (PizzaItem < 1);


		// ** Enter price ** //
		do {
			cout << "Enter price: ";
			cin >> PizzaPrice;

			if (PizzaPrice <= 0) {
				cout << "\nInvalid price! Please try again." << endl;
			}

		} while (PizzaPrice <= 0);


		// ** Enter size M/L ** //
		do {
			cout << "Size of the pizza(M/L): ";
			cin >> PizzaSize;
			PizzaSize = toupper(PizzaSize);

			if (PizzaSize != 'M' && PizzaSize != 'L') {
				cout << "\nInvalid size! Please try again." << endl;
			}

		} while (PizzaSize != 'M' && PizzaSize != 'L');


		// ** Enter topping YES/NO ** //
		do {
			cout << "Topping Sauce? (YES/NO): ";
			cin >> ToppingSauce;

			for (int j = 0; j < ToppingSauce.length(); j++) {
				ToppingSauce[j] = toupper(ToppingSauce[j]);
			}

			if (ToppingSauce != "YES" && ToppingSauce != "NO") {
				cout << "\nInvalid input! Please try again." << endl;
			}

		} while (ToppingSauce != "YES" && ToppingSauce != "NO");

		Orders[i] = Pizza(PizzaItem, PizzaPrice, PizzaSize, ToppingSauce); // ** Stores data into an array ** //
	}


	//  ** Print Info about all Pizzas **  //

	cout << "\n    All Ordered Pizzas :     " << endl;
	for (i = 0; i < N; i++) {
		Orders[i].display();
	}


	// ** Print Info for Large Pizzas ** //

	int Largecount = 0;

	for (i = 0; i < N; i++) {
		if (Orders[i].getSize() == 'L') {
			Largecount++;
		}
	}

	if (Largecount > 0) {
		cout << "\n    Ordered Pizzas with Size Large: " << endl;

		for (i = 0; i < N; i++) {
			if (Orders[i].getSize() == 'L') {
				Orders[i].display();
			}
		}
	}
	else {
		cout << "\n No Pizzas with Size Large. " << endl;
	}


	//  ** Calculate Price ** //

	price = 0.0;
	VAT = 1.20;

	for (i = 0; i < N; i++) {
		price += Orders[i].getPrice();

		if (Orders[i].getTopping() == "YES") {
			price += 2.50;
		}
	}

	total = price * VAT;

	cout << "\n    Total price including VAT: " << total << " BGN" << endl;

	return 0;
}
