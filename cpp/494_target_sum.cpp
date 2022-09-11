
#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[21][1001];
    int findTargetSumWays(std::vector<int>& nums, int target) {
      int m = nums.size();
      int n = 0;
      for (int i = 0; i < nums.size(); i++) {
        n += nums[i];
      }
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          if(i==0){
            dp[i][j] = (j==0)? 1: 0;
          } else {
            int stone_weight = nums[i-1];
            int first = 0;
            int idx = (stone_weight > j)? stone_weight-j : j - stone_weight;
            first = dp[i-1][idx];
            int second = 0;
            if(stone_weight + j <= n){
              second = dp[i-1][stone_weight+j];
            }
            dp[i][j] = first + second;
          }
        }
      }
      if (target < 0) {
        target = -target;
      }
      return dp[m][target];
    }
};
