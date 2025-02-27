#include <iostream>
#include <string>

using namespace std;

class CoffeeShop {
private:
    const string name; 
    string menu[4]; 
    double prices[4]; 
    string orders[10]; 
    int orderCount; 

public:
    CoffeeShop(string shopName) : name(shopName), orderCount(0) {
        menu[0] = "Coffee"; prices[0] = 2.5;
        menu[1] = "Tea"; prices[1] = 1.5;
        menu[2] = "Sandwich"; prices[2] = 5.0;
        menu[3] = "Cake"; prices[3] = 3.0;
    }

    void addOrder(string item) {
        bool found = false;
        for (int i = 0; i < 4; i++) {
            if (menu[i] == item) {
                found = true;
                if (orderCount < 10) {
                    orders[orderCount++] = item; 
                    cout << item << " has been added to your order." << endl;
                } else {
                    cout << "Order limit reached!" << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "This item is currently unavailable!" << endl;
        }
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 1; i < orderCount; i++) {
                orders[i - 1] = orders[i]; 
            }
            orderCount--;
            return "The " + item + " is ready!";
        } else {
            return "All orders have been fulfilled";
        }
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders taken." << endl;
            return;
        }
        cout << "Current Orders: ";
        for (int i = 0; i < orderCount; i++) {
            cout << orders[i] << (i < orderCount - 1 ? ", " : "\n");
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < 4; j++) {
                if (orders[i] == menu[j]) {
                    total += prices[j]; 
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = prices[0];
        string item = menu[0];
        for (int i = 1; i < 4; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                item = menu[i];
            }
        }
        return item;
    }

    void drinksOnly() {
        cout << "Drinks on the menu: ";
        for (int i = 0; i < 4; i++) {
            if (menu[i] == "Coffee" || menu[i] == "Tea") {
                cout << menu[i] << (i < 3 ? ", " : "\n");
            }
        }
    }

    void foodOnly() {
        cout << "Food items on the menu: ";
        for (int i = 0; i < 4; i++) {
            if (menu[i] == "Sandwich" || menu[i] == "Cake") {
                cout << menu[i] << (i < 3 ? ", " : "\n");
            }
        }
    }
};

int main() {
    CoffeeShop shop("My Coffee Shop");

    shop.addOrder("Coffee");
    shop.addOrder("Sandwich");
    cout << shop.fulfillOrder() << endl;
    shop.listOrders();
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
