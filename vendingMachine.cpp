#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Product 
{
    string name;
    double price;
    int quantity;
};

class VendingMachine 
{
private:
    vector<Product> products;
    double currentBalance;

public:
    VendingMachine() : currentBalance(0) 
	{
        // Initialize products
        products = 
		{
            {"Coke", 1.50, 5},
            {"Pepsi", 1.50, 5},
            {"Snickers", 1.00, 3},
            {"KitKat", 1.00, 3},
            {"Water", 0.75, 5}
        };
    }

    void displayProducts() const 
	{
        cout << "Available Products:" << endl;
        cout << "-------------------" << endl;
        for (size_t i = 0; i < products.size(); ++i) 
		{
            cout << i + 1 << ". " << products[i].name << " - $" << fixed << setprecision(2) << products[i].price
                 << " (" << products[i].quantity << " left)" << endl;
        }
        cout << "-------------------" << endl;
    }

    void insertCoin(double amount) 
	{
        currentBalance += amount;
        cout << "Inserted $" << fixed << setprecision(2) << amount << ". Current balance: $"
             << currentBalance << endl;
    }

    int selectProduct() const 
	{
        int choice;
        cout << "Enter the number of the product you want to purchase (or 0 to cancel): ";
        cin >> choice;
        return choice;
    }

    void processTransaction(int choice) 
	{
        if (choice > 0 && choice <= products.size()) 
		{
            int index = choice - 1;
            if (products[index].quantity > 0) 
			{
                if (currentBalance >= products[index].price) 
				{
                    products[index].quantity--;
                    currentBalance -= products[index].price;
                    cout << "Dispensing " << products[index].name << ". Enjoy!" << endl;
                    if (currentBalance > 0) 
					{
                        cout << "Your change is $" << fixed << setprecision(2) << currentBalance << endl;
                        currentBalance = 0;
                    }
                } 
				else 
				{
                    cout << "Insufficient funds. Please insert $" << fixed << setprecision(2)
                         << products[index].price - currentBalance << " more." << endl;
                }
            } 
			else 
			{
                cout << "Sorry, " << products[index].name << " is sold out." << endl;
            }
        } 
		else if (choice != 0)
		{
          cout << "Invalid choice." << endl;
        }
    }

    void run() 
	{
        int choice;
        do 
		{
            displayProducts();
            cout << "Current balance: $" << fixed << setprecision(2) << currentBalance << endl;
            cout << "1. Insert coin" << endl;
            cout << "2. Select product" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) 
			{
                case 1: 
				{
                    double amount;
                    cout << "Enter amount to insert: $";
                    cin >> amount;
                    insertCoin(amount);
                    break;
                }
                case 2: 
				{
                    if (currentBalance > 0) 
					{
                      int productChoice = selectProduct();
                      processTransaction(productChoice);
                    } 
					else 
					{
                      cout << "Please insert coin first" << endl;
                    }
                    break;
                }
                case 0:
                    cout << "Exiting vending machine." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 0);
    }
};

int main() 
{
    VendingMachine vendingMachine;
    vendingMachine.run();
    return 0;
}