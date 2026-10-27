#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountID;
public:
    Account(string id) { accountID = id; }
    void getAccountInfo() const { cout << "Account ID: " << accountID << endl; }
};

class BankAccount : public Account {
protected:
    double balance;
public:
    BankAccount(string id, double initialBalance) : Account(id) { balance = initialBalance; }
    void depositMoney(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    float interestRate;
public:
    SavingsAccount(string id, double initialBalance, float rate) 
        : BankAccount(id, initialBalance) { interestRate = rate; }
    void addInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added at " << interestRate << "% | New Balance: $" << balance << endl;
    }
};

int main() {
    cout << "--- Chained Inheritance Demo ---" << endl;
    SavingsAccount mySavings("SAV-12345", 1000.0, 5.0);
    mySavings.getAccountInfo();
    mySavings.depositMoney(500.0);
    mySavings.addInterest();
    return 0;
}