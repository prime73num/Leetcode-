#include <iostream>
#include <vector>

class Solution {
public:
  int dp[100][100];
  int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[0][0] = 1;
        } else {
          int first = (i == 0) ? 0 : dp[i - 1][j];
          int second = (j == 0) ? 0 : dp[i][j - 1];
          dp[i][j] = first + second;
        }
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  return 0;
}
