


#include <iostream>
#include <vector>


class Solution {
  public:
    int maxSubArray(std::vector<int>& nums) {
      std::vector<int> dp(nums.size()+1, 0);
      dp[0] = 0;
      int biggest = INT_MIN;
      for (int i = 1; i <= nums.size(); i++) {
        dp[i] = (dp[i-1] > 0) ? dp[i-1]+nums[i-1] : nums[i-1];
        if(dp[i] > biggest){
          biggest = dp[i];
        }
      }
      return biggest;
    }
};
