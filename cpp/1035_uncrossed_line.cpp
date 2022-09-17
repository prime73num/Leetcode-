

#include <iostream>
#include <vector>


class Solution {
  public:
    int dp[501][501];
    int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
      for (int i = 0; i <= nums1.size(); i++) {
        for (int j = 0; j <= nums2.size(); j++) {
          if(i==0 || j==0) {
            dp[i][j] = 0;
          } else {
            int f = nums1[i-1];
            int s = nums2[j-1];
            if (f==s) {
              dp[i][j] = dp[i-1][j-1] + 1;
            } else {
              int first = dp[i-1][j];
              int second = dp[i][j-1];
              dp[i][j] = first>second ? first:second;
            }
          }
        }
      }
      return dp[nums1.size()][nums2.size()];

    }
};
