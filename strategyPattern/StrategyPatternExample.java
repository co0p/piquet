
import java.util.*;

class StrategyPatternExample {
  SortStrategy strategy;

  void setStrategy(SortStrategy newStrategy){ strategy = newStrategy; }

  void run(ArrayList list) {
    System.out.println("before: " + list);
    strategy.sort(list);
    System.out.println("after: " + list);
  }

  public static void main(String[] args) {

    ArrayList list = new ArrayList();
    list.add(2);
    list.add(3);
    list.add(1);
    list.add(5);
    list.add(4);

    StrategyPatternExample example = new StrategyPatternExample();
    example.setStrategy(new QuickSort());
    example.run(list);
  }
}

  /* code versus interface not implementation */
  interface SortStrategy {
    public abstract void sort(ArrayList list);
  }
  
  /* concrete strategy */
  class ApiSort implements SortStrategy {
    public void sort(ArrayList list) {
      Collections.sort(list);
    } 
  }

  /* another concrete strategy */
  class QuickSort implements SortStrategy {
    ArrayList list;

    public void sort(ArrayList newList) {
      list = newList;
      /* todo */
    }
  }