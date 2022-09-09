#include <iostream>

class Solution {
public:
    int fib(int n) {
      int first = 0;
      int second = 1;
      if (n==0)
        return first;
      if (n==1)
        return second;
      n--;
      while (n--){
        int temp = first + second;
        first = second;
        second = temp;
      }
      return second;
    }
};


int main (int argc, char *argv[])
{
  Solution test;
  int n;
  std::cin >> n;
  std::cout << test.fib(n) << std::endl;
  return 0;
}
