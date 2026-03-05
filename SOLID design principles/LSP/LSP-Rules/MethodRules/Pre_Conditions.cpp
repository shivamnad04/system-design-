#include <bits/stdc++.h>
using namespace std;  

/*Pre-Conditions for LSP*/
/*If a parent class has specific pre-conditions for its methods, a subclass should maintain those pre-conditions.*/
// A subclass cannot be "picker" than its parent class in terms of input requirements.
//example -> if a parent class method requires a integer as an argument, the subclass method should not suddenly require a positive integer or a non-zero integer, as this would violate the LSP by making the subclass less substitutable for the parent class. The subclass should accept the same range of inputs as the parent class to ensure that it can be used in place of the parent class without causing issues.


class User {
public:
    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password) {
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

class AdminUser : public User {
public:
    // Precondition: Password must be at least 6 characters
    void setPassword(string password) override {
        if (password.length() < 6) { 
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

int main() {
    User* user = new AdminUser();
    user->setPassword("Admin1");  // Works fine: AdminUser allows shorter passwords

    return 0;
}