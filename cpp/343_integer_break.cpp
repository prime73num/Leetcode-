#include <iostream>
#include <vector>




class Solution {
  public:
    int dp[60][60];
    int integerBreak(int n){
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          int first = 0;
          if(i > j){
            first = dp[i-j][j] * j;
          } else if (i==j) {
            first = j;
          }
          int second = dp[i][j-1];
          if(j==1){
            second = 0;
          }
          dp[i][j] = (first<second)? second : first;
          if(i==1 && j==1){
            dp[i][j] = 1;
          }
        }
      }
      int res = 0;
      for (int i = 1; i < n; i++) {
        if(dp[n][i] > res) {
          res = dp[n][i];
        }
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  std::cout << sol.integerBreak(10) << std::endl;
  return 0;
}
