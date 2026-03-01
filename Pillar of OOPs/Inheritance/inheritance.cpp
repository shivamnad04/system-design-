#include <bits/stdc++.h>
using namespace std;

/*
We know that real world Objects show inheritance relationship where we
have parent object and child object. child object have all the characters
or behaviours that parent have plus some additional characters/behaviours.
Like all cars in real world have a brand, model etc and can start, stop,
accelerate etc. But some specific cars like manual car have gear System
while other specific cars like Electric cars have battery system.

We represent this scenario of real world in programming by creating a parent class and
defining all the characters(variables) or behaviours(methods) that all cars
have in parent class. Then we create different child classes that inherits
from this parent class and define only those characters and behaviours
that are specific to them. Although objects of these child classes can
access or call parent class characters(variables) and behaviours(methods).
Hence providing code reusability.
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

  void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << " : Engine starts with a roar!" << endl;
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
    currentSpeed = 0;
    cout << brand << " " << model << " : Engine turned off." << endl;
  }
};

class ManualCar : public Car
{ // ManualCar is a child class of Car and inherits all the characters and behaviours of Car class
private:
  int currentGear;

public:
  ManualCar(string b, string m) : Car(b, m)
  {
    currentGear = 0;
  }
  // gear shifting is specific to manual cars so we define it in ManualCar class
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
};

class ElectricCar : public Car
{ // ElectricCar is a child class of Car and inherits all the characters and behaviours of Car class
private:
  int batteryLevel;

public:
  ElectricCar(string b, string m) : Car(b, m)
  {
    batteryLevel = 100;
  }
  // battery level is specific to electric cars so we define it in ElectricCar class
  void checkBatteryLevel()
  {
    cout << brand << " " << model << " : Battery level is " << batteryLevel << "%" << endl;
  }
};


int main()
{
  ManualCar *myCar = new ManualCar("Ferrari", "488 Spider");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();  
  myCar->brake();
  myCar->stopEngine();  
  delete myCar;
  
  ElectricCar *myElectricCar = new ElectricCar("Tesla", "Model S");
  myElectricCar->startEngine();
  myElectricCar->checkBatteryLevel();
  myElectricCar->accelerate();
  myElectricCar->brake();
  myElectricCar->stopEngine();
  delete myElectricCar;
  return 0;
}