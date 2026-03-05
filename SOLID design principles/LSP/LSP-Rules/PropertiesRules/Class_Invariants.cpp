#include <bits/stdc++.h>
using namespace std;

/*Class Invariants for LSP*/
/*If a parent class has specific invariants, a subclass should maintain those invariants or strengthen them, but never weaken them.*/

// example -> if a parent class has an invariant that a certain member variable must always be positive, the subclass should ensure that this invariant is maintained and should not allow the member variable to become negative.

// Invariant: balance must always be non-negative
class Account
{
protected:
  double balance;

public:
  Account(double initialBalance)
  {
    if (initialBalance < 0)
    {
      throw invalid_argument("Initial balance cannot be negative");
    }
    balance = initialBalance;
  }
  virtual void withdraw(double amount)
  {
    if (balance - amount < 0)
    {
      throw runtime_error("Insufficient funds! Balance cannot go negative.");
    }
    else
    {
      balance -= amount;
      cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
    }
  }
  ~Account()
  {
    cout << "Account destructor called" << endl;
  }
};

// Brakes Invariant: should not be allowed.

class CheatingAccount : public Account
{
public:
  CheatingAccount(double initialBalance) : Account(initialBalance) {}
  void withdraw(double amount) override
  {
    balance -= amount; // This breaks the invariant as it allows balance to become negative without any checks.
    cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
  }
  ~CheatingAccount()
  {
    cout << "CheatingAccount destructor called" << endl;
  }
};

int main()
{
  Account *acc = new Account(100);
  acc->withdraw(50); // This will work fine, balance becomes 50
  acc->withdraw(60); // This will throw an exception, as it would make balance negative
  delete acc;
}
