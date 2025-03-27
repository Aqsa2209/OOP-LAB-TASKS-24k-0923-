#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    int employeeID;

public:
    // Function to get employee ID
    void getData(int id) {
        employeeID = id;
    }

    // Function to display employee ID
    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived class for Admin
class Admin : public Person {
private:
    string name;       
    double monthlyIncome;

public:
    // Function to get Admin data
    void getData(int id, const string& empName, double income) {
        Person::getData(id); // Call base class function
        name = empName;
        monthlyIncome = income;
    }

    // Function to calculate bonus
    double bonus() const {
        return monthlyIncome * 0.05 * 12; // Annual bonus calculation
    }

    // Function to display Admin data
    void displayData() const {
        Person::displayData(); // Display Employee ID
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

// Derived class for Accounts
class Accounts : public Person {
private:
    string name;        
    double monthlyIncome; 

public:
    // Function to get Accounts data
    void getData(int id, const string& empName, double income) {
        Person::getData(id); // Call base class function
        name = empName;
        monthlyIncome = income;
    }

    // Function to calculate bonus
    double bonus() const {
        return monthlyIncome * 0.05 * 12; // Annual bonus calculation
    }

    // Function to display Accounts data
    void displayData() const {
        Person::displayData(); // Display Employee ID
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

int main() {
    Admin admin;
    Accounts accounts;
    admin.getData(101, "Alice Smith", 4000);
    accounts.getData(102, "Bob Johnson", 3500);
    cout << "Admin Information:" << endl;
    admin.displayData();
    cout << endl;
    cout << "Accounts Information:" << endl;
    accounts.displayData();

    return 0;
}
