#include <iostream>

class Solution {
  public:
    int fib(int n) {
      int first = 1;
      int second = 2;
      if (n==1)
        return first;
      if (n==2)
        return second;
      n -= 2;
      while (n--){
        int temp = first + second;
        first = second;
        second = temp;
      }
      return second;
    }
};
