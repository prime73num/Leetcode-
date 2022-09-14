
#include <iostream>
#include <vector>

class Solution {
  public:
    int coinChange(std::vector<int>& coins, int amount) {
      std::vector<int> dp(amount+1, 0);
      for (int i = 1; i <= amount; i++) {
        int smallest = INT_MAX;
        for (int j = 0; j < coins.size(); j++) {
          if (i >= coins[j]) {
            if(dp[i-coins[j]] != INT_MAX){
              int coin_num = dp[i - coins[j]] + 1;
              if(coin_num < smallest){
                smallest = coin_num;
              }
            }
          }
        }
        dp[i] = smallest;
      }
      if(dp[amount] == INT_MAX){
        return -1;
      }
      return dp[amount];
    }
};
