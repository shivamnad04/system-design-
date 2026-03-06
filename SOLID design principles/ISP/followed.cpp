#include <bits/stdc++.h>
using namespace std;

/* ISP states many client specific interfaces are better than one general-purpose interface.
   Clients should not be forced to implement methods they don't need. */

// Followed ISP

class Shape2D
{
public:
  virtual double area() = 0;
  virtual ~Shape2D() = default;
};

class Shape3D
{
public:
  virtual double area() = 0;
  virtual double volume() = 0;
  virtual ~Shape3D() = default;
};

// Square is a 2D shape
class Square : public Shape2D
{
private:
  double side;

public:
  Square(double s) : side(s) {}
  double area() override
  {
    return side * side;
  }
};

// Rectangle is a 2D shape
class Rectangle : public Shape2D
{
private:
  double length, width;

public:
  Rectangle(double l, double w) : length(l), width(w) {}
  double area() override
  {
    return length * width;
  }
};

// Cube is a 3D shape
class Cube : public Shape3D
{
private:
  double side;

public:
  Cube(double s) : side(s) {}
  double area() override
  {
    return 6 * side * side;
  }
  double volume() override
  {
    return side * side * side;
  }
};

int main()
{
  Shape2D *square = new Square(5);
  Shape2D *rectangle = new Rectangle(4, 6);
  Shape3D *cube = new Cube(3);

  cout << "Square Area: " << square->area() << endl;
  cout << "Rectangle Area: " << rectangle->area() << endl;
  cout << "Cube Area: " << cube->area() << endl;
  cout << "Cube Volume: " << cube->volume() << endl;

  delete square;
  delete rectangle;
  delete cube;

  return 0;
}