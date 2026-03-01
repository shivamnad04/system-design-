#include <iostream>
#include <string>

using namespace std;
/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/
class Car
{
public:
  virtual void startEngine() = 0;
  virtual void shiftGear(int gear) = 0;
  virtual void accelerate() = 0;
  virtual void brake() = 0;
  virtual void stopEngine() = 0;
  virtual ~Car()
  {
    cout << "Car Destructor called!" << endl;
  }
};

class SportsCar : public Car
{
private:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;
  int currentGear;
  // Introduce new variable to explain setters
  string tyreCompany;

public:
  int getCurrentSpeed()
  {
    return currentSpeed;
  }
  string getTyreCompany()
  {
    return tyreCompany;
  }
  string setTyreCompany(string tyre)
  {
    // we can add some validation here before setting the tyre company, for example we can check if the tyre company is valid or not. This way we can control how the variable is modified, providing data security.
    this->tyreCompany = tyre;
    return this->tyreCompany;
  }
  SportsCar(string b, string m, string tyre)
  {
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
    this->tyreCompany = tyre;
  }

  void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << " : Engine starts with a roar!" << endl;
  }

  void shiftGear(int gear)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
      return;
    }
    currentGear = gear;
    cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
  }

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
      return;
    }
    currentSpeed += 20;
    cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
  }

  void brake()
  {
    currentSpeed -= 20;
    if (currentSpeed < 0)
      currentSpeed = 0;
    cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
  }

  void stopEngine()
  {
    isEngineOn = false;
    currentGear = 0;
    currentSpeed = 0;
    cout << brand << " " << model << " : Engine turned off." << endl;
  }
};

int main()
{

  SportsCar *myCar = new SportsCar("Ford", "Mustang", "MRF");

  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();
  // myCar->currentSpeed = 500;
  // cout << "Current Speed: " << myCar->getCurrentSpeed() << endl;
  // we can not give direct access to currentSpeed variable as it is public, but we can provide a getter method to access it and setter method to modify it. This way we can control how the variable is accessed and modified, providing data security.
  myCar->brake();
  myCar->stopEngine();

  cout << "Current Tyre Company: " << myCar->getTyreCompany() << endl;

  myCar->setTyreCompany("CEAT");
  cout << "Current Tyre Company: " << myCar->getTyreCompany() << endl;

  delete myCar;

  return 0;
}