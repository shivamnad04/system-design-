#include <bits/stdc++.h>
using namespace std;  

/*History Constraint for LSP*/
/*If a parent class has a history constraint, a subclass should maintain that constraint or strengthen it, but never weaken it.*/

// example -> if a parent class has a history constraint that states that an account balance cannot go negative, the subclass should also enforce this constraint or make it stricter (e.g., by not allowing any withdrawals at all), but it should not allow the balance to go negative.

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }

    // History Constraint : Withdraw should be allowed
    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
    

class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    // LSP break! History constraint broke!
    // Parent class behaviour change : Now withdraw is not allowed.
    //This class will brake client code that relies on withdraw.
    void withdraw(double amount) override {
        throw runtime_error("Withdraw not allowed in Fixed Deposit");
    }
};
    
int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
    BankAccount* fixedDeposit = new FixedDepositAccount(100);
    fixedDeposit->withdraw(100); // This will throw an exception, breaking the client code  
    return 0;
} 