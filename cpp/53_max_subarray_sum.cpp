


#include <iostream>
#include <vector>


class Solution {
  public:
    int maxSubArray(std::vector<int>& nums) {
      int max = INT_MIN;
      int sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        if(sum+nums[i] > 0){
          sum+=nums[i];
          max = sum > max ? sum:max;
        } else {
          sum = 0;
          max = nums[i] > max ? nums[i]:max;
        }
      }
      return max;
    }
    int soltoin1(std::vector<int>& nums) {
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
