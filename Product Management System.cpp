#include <iostream>
using namespace std;

// Variables to store data temporary...
int ID;
string Name;
int Price;
int Quantity;
string SupplierName;

int active_Products = 0; // Stores --> To check the availability of the product...
int product_counts = 1;	 // Stores --> The active products counts in the inventory
int position = 0;		 // Stores --> The position in the array

// Structure --> To manage data in appropriate way
struct Shop
{
	int product_count;
	int product_ID;
	string product_Name;
	int price_inPKR;
	int product_Quantity;
	string product_SupplierName;
};

Shop shop[5]; // Global shop array to store data...

//		--:( FUNCTIONS TO MANAGE THE DATA ):--		//

// Screen Waiting function
void waitScreen()
{
	sleep(4);
	system("cls");
}

// Function to display details at the beginning
void details()
{
	cout << "\n\n\tHello Sir! Welcome to the Product Management System! Here you can add a product, remove the product from the inventory. You can also see the all products available in the inventory.";
	sleep(2);
	cout << "\n\nNOTE: This program will holds your data during the program running time, because it's under construction and after completion, it will be able to store your data in the backend storage. So wait for the complete version...\n";
	sleep(4);
	cout << "\nPress enter to continue...";
	cin.get(); // Will wait for the enter button.
	system("cls");
}

// Function to take the product data from the user...
void productData()
{
	cout << "\nEnter the product ID: ";
	cin >> ID;
	cout << "Enter the product Name: ";
	cin >> Name;
	cout << "Enter the product price in PKR: ";
	cin >> Price;
	cout << "Enter the product Quantity: ";
	cin >> Quantity;
	cout << "Enter the product Supplier Name: ";
	cin >> SupplierName;
}

// Function for adding product to the inventory
void addProduct()
{
	for (int i = position; i <= (i + 1);)
	{
		shop[i].product_count = product_counts;
		shop[i].product_ID = ID;
		shop[i].product_Name = Name;
		shop[i].price_inPKR = Price;
		shop[i].product_Quantity = Quantity;
		shop[i].product_SupplierName = SupplierName;
		break;
	}
	cout << "Your data has been added successfully.\n"
		 << endl;
	active_Products++;
	product_counts++;
	position++;
}

// Function to diplay the selected product to delete
void display_RemovingProduct(int ID)
{
	cout << " Here's your product:" << endl;
	cout << "*************************************************" << endl;
	for (int i = 0; i <= (active_Products - 1); i++)
	{
		if (ID == shop[i].product_ID)
		{
			cout << "\n\t(Product No: " << shop[i].product_count << ")" << endl;
			cout << "Product ID: " << shop[i].product_ID << endl
				 << "Product Name: " << shop[i].product_Name << endl
				 << "Product Price: " << shop[i].price_inPKR << endl
				 << "Product Quantity: " << shop[i].product_Quantity << endl
				 << "Product Supplier Name: " << shop[i].product_SupplierName << endl
				 << endl;
			cout << "*************************************************" << endl;
		}
	}
}

// Function to delete the product from the inventory
int deleteProduct()
{
	int removingProduct_ID;
	cout << "\nEnter the Product ID: ";
	cin >> removingProduct_ID;
	sleep(2);

	for (int i = 0; i <= active_Products; i++)
	{
		if (removingProduct_ID == shop[i].product_ID)
		{
			cout << "\nProduct Found...";
			display_RemovingProduct(removingProduct_ID);

			cout << "Are you sure you want to remove the product? (yes/no) ";
			string choice;
			cin >> choice;

			if (choice == "Yes" || choice == "yes")
			{
				for (int j = i; j < (i + 1);)
				{
					// shop[i].product_count = product_counts;
					shop[j].product_ID = 0;
					shop[j].product_Name = "---";
					shop[j].price_inPKR = 0;
					shop[j].product_Quantity = 0;
					shop[j].product_SupplierName = "---";

					cout << "\nThe Product no " << j + 1 << " with the Product Code " << removingProduct_ID << " has been removed succesfully!" << endl;
					cout << "NOTE: Now, The container of Product no " << j + 1 << " is empty..." << endl;
					return 0;
				}
			}
			else
				cout << "Okay Sir!" << endl;
			return 0;
		}
	}

	cout << "No product found with the Product ID " << removingProduct_ID << "." << endl;
	return 0;
}

// Function for diplaying all the products in the inventory
void displayProduct()
{
	if (active_Products == 0)
		cout << "\nThere's no product in your inventory...\n";
	else
	{
		cout << "\n\n\tHere's your products data:" << endl;
		cout << "===========================================" << endl;
		for (int i = 0; i <= (active_Products - 1); i++)
		{
			cout << "\n\t(Product No: " << shop[i].product_count << ")" << endl;

			cout << "Product ID: " << shop[i].product_ID << endl
				 << "Product Name: " << shop[i].product_Name << endl
				 << "Product Price: " << shop[i].price_inPKR << endl
				 << "Product Quantity: " << shop[i].product_Quantity << endl
				 << "Product Supplier Name: " << shop[i].product_SupplierName << endl
				 << endl;
		}
		cout << "===========================================" << endl
			 << endl;
	}
	sleep(3);
}

//		--:( MAIN FUNCTION ):--		//

int main()
{
	cout << "\t\tProduct Management System\n\n";

	int choice;
	string shop_menu = "\n\n\t(MENU)\nEnter 1 to add product\nEnter 2 to remove the product\nEnter 3 to display all the products\nEnter your choice: ";

	details(); // Will display the details about the program...

	bool shop_isOPEN = true;
	while (shop_isOPEN)
	{
		cout << "\t\tProduct Management System\n\n";
		cout << shop_menu;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			productData();
			addProduct();
			waitScreen();
			break;
		}
		case 2:
		{
			deleteProduct();
			waitScreen();
			break;
		}
		case 3:
		{
			displayProduct();
			waitScreen();
			break;
		}
		default:
		{
			cout << "Invalid Choice! Try again....\n";
			waitScreen();
			break;
		}
		}
	}

	return 0;
}