#include <iostream>
#include <string>

using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double dailyDepositTotal;
    double dailyWithdrawTotal;

public:
    Wallet(double depositLimit, double withdrawLimit)
        : balance(0), dailyDepositLimit(depositLimit), dailyWithdrawLimit(withdrawLimit),
          dailyDepositTotal(0), dailyWithdrawTotal(0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive." << endl;
            return;
        }
        if (dailyDepositTotal + amount > dailyDepositLimit) {
            cout << "Error: Daily deposit limit exceeded." << endl;
            return;
        }
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Error: Insufficient balance." << endl;
            return;
        }
        if (dailyWithdrawTotal + amount > dailyWithdrawLimit) {
            cout << "Error: Daily withdrawal limit exceeded." << endl;
            return;
        }
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDepositTotal = 0;
        dailyWithdrawTotal = 0;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string userName, double depositLimit, double withdrawLimit)
        : userID(id), name(userName), wallet(depositLimit, withdrawLimit) {}

    void deposit(double amount) {
        wallet.deposit(amount);
    }

    void withdraw(double amount) {
        wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }
};

int main() {
    User user1("001", "Aqsa", 1000, 500);
    User user2("002", "Ayesha", 1500, 700);

    user1.deposit(300);
    user1.withdraw(100);
    cout << "Aqsa's Balance: " << user1.checkBalance() << endl;

    user2.deposit(1000);
    user2.withdraw(200);
    cout << "Ayesha's Balance: " << user2.checkBalance() << endl;

    // Attempting to withdraw more than the balance
    user1.withdraw(300);

    return 0;
}
