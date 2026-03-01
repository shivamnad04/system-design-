#include <bits/stdc++.h>
using namespace std;

/* SRP stands for Single Responsibility Principle. It states that a class should have only one reason to change, meaning that a class should have only one responsibility or job. This principle helps to keep the code organized and maintainable by ensuring that each class has a clear and focused purpose.
 */

// Example of SRP Followed

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

// 1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart
{
private:
  vector<Product *> products; // Store heap-allocated products

public:
  void addProduct(Product *p)
  {
    products.push_back(p);
  }

  const vector<Product *> &getProducts()
  {
    return products;
  }

  // Calculates total price in cart.
  double calculateTotal()
  {
    double total = 0;
    for (auto p : products)
    {
      total += p->price * p->quantity ;
    }
    return total;
  }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
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

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage
{
private:
  ShoppingCart *cart;

public:
  ShoppingCartStorage(ShoppingCart *cart)
  {
    this->cart = cart;
  }

  void saveToDatabase()
  {
    cout << "Saving shopping cart to database..." << endl;
  }
};

int main()
{
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Laptop", 50000 ,1));
  cart->addProduct(new Product("Mouse", 2000, 2));

  ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
  printer->printInvoice();

  ShoppingCartStorage *db = new ShoppingCartStorage(cart);
  db->saveToDatabase();

  return 0;
}