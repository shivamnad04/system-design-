#include <bits/stdc++.h>
using namespace std;

/* Liskov Substitution Principle states that objects of a superclass should be replaceable with objects of its subclasses without breaking the application. */

// violating LSP

class Account
{
public:
  virtual void withdraw(double amount) = 0;
  virtual void deposit(double amount) = 0;
};

class SavingsAccount : public Account
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
class currentAccount : public Account
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

// This class violates LSP because it does not allow withdrawals, which is a fundamental behavior expected from an Account. If we replace an Account with a FixedDepositAccount, it will break the application logic that expects all accounts to support withdrawals.
class FixedDepositAccount : public Account
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
  void withdraw(double amount) override
  {
    cout << "Withdrawals are not allowed from a Fixed Deposit Account!" << endl;
    throw runtime_error("Withdrawals are not allowed from a Fixed Deposit Account!");
  }
};

class BankClient
{
private:
  vector<Account *> accounts;

public:
  BankClient(vector<Account *> accounts)
  {
    this->accounts = accounts;
  }
  void performTransactions()
  {
    for (Account *account : accounts)
    {
      account->deposit(1000);
      try
      {
        account->withdraw(500);
      }
      catch (const runtime_error &e)
      {
        cout << "Error: " << e.what() << endl;
      }
    }
  }
};

int main()
{
  SavingsAccount *savings = new SavingsAccount();
  currentAccount *current = new currentAccount();
  FixedDepositAccount *fixedDeposit = new FixedDepositAccount();

  vector<Account *> accounts = {savings, current, fixedDeposit};
  BankClient client(accounts);
  client.performTransactions();

  delete savings;
  delete current;
  delete fixedDeposit;

  return 0;
}