#include <iostream>
#include <vector>

class Solution {
  public:
    int dp[20];
    int numTrees(int n) {
      dp[0] = 1;
      for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
          sum += dp[j-1] * dp[i-j];
        }
        dp[i] = sum;
      }
      return dp[n];
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  sol.numTrees(3);
  return 0;
}


