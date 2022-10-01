


#include <iostream>
#include <vector>




class Solution {
  public:
    int getSum(int n) {
      int sum = 0;
      while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      return sum;
    }
    bool isHappy(int n) {
      bool hash_map[100] = {0};
      while (n >= 100 || !hash_map[n]) {
        if(n < 100){
          hash_map[n] = true;
        }
        n = getSum(n);
      }
      if(n==1){
        return true;
      }
      return false;
    }
};
