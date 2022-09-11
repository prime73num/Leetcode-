#include <iostream>
#include <vector>


class Solution {
  public:
    bool dp[201][10001];
    bool canPartition(std::vector<int>& nums) {
      int half = 0;
      for(int i =0; i<nums.size(); i++){
        half += nums[i];
      }
      if (half % 2 == 1)
        return false;
      half = half/2;
      for (int i = 0; i <= nums.size(); i++) {
        for (int j = 0; j <= half; j++) {
          if (i==0) {
            dp[i][j] = (j==0)? true : false;
          } else {
            bool first = false;
            if (j >= nums[i-1]) {
              first = dp[i-1][j - nums[i-1]];
            }
            bool second = dp[i-1][j];
            dp[i][j] = first | second;
          }
        }
      }
      return dp[nums.size()-1][half];
    }
};

int main (int argc, char *argv[])
{
  int cost[] = {1,5,5,11};
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  if(sol.canPartition(test)){
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}
