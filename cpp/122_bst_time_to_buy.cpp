













#include <iostream>
#include <vector>

using namespace std;


class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int sum = 0;
      int state = 0;
      int prev = INT_MAX;
      for (int i = 0; i < prices.size(); i++) {
        int cur = prices[i];
        if(i==prices.size()-1){
          if(cur > prev){
            sum += cur - prev;
          }
          prev = cur;
          continue;
        }
        int next = prices[i+1];
        if(cur==next) continue;
        int next_state = next > cur ? 1 : -1;
        if(state != next_state){
          if(cur > prev){
            sum += cur - prev;
          }
          prev = cur;
          state = next_state;
        }
      }
      return sum;;
    }
};
