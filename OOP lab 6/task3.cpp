#include <iostream>
using namespace std;

// Base Employee class with polymorphism
class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    virtual void showDetails() { cout << "ID: " << id << ", Name: " << name << endl; }
    virtual ~Employee() {}
};

// Abstract interfaces for responsibilities
class IOrderTaker {
public:
    virtual void takeOrder(const string& order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(const string& order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

// Waiter class implementing IOrderTaker
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override {
        cout << "Waiter " << name << " is taking order: " << order << endl;
    }
};

// Chef class implementing IOrderPreparer
class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
    void prepareOrder(const string& order) override {
        cout << "Chef " << name << " is preparing order: " << order << endl;
    }
};

// Cashier class implementing IBiller
class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
    void generateBill(double amount) override {
        cout << "Cashier " << name << " is generating a bill of $" << amount << endl;
    }
};

// Manager class implementing multiple roles
class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override {
        cout << "Manager " << name << " is taking order: " << order << endl;
    }
    void generateBill(double amount) override {
        cout << "Manager " << name << " is generating a bill of $" << amount << endl;
    }
};

// Base Menu class with polymorphism
class Menu {
protected:
    string items[10];
    double prices[10];
    int itemCount;
public:
    Menu() : itemCount(0) {}
    void addItem(const string& name, double price) {
        if (itemCount < 10) {
            items[itemCount] = name;
            prices[itemCount] = price;
            itemCount++;
        }
    }
    virtual double calculateTotal(const string orders[], int orderCount) = 0;
    virtual ~Menu() {}
};

// FoodMenu class
class FoodMenu : public Menu {
public:
    double calculateTotal(const string orders[], int orderCount) override {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < itemCount; j++) {
                if (orders[i] == items[j]) {
                    total += prices[j];
                    break;
                }
            }
        }
        return total;
    }
};

// BeverageMenu class with tax
class BeverageMenu : public Menu {
public:
    double calculateTotal(const string orders[], int orderCount) override {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < itemCount; j++) {
                if (orders[i] == items[j]) {
                    total += prices[j] * 1.1; // 10% tax on beverages
                    break;
                }
            }
        }
        return total;
    }
};

int main() {
    // Employees
    Waiter waiter(1, "John");
    Chef chef(2, "Gordon");
    Cashier cashier(3, "Alice");
    Manager manager(4, "Sophia");

    // Menus
    FoodMenu foodMenu;
    foodMenu.addItem("Burger", 5.0);
    foodMenu.addItem("Pizza", 8.0);
    
    BeverageMenu beverageMenu;
    beverageMenu.addItem("Cola", 2.0);
    beverageMenu.addItem("Coffee", 3.0);

    // Orders
    string foodOrder[] = {"Burger", "Pizza"};
    string drinkOrder[] = {"Cola", "Coffee"};

    // Process orders using polymorphism
    IOrderTaker* orderTaker = &waiter;
    IOrderPreparer* orderPreparer = &chef;
    IBiller* biller = &manager;

    orderTaker->takeOrder("Burger and Cola");
    orderPreparer->prepareOrder("Burger");
    orderPreparer->prepareOrder("Cola");
    
    double total = foodMenu.calculateTotal(foodOrder, 2) + beverageMenu.calculateTotal(drinkOrder, 2);
    biller->generateBill(total);

    return 0;
}

