#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    string accountType;
    double balance;

public:
    Account(string accNum, string accHolder, string accType)
        : accountNumber(accNum), accountHolderName(accHolder), accountType(accType), balance(0.0) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Invalid withdraw amount!" << endl;
        }
    }

    virtual void calculateInterest() = 0;

    void printStatement() {
        cout << "Account Number: " << accountNumber << "\n"
             << "Account Holder: " << accountHolderName << "\n"
             << "Account Type: " << accountType << "\n"
             << "Current Balance: " << balance << "\n" << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, string accHolder, double rate, double minBalance)
        : Account(accNum, accHolder, "Savings"), interestRate(rate), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw, minimum balance requirement not met!" << endl;
        }
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Interest for Savings Account (" << accountNumber << "): " << interest << endl;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string accHolder, double overdraft)
        : Account(accNum, accHolder, "Checking"), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void calculateInterest() override {
        cout << "Checking Accounts do not earn interest." << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;

public:
    FixedDepositAccount(string accNum, string accHolder, double rate)
        : Account(accNum, accHolder, "Fixed Deposit"), fixedInterestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Interest for Fixed Deposit Account (" << accountNumber << "): " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed until maturity date!" << endl;
    }
};

int main() {
    SavingsAccount savings("S123", "Aqsa", 5.0, 100.0);
    savings.deposit(500);
    savings.calculateInterest();
    savings.printStatement();
    savings.withdraw(450);
    savings.printStatement();

    CheckingAccount checking("C456", "Rafia", 200.0);
    checking.deposit(300);
    checking.withdraw(350);
    checking.printStatement();

    FixedDepositAccount fixedDeposit("FD789", "Urooj", 6.0);
    fixedDeposit.deposit(1000);
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();
    fixedDeposit.withdraw(100); // Should not be allowed

    return 0;
}
