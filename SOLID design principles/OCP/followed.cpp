#include <bits/stdc++.h>
using namespace std;

/* Open/Closed Principle is a fundamental principle in software engineering that states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means that you should be able to add new functionality to a class without modifying its existing code. */

// followed OCP

class Product
{
public:
  string name;
  double price;
  int quantity;

  Product(string name, double price, int quantity)
  {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
  }
};

class ShoppingCart
{
private:
  vector<Product *> products;

public:
  void addProduct(Product *p)
  {
    products.push_back(p);
  }

  const vector<Product *> &getProducts()
  {
    return products;
  }

  double calculateTotal()
  {
    double total = 0;
    for (auto p : products)
    {
      total += p->price * p->quantity;
    }
    return total;
  }
};

class ShoppingCartPrinter
{
private:
  ShoppingCart *cart;

public:
  ShoppingCartPrinter(ShoppingCart *cart)
  {
    this->cart = cart;
  }

  void printInvoice()
  {
    cout << "Shopping Cart Invoice:\n";
    for (auto p : cart->getProducts())
    {
      cout << p->name << " - Rs " << p->price << " x " << p->quantity << " = Rs " << (p->price * p->quantity) << endl;
    }
    cout << "Total: Rs " << cart->calculateTotal() << endl;
  }
};

class ShoppingCartStorage
{
private:
  ShoppingCart *cart;

public:
  ShoppingCartStorage(ShoppingCart *cart)
  {
    this->cart = cart;
  }

  virtual void save()
  {
    cout << "Saving shopping cart to database..." << endl;
  }
};
// New functionality added by creating new class, following OCP , now without modifying existing code, we can add new functionality by creating new class that inherits from ShoppingCartStorage and overrides the save method to save to file instead of database or any other storage.
class saveToDatabase : public ShoppingCartStorage
{
public:
  saveToDatabase(ShoppingCart *cart) : ShoppingCartStorage(cart) {}

  void save()
  {
    cout << "Saving shopping cart to database..." << endl;
  }
};
class saveToFile : public ShoppingCartStorage
{
public:
  saveToFile(ShoppingCart *cart) : ShoppingCartStorage(cart) {}

  void save()
  {
    cout << "Saving shopping cart to file..." << endl;
  }
};

int main()
{
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Laptop", 50000, 1));
  cart->addProduct(new Product("Mouse", 2000, 2));

  ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
  printer->printInvoice();

  // Saving to database
  ShoppingCartStorage *db = new saveToDatabase(cart);
  db->save();
  // Saving to file
  ShoppingCartStorage *file = new saveToFile(cart);
  file->save();

  return 0;
}