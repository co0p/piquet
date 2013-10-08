/* example usage of the observer pattern */

import java.util.*;

/**************************************
** interfaces
***************************************/
interface Observable {
  public void addObserver(Observer o);
  public void removeObserver(Observer o);
  public void notifyObservers();
}

interface Observer {
  public void update(int level);
}


/**************************************
** concrete impl. using interfaces
***************************************/

class Alert implements Observable {
  ArrayList<Observer> observers;
  int level = 0;

  public Alert() {  observers = new ArrayList<>(); }

  public void addObserver(Observer o) {  observers.add(o); }
  public void removeObserver(Observer o) { observers.remove(o); }
  public void notifyObservers() { 
    for (Observer o : observers ) {
      o.update(level); 
    }
  }
  
  void setLevel(int level) { this.level = level; }
}


class FireDepartment implements Observer {
  public void update(int level) {
    if ( level > 50) response(10); else response(2);
  }
  void response(int cars) {
    System.out.println("FIRE will send '"+cars+"' cars!");
  }
}

class PoliceDepartment implements Observer {
  public void update(int level) {
    if ( level > 20) response(2); else response(1);
  }
  void response(int cars) {
    System.out.println("POLICE will send '"+cars+"' cars!");
  }
}


/**************************************
** use case: city alert system
***************************************/
class ObserverPatternExample {
  public static void main(String[] args) {
    ObserverPatternExample example = new ObserverPatternExample();
    example.run();
  }

  /* simulate a city alert system */
  void run() {
    
    FireDepartment fire = new FireDepartment();
    PoliceDepartment police = new PoliceDepartment();

    Alert alert = new Alert();
    alert.addObserver(fire);
    alert.addObserver(police);

    alert.setLevel(100);
    alert.notifyObservers();

    alert.setLevel(20);
    alert.notifyObservers(); 
  }
}