/* example usage of the decorator pattern, 
from the head first pattern book*/

#include <string>
#include <iostream>

using namespace std;

/* */
class Beverage {
  public:
  virtual string getDescription() = 0;
  virtual int cost() = 0;
};

/* a beverage we would like to 'decorate' */
class Coffee : public Beverage {
  private:
    string description;
    int price;
  
  public:
  Coffee() {
    description = "Coffee";
    price = 70;
  }
  string getDescription() { return description; }
  int cost() { return price; }
};


/* another beverage we want to decorate */
class Special : public Beverage {
  private:
    string description;
    int price;
  
  public:
  Special() {
    description = "Coffee";
    price = 100;
  }
  string getDescription() { return description; }
  int cost() { return price; }
};

/* this is the super class we use for decoration */
class Addition : public Beverage {
  private:
    int price;

  public:
    Beverage* subject;

    Addition(Beverage& beverage) : Beverage() {

      price = 0;
      subject = &beverage;
    }
    int cost() {
      return price + subject->cost();
    }
};

/* finally something to decorate with */
class Milk : public Addition {
  private:
    string description;

  public:
    Milk(Beverage* bev) : Addition(*bev) {
      description = subject->getDescription() + " + milk";
    }

    string getDescription() {
      return description;
    }

    int cost() {
      return subject->cost() + 25;
    }
};


class Sugar : public Addition {
  private:
    string description;

    public: 
      Sugar(Beverage* bev) : Addition(*bev) {
        description = subject->getDescription() + " + sugar";
      }

    string getDescription() {
      return description;
    }

    int cost() {
      return subject->cost() + 10;
    }
};

int main(int argc, char* argv[]) {


  Beverage *drink1 = new Coffee();
  cout << "regular coffee: " << drink1->cost() << endl;

  Beverage *drink2 = new Coffee();
  drink2 = new Milk(drink2);

  cout << "coffee with milk: " << drink2->cost() << endl;

  Beverage *drink3 = new Sugar(new Milk(new Special()));
  cout << "special with milk, sugar: " << drink3->cost() << endl;

  return 0;
}