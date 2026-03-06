#include <bits/stdc++.h>
using namespace std;

/* DIP states that high-level modules should not depend on low-level modules. Both should depend on abstractions. */

// follow of DIP

class Database {
public:
  virtual void save(string data) = 0; // Abstraction
};

class MySQLDatabase : public Database
{ // Low-level module
public:
  void save(string data) override
  {
    cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
  }
};

class MongoDBDatabase : public Database
{ // Low-level module
public:
  void save(string data) override
  {
    cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
  }
};

class UserService
{ // High-level module 
private:

  Database *db;
 

public:
  UserService(Database *database) {
    db = database;
  }

  void storeUser(string user)
  {
    db->save(user);
  }
};

int main()
{
  MySQLDatabase sqlDb;
  MongoDBDatabase mongoDb;

  UserService *sqlService = new UserService(&sqlDb);
  UserService *mongoService = new UserService(&mongoDb);

  sqlService->storeUser("Aditya");
  mongoService->storeUser("Rohit");
}