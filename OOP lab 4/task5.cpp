#include <iostream>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    string type; 
    double price;

    MenuItem(const string& itemName, const string& itemType, double itemPrice) 
        : name(itemName), type(itemType), price(itemPrice) {}
};

class CoffeeShop {
private:
    string name;
    MenuItem* menu[100]; 
    string orders[100]; 
    int menuCount;
    int orderCount;

public:
    CoffeeShop(const string& shopName) : name(shopName), menuCount(0), orderCount(0) {}

    void addMenuItem(const MenuItem& item) {
        if (menuCount < 100) {
            menu[menuCount++] = new MenuItem(item);
        } else {
            cout << "Menu is full, cannot add more items." << endl;
        }
    }

    string addOrder(const string& itemName) {
        for (int i = 0; i < menuCount; i++) {
            if (menu[i]->name == itemName) {
                if (orderCount < 100) {
                    orders[orderCount++] = itemName;
                    return "Order added: " + itemName;
                } else {
                    return "Order list is full.";
                }
            }
        }
        return "This item is currently unavailable.";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + item + " is ready.";
        }
        return "All orders have been fulfilled.";
    }

    string listOrders() const {
        if (orderCount == 0) {
            return "[]";
        }
        string orderList = "[";
        for (int i = 0; i < orderCount; i++) {
            orderList += orders[i];
            if (i < orderCount - 1) {
                orderList += ", ";
            }
        }
        orderList += "]";
        return orderList;
    }

    double dueAmount() const {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuCount; j++) {
                if (orders[i] == menu[j]->name) {
                    total += menu[j]->price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menuCount == 0) {
            return "No items on the menu.";
        }
        double minPrice = menu[0]->price;
        string cheapest = menu[0]->name;

        for (int i = 1; i < menuCount; i++) {
            if (menu[i]->price < minPrice) {
                minPrice = menu[i]->price;
                cheapest = menu[i]->name;
            }
        }
        return cheapest;
    }

    string drinksOnly() const {
        string drinkList = "";
        for (int i = 0; i < menuCount; i++) {
            if (menu[i]->type == "drink") {
                drinkList += menu[i]->name + ", ";
            }
        }
        if (!drinkList.empty()) {
            drinkList = drinkList.substr(0, drinkList.length() - 2);
        }
        return drinkList.empty() ? "No drinks available." : drinkList;
    }

    string foodOnly() const {
        string foodList = "";
        for (int i = 0; i < menuCount; i++) {
            if (menu[i]->type == "food") {
                foodList += menu[i]->name + ", ";
            }
        }
        if (!foodList.empty()) {
            foodList = foodList.substr(0, foodList.length() - 2); 
        }
        return foodList.empty() ? "No food available." : foodList;
    }

    ~CoffeeShop() {
        for (int i = 0; i < menuCount; i++) {
            delete menu[i]; 
        }
    }
};

int main() {
    string shopName;
    cout << "Enter the name of the coffee shop: ";
    getline(cin, shopName);
    CoffeeShop shop(shopName);
    int numberOfItems;
    cout << "Enter the number of menu items to add: ";
    cin >> numberOfItems;

    for (int i = 0; i < numberOfItems; i++) {
        string name, type;
        double price;

        cout << "\nEnter details for menu item " << (i + 1) << ":\n";
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Type (food/drink): ";
        getline(cin, type);
        cout << "Price: ";
        cin >> price;

        shop.addMenuItem(MenuItem(name, type, price));
    }
    string orderName;
    char moreOrders;

    do {
        cout << "\nEnter an item to order: ";
        cin.ignore(); 
        getline(cin, orderName);
        cout << shop.addOrder(orderName) << endl;

        cout << "Would you like to add another order? (y/n): ";
        cin >> moreOrders;
    } while (moreOrders == 'y' || moreOrders == 'Y');
    cout << shop.fulfillOrder() << endl;
    cout << "Current Orders: " << shop.listOrders() << endl;
    cout << "Total Amount Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    cout << "Drinks Only: " << shop.drinksOnly() << endl;
    cout << "Food Only: " << shop.foodOnly() << endl;

    return 0;
}
