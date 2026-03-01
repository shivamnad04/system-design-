#include <bits/stdc++.h>
using namespace std;

/* SRP stands for Single Responsibility Principle. It states that a class should have only one reason to change, meaning that a class should have only one responsibility or job. This principle helps to keep the code organized and maintainable by ensuring that each class has a clear and focused purpose.
 */

// Example of SRP Violation

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
// This class is responsible for both managing the product details and handling the shopping cart operations, which violates the Single Responsibility Principle.
class ShoppingCart
{
private:
  vector<Product> products;

public:
  void addProduct(Product product)
  {
    products.push_back(product);
  }

  double calculateTotal()
  {
    double total = 0;
    for (auto product : products)
    {
      total += product.price * product.quantity;
    }
    return total;
  }

  void generateInvoice()
  {
    cout << "Invoice:" << endl;
    for (auto product : products)
    {
      cout << product.name << " - " << product.price << " x " << product.quantity << endl;
    }
    cout << "Total: " << calculateTotal() << endl;
  }
  void saveToDatabase()
  {
    // Code to save the shopping cart details to a database
    cout << "Saving shopping cart details to database..." << endl;
  }
};

int main()
{
  ShoppingCart cart;
  cart.addProduct(Product("Laptop", 1000, 1));
  cart.addProduct(Product("Mouse", 50, 2));

  cart.generateInvoice();
  cart.saveToDatabase();

  return 0;
}