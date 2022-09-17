

#include <iostream>
#include <vector>




class Solution {
  public:
    int dp[2502];
    int lengthOfLIS(std::vector<int>& nums) {
      dp[0] = 0;
      int longest = 0;
      for (int i = 0; i < nums.size(); i++) {
        int res = 0;
        for (int j = 0; j < i; j++) {
          if(nums[j] < nums[i]){
            int temp = dp[j+1];
            if(temp > res)
              res = temp;
          }
        }
        dp[i+1] = res+1;
        if(dp[i+1] > longest){
          longest = dp[i+1];
        }
      }
      return longest;
    }
};

int main (int argc, char *argv[])
{
  int cost[] = {0,1,0,1,2,3};
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  int res = sol.lengthOfLIS(test);
  std::cout << res << std::endl;
  return 0;
}
