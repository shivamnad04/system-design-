#include <bits/stdc++.h>
using namespace std;

/* Liskov Substitution Principle states that objects of a superclass should be replaceable with objects of its subclasses without breaking the application. */

// followed LSP

// Here, we have separated the withdrawable accounts and non-withdrawable accounts into different interfaces, ensuring that each class only implements the behaviors it supports. This way, we can replace any account type without breaking the application logic.
class nonWithdrawAccount
{
public:
  virtual void deposit(double amount) = 0;
};
class withdrawAccount : public nonWithdrawAccount
{
public:
  virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public withdrawAccount
{
private:
  double balance;

public:
  SavingsAccount()
  {
    balance = 0.0;
  }
  void deposit(double amount) override
  {
    balance += amount;
    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
  }
  void withdraw(double amount) override
  {
    if (amount > balance)
    {
      cout << "Insufficient funds!" << endl;
    }
    else
    {
      balance -= amount;
      cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
    }
  }
};
class currentAccount : public withdrawAccount
{
private:
  double balance;

public:
  currentAccount()
  {
    balance = 0.0;
  }
  void deposit(double amount) override
  {
    balance += amount;
    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
  }
  void withdraw(double amount) override
  {
    if (amount > balance)
    {
      cout << "Overdraft! You can withdraw more than your balance." << endl;
    }
    balance -= amount;
    cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
  }
};

class FixedDepositAccount : public nonWithdrawAccount
{
private:
  double balance;

public:
  FixedDepositAccount()
  {
    balance = 0.0;
  }
  void deposit(double amount) override
  {
    balance += amount;
    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
  }
  // FixedDepositAccount does not implement withdraw, as it doesn't allow withdrawals
};

class BankClient {
private:
    vector<withdrawAccount*> withdrawableAccounts;
    vector<nonWithdrawAccount*> depositOnlyAccounts;

public:
    BankClient( vector<withdrawAccount*> withdrawableAccounts, 
        vector<nonWithdrawAccount*> depositOnlyAccounts) { 
        this->withdrawableAccounts = withdrawableAccounts; 
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        for (withdrawAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500); 
        }
        for (nonWithdrawAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }
    }
};

int main() {
    vector<withdrawAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new currentAccount());

    vector<nonWithdrawAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedDepositAccount());

    BankClient* client = new BankClient (withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}
