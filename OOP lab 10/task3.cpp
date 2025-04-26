#include <iostream>
#include <string>
using namespace std;

// Product Class
class Product {
public:
    string productId;
    string productName;
    string description;
    int price;

    Product() {}
    Product(string id, string name, string desc, int p)
        : productId(id), productName(name), description(desc), price(p) {}
};

// User Class
class User {
public:
    string userId;
    string firstName;
    string lastName;
    string address;
    string email;

    User() {}
    User(string id, string first, string last, string addr, string mail)
        : userId(id), firstName(first), lastName(last), address(addr), email(mail) {}
};

// Order Class
class Order {
public:
    string orderId;
    User* user;
    Product* productOrdered;
    int totalPaid;

    Order() {}
    Order(string id, User* u, Product* p, int paid)
        : orderId(id), user(u), productOrdered(p), totalPaid(paid) {}
};

int main() {
    // Create Users
    User users[2] = {
        User("1111", "Linus", "Torvalds", "Linux Street", "linus@example.com"),
        User("2222", "Ada", "Lovelace", "Math Street", "ada@example.com")
    };

    // Create Products
    Product products[3] = {
        Product("aaaa", "Laptop", "High performance laptop", 1500),
        Product("aaab", "Smartphone", "Latest model", 800),
        Product("aaac", "Keyboard", "Mechanical keyboard", 120)
    };

    // Create Orders
    Order orders[3] = {
        Order("bbbb", &users[0], &products[0], 1500), // Linus -> Laptop
        Order("bbbc", &users[0], &products[2], 120),  // Linus -> Keyboard
        Order("bbbd", &users[1], &products[1], 800)   // Ada -> Smartphone
    };

    // Fetch and display products ordered by Linus
    cout << "Products ordered by Linus:" << endl;
    for (int i = 0; i < 3; ++i) {
        if (orders[i].user->firstName == "Linus") {
            cout << "- " << orders[i].productOrdered->productName << endl;
        }
    }

    return 0;
}

