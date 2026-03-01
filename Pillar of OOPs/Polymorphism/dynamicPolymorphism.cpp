#include <bits/stdc++.h>
using namespace std;

/* dynamic polymorphism is also known as runtime polymorphism or method overriding. It is achieved by defining a virtual function in the base class and overriding it in the derived class. The decision of which function to call is made at runtime based on the type of the object pointed to by the base class pointer. In the context of our Car example, we can have a base class Car with a virtual function startEngine() and a derived class SportsCar that overrides this function to provide a specific implementation for starting the engine of a sports car. When we create a pointer of type Car and point it to an object of type SportsCar, and call the startEngine() function, the overridden version in the SportsCar class will be called at runtime, demonstrating dynamic polymorphism.
*/

class Car
{
protected:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;

public:
  Car(string b, string m)
  {
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentSpeed = 0;
  }
  virtual void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << " : Engine starts with a roar!" << endl;
  }
  virtual void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    cout << brand << " " << model << " : Engine turned off." << endl;
  }
};

class SportsCar : public Car
{
public:
  SportsCar(string b, string m) : Car(b, m) {}
  void startEngine() override
  {
    isEngineOn = true;
    cout << brand << " " << model << " : Sports car engine starts with a roar!" << endl;
  }
};

int main()
{
  Car *myCar = new SportsCar("Ferrari", "488 Spider");
  myCar->startEngine();
  myCar->stopEngine();
  delete myCar;
  return 0;
}