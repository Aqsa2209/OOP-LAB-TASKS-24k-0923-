#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    virtual ~Person() {} // Virtual destructor to make the class polymorphic

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayData() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Admin : public Person {
public:
    double bonus() const {
        return 0.1 * 50000; // Example bonus calculation
    }
};

class Account : public Person {
public:
    double bonus() const {
        return 0.2 * 60000; // Example bonus calculation
    }
};

class Master : public Person {
public:
    double calculateBonus(Person* p) {
        if (Admin* admin = dynamic_cast<Admin*>(p)) {
            return admin->bonus();
        } else if (Account* account = dynamic_cast<Account*>(p)) {
            return account->bonus();
        }
        return 0;
    }
};

int main() {
    Master master;
    Admin admin;
    Account account;

    // Get data for Admin
    cout << "Admin Data:" << endl;
    admin.getData();

    // Get data for Account
    cout << "Account Data:" << endl;
    account.getData();

    // Calculate and display bonuses
    cout << "Admin Bonus: $" << master.calculateBonus(&admin) << endl;
    cout << "Account Bonus: $" << master.calculateBonus(&account) << endl;

    return 0;
}
