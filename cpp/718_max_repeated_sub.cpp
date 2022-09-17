


#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[1001][1001];
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
      int res = 0;
      for (int i = 0; i <= nums1.size(); i++) {
        for (int j = 0; j <= nums2.size(); j++) {
          if(i==0 || j==0){
            dp[i][j] = 0;
          } else {
            if(nums1[i-1] == nums2[j-1]){
              dp[i][j] = dp[i-1][j-1] + 1;
            } else {
              dp[i][j] = 0;
            }
          }
          res = (dp[i][j] > res)? dp[i][j] : res;
        }
      }
      return res;
    }
};
