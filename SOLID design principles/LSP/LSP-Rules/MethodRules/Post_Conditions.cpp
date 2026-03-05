#include <bits/stdc++.h>
using namespace std;

/*Post-Conditions for LSP*/
/*If a parent class has specific post-conditions for its methods, a subclass should maintain those post-conditions.*/
// A subclass must fullfill all the promises made by the parent class method.
//example -> if a parent class method guarantees that it will return a positive value, the subclass method should also guarantee the same.



class Car {
protected:
    int speed;    

public:
    Car() {
        speed = 0;
    }
    
    void accelerate() {
        cout << "Accelerating" << endl;
        speed += 20;
    }

    //PostCondition : Speed must reduce after brake
    virtual void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car {
private:
    int charge;

public:

    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake
    // PostCondition : Charge must increase.
    void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;
    }
};


int main() {
    Car* hybridCar = new HybridCar();
    hybridCar->brake();  // Works fine: HybridCar reduces speed and also increases charge.

    //Client feels no difference in substituting Hybrid car in place of Car.

    return 0;
}