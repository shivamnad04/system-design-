#include <bits/stdc++.h>
using namespace std;

/*static polymorphism is also known as compile time polymorphism or method overloading. It is achieved by defining multiple methods with the same name but different parameters in the same class. The compiler determines which method to call based on the number and type of arguments passed to the method.
In the context of our Car example, we can have multiple methods with the same name but different parameters to perform different actions. For example, we can have a method to accelerate the car by a certain speed and another method to accelerate the car by a certain percentage of its current speed. This way we can provide multiple ways to accelerate the car, and the compiler will determine which method to call based on the arguments passed to it.
*/

class ManualCar
{
private:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;
  int currentGear;

public:
  ManualCar(string b, string m)
  {
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
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
  void accelerate(int speed)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
      return;
    }
    currentSpeed += speed;
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
  ManualCar *myCar = new ManualCar("Ferrari", "488 Spider");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->accelerate(30); // using the overloaded method to accelerate by a specific speed
  myCar->brake();
  myCar->stopEngine();

  delete myCar;

  return 0;
}