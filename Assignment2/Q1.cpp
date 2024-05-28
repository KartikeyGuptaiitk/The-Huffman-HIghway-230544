#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class Transaction {
public:
    string date;
    double amount;
    string type;

    Transaction(string date, double amount, string type)
        : date(date), amount(amount), type(type) {}
};

class Loan {
public:
    double amount;
    string date;

    Loan(double amount, string date)
        : amount(amount), date(date) {}
};

class Account {
protected:
    int accountNumber;
    string holderName;
    string address;
    string accountType;
    double funds;
    vector<Transaction> transactionHistory;
    vector<Loan> loanHistory;

public:
    Account(int accNum, string holder, string addr, string accType, double initialFunds)
        : accountNumber(accNum), holderName(holder), address(addr), accountType(accType), funds(initialFunds) {}

    virtual void deposit(double amount) {
        funds += amount;
        string date = getCurrentDate();
        transactionHistory.push_back(Transaction(date, amount, "Deposit"));
    }

    virtual bool withdraw(double amount) {
        if (amount > funds) {
            cout << "Insufficient funds." << endl;
            return false;
        }
        funds -= amount;
        string date = getCurrentDate();
        transactionHistory.push_back(Transaction(date, amount, "Withdrawal"));
        return true;
    }

    void updateAddress(string newAddress) {
        address = newAddress;
    }

    void addJointAccountHolder(string jointHolderName) {
        holderName += " & " + jointHolderName;
    }

    void takeLoan(double amount) {
        funds += amount;
        string date = getCurrentDate();
        loanHistory.push_back(Loan(amount, date));
        transactionHistory.push_back(Transaction(date, amount, "Loan"));
    }

    bool transferFunds(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            return true;
        }
        return false;
    }

    void viewPassbook() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Address: " << address << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Funds: " << funds << endl;
        cout << "Transaction History: " << endl;
        for (const auto &transaction : transactionHistory) {
            cout << "Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
        }
        cout << "Loan History: " << endl;
        for (const auto &loan : loanHistory) {
            cout << "Date: " << loan.date << ", Amount: " << loan.amount << endl;
        }
    }

    void searchTransactionHistory(string date, double amount) {
        cout << "Search Results for Date: " << date << ", Amount: " << amount << endl;
        for (const auto &transaction : transactionHistory) {
            if (transaction.date == date && transaction.amount == amount) {
                cout << "Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
            }
        }
    }

    string getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string date = to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year);
        return date;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int accNum, string holder, string addr, double initialFunds)
        : Account(accNum, holder, addr, "Savings", initialFunds) {}
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, string holder, string addr, double initialFunds)
        : Account(accNum, holder, addr, "Checking", initialFunds) {}
};

int main() {
    SavingsAccount acc1(1001, "John Doe", "123 Main St", 5000.0);
    CheckingAccount acc2(1002, "Jane Smith", "456 Elm St", 3000.0);

    acc1.deposit(1000);
    acc1.withdraw(500);
    acc1.takeLoan(2000);
    acc1.viewPassbook();

    acc2.deposit(1500);
    acc2.withdraw(700);
    acc2.viewPassbook();

    acc1.transferFunds(acc2, 500);

    acc1.viewPassbook();
    acc2.viewPassbook();

    acc1.searchTransactionHistory("27-5-2024", 500);

    return 0;
}
