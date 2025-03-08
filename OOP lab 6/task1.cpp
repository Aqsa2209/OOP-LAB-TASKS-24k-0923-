#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Withdrawal failed: Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        balance += balance * interestRate / 100;
    }

    void display() const {
        BankAccount::display();
        cout << "Account Type: Savings" << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    bool withdraw(double amount) {
        if (amount > balance + overdraftLimit) {
            cout << "Withdrawal failed: Overdraft limit exceeded." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    void display() const {
        BankAccount::display();
        cout << "Account Type: Checking" << endl;
    }
};

class BusinessAccount : public BankAccount {
private:
    double corporateTaxRate;

public:
    BusinessAccount(const string& accNum, double initialBalance, double taxRate)
        : BankAccount(accNum, initialBalance), corporateTaxRate(taxRate) {}

    void deposit(double amount) {
        double tax = amount * corporateTaxRate / 100;
        balance += (amount - tax);
    }

    void display() const {
        BankAccount::display();
        cout << "Account Type: Business" << endl;
    }
};

class Customer {
private:
    string name;

public:
    Customer(const string& userName) : name(userName) {}

    void deposit(BankAccount& account, double amount) {
        account.deposit(amount);
        cout << name << " deposited " << amount << " to account " << account.getAccountNumber() << endl;
    }

    void withdraw(BankAccount& account, double amount) {
        if (account.withdraw(amount)) {
            cout << name << " withdrew " << amount << " from account " << account.getAccountNumber() << endl;
        }
    }
};

class Teller {
private:
    string name;

public:
    Teller(const string& userName) : name(userName) {}

    void deposit(BankAccount& account, double amount) {
        account.deposit(amount);
        cout << name << " (Teller) deposited " << amount << " to account " << account.getAccountNumber() << endl;
    }

    void withdraw(BankAccount& account, double amount) {
        if (account.withdraw(amount)) {
            cout << name << " (Teller) withdrew " << amount << " from account " << account.getAccountNumber() << endl;
        }
    }

    void freezeAccount(BankAccount& account) {
        // Logic to freeze the account (to be implemented)
        cout << name << " (Teller) froze account " << account.getAccountNumber() << endl;
    }
};

class Manager {
private:
    string name;

public:
    Manager(const string& userName) : name(userName) {}

    void deposit(BankAccount& account, double amount) {
        account.deposit(amount);
        cout << name << " (Manager) deposited " << amount << " to account " << account.getAccountNumber() << endl;
    }

    void withdraw(BankAccount& account, double amount) {
        if (account.withdraw(amount)) {
            cout << name << " (Manager) withdrew " << amount << " from account " << account.getAccountNumber() << endl;
        }
    }

    void overrideLimit(BankAccount& account, double newLimit) {
        // Logic to override account limits (to be implemented)
        cout << name << " (Manager) changed account limit for " << account.getAccountNumber() << endl;
    }
};

int main() {
    SavingsAccount savings("S123", 1000.0, 5.0);
    CheckingAccount checking("C123", 500.0, 200.0);
    BusinessAccount business("B123", 2000.0, 15.0);

    Customer customer("Ali");
    Teller teller("Fatima");
    Manager manager("Ahsan");

    customer.deposit(savings, 100);
    customer.withdraw(checking, 600); // Should succeed
    customer.withdraw(checking, 700); // Should fail due to overdraft limit

    teller.deposit(business, 500);
    teller.withdraw(business, 1000);

    manager.deposit(savings, 200);
    manager.withdraw(checking, 800); // Should succeed now

    savings.applyInterest();
    savings.display();
    checking.display();
    business.display();

    return 0;
}
