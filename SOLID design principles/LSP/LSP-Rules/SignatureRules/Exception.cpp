#include <iostream>

using namespace std;

/*Signature Rules for LSP - Exception Handling*/
/*it state that a subclass should throw fewer or narrower exceptions than its parent class. This means that if a parent class method throws a certain type of exception, the subclass method should either throw the same type of exception or a more specific one, but not a more general exception.*/

/*
├── std::logic_error        <-- For logical errors detected before runtime
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error   
*/

class Parent {
public:
    virtual void getValue() noexcept(false) { // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() noexcept(false)  override { // Child throws out_of_range exception
        throw out_of_range("Child error");
        // throw runtime_error("Child Error"); // This is Wrong
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout << "Logic error exception occured : " << e.what() << endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    //Client* client = new Client(parent);
    Client* client = new Client(child);

    client->takeValue();

    return 0;
}
    