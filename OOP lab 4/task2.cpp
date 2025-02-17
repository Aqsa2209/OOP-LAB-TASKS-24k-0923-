#include <iostream>

using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid credit amount." << endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Debited: " << amount << ". New balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
        } else {
            cout << "Invalid debit amount." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    double initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account myAccount(initialBalance);
    cout << "Initial balance: " << myAccount.getBalance() << endl;

    double creditAmount, debitAmount;
    cout << "Enter amount to credit: ";
    cin >> creditAmount;
    myAccount.credit(creditAmount);

    cout << "Enter amount to debit: ";
    cin >> debitAmount;
    myAccount.debit(debitAmount);

    cout << "Final balance: " << myAccount.getBalance() << endl;

    return 0;
}
