
#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[101];
    int rob(std::vector<int>& nums) {
      if (nums.size()==1) {
        return nums[0];
      }
      dp[0] = 0;
      for (int i = 1; i <= nums.size()-1; i++) {
        int first = dp[i-1];
        int second = nums[i-1];
        if(i>=2){
          second += dp[i-2];
        }
        dp[i] = (first > second)? first : second;
      }
      int first = dp[nums.size()-1];
      dp[0] = 0;
      for (int i = 1; i <= nums.size()-1; i++) {
        int first = dp[i-1];
        int second = nums[i];
        if(i>=2){
          second += dp[i-2];
        }
        dp[i] = (first > second)? first : second;
      }
      int second = dp[nums.size()-1];
      if(second > first){
        return second;
      }
      return first;
    }
};
