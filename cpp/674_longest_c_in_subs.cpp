

#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[10001];
    int findLengthOfLCIS(std::vector<int>& nums) {
      dp[0] = 0;
      int res = 0;
      for (int i = 0; i < nums.size(); i++) {
        if(i==0 || nums[i] > nums[i-1]){
          dp[i+1] = dp[i] + 1;
        } else {
          dp[i+1] = 1;
        }
        res = (dp[i+1] > res)? dp[i+1] : res;
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  int cost[] = {1,3,5,4,7};
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  std::cout << sol.findLengthOfLCIS(test) << std::endl;
  return 0;
}
