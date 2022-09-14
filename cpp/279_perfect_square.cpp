
#include <iostream>
#include <vector>



class Solution {
  public:
    int numSquares(int n) {
      std::vector<int> dp(n+1, 0);
      for (int i = 1; i <= n; i++) {
        int smallest = INT_MAX;
        for (int j = 1; j*j <= i; j++) {
          if(dp[i - j*j] != INT_MAX){
            int coin_num = dp[i - j*j] + 1;
            if(coin_num < smallest){
              smallest = coin_num;
            }
          }
        }
        dp[i] = smallest;
      }
      if(dp[n] == INT_MAX){
        return -1;
      }
      return dp[n];
    }
};
