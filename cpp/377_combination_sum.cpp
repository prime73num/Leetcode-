
#include <iostream>
#include <vector>


class Solution {
  public:
    int dp[1001];
    int combinationSum4(std::vector<int>& nums, int target) {
      dp[0] = 1;
      for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
          if(i >= nums[j] && dp[i] < INT_MAX - dp[i-nums[j]]){
            dp[i] += dp[i - nums[j]];
          }
        }
      }
      return dp[target];
    }
};
