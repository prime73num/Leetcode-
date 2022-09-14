
#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[101];
    int rob(std::vector<int>& nums) {
      dp[0] = 0;
      for (int i = 1; i <= nums.size(); i++) {
        int first = dp[i-1];
        int second = nums[i-1];
        if(i>=2){
          second += dp[i-2];
        }
        dp[i] = (first > second)? first : second;
      }
      return dp[nums.size()];
    }
};
