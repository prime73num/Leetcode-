#include <iostream>
#include <vector>


class Solution {
  public:
    int dp[601][101][101];
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
      for (int i = 0; i <= strs.size(); i++) {
        for (int j = 0; j <= m; j++) {
          for (int k = 0; k <= n; k++) {
            if(i==0){
              dp[i][j][k] = 0;
            } else {
              int smallest = dp[i-1][j][k];
              int ones = std::count(strs[i-1].begin(), strs[i-1].end(), '1');
              int zeros = std::count(strs[i-1].begin(), strs[i-1].end(), '0');
              if (j >= zeros && k >= ones) {
                int second = dp[i-1][j - zeros][k - ones] + 1;
                if(second < smallest){
                  smallest = second;
                }
              }
              dp[i][j][k] = smallest;
            }
          }
        }
      }
      return dp[strs.size()][m][n];
    }
};

int main (int argc, char *argv[])
{
  std::cout << "test" << std::endl;
  std::string cost[] = { std::string("10"), std::string("0001"), std::string("111001"), std::string("1"), std::string("0") };
  std::vector<std::string> test = std::vector<std::string>(std::begin(cost), std::end(cost));
  int ans = 0;
  Solution sol;
  // int ans = sol.findMaxForm(test, 5, 3);
  std::cout << ans << std::endl;
  return 0;
}
