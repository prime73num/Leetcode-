

#include <iostream>
#include <vector>

using namespace std;





class Solution {
  public:
    int monotoneIncreasingDigits(int n) {
      int state = 0;
      int p = INT_MAX;
      int target = n;
      int pos = -1;
      for (int i = 0; i < 10; i++) {
        int temp = target % 10;
        if(temp > p){
          state = 1;
        }
        if(temp < p){
          state = -1;
        }
        p = temp;
        target /= 10;

        if(state==1){
          pos = i;
        }
      }
      if(pos==-1) return n;
      int res = 0;
      int ten = 1;
      for (int i = 0; i < pos; i++) {
        res += 9*ten;
        ten *= 10;
      }
      res += (n / ten - 1)*ten;
      return res;
    }
};
