

#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[1001][1001];
    int longestPalindromeSubseq(std::string s) {
      std::string text1(s);
      std::string text2(s);
      std::reverse(text2.begin(), text2.end());
      for (int i = 0; i <= text1.size(); i++) {
        for (int j = 0; j <= text2.size(); j++) {
          if(i==0 || j==0) {
            dp[i][j] = 0;
          } else {
            char f = text1[i-1];
            char s = text2[j-1];
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
      return dp[text1.size()][text2.size()];
    }
};
