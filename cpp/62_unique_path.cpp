#include <iostream>

class Solution {
public:
    int dp[100][100];
    int uniquePaths(int m, int n) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if( i==0 && j==0 ) {
            dp[0][0] = 1;
          } else {
            int first = (i==0)? 0 : dp[i-1][j];
            int second = (j==0)? 0 : dp[i][j-1];
            dp[i][j] = first + second;
          }
        }
      }
      return dp[m-1][n-1];
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  sol.uniquePaths(3, 7);
  return 0;
}
