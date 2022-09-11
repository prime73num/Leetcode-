#include <iostream>
#include <vector>


class Solution {
  public:
    bool dp[31][3001];
    int lastStoneWeightII(std::vector<int>& stones) {
      int m = stones.size();
      int n = 0;
      for (int i = 0; i < stones.size(); i++) {
        n += stones[i];
      }
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
          if(i==0){
            dp[i][j] = (j==0)? true: false;
          } else {
            int stone_weight = stones[i-1];
            bool first = false;
            int idx = (stone_weight > j)? stone_weight-j : j - stone_weight;
            first = dp[i-1][idx];
            bool second = false;
            if(stone_weight + j <= n){
              second = dp[i-1][stone_weight+j];
            }
            dp[i][j] = first | second;
          }
        }
      }
      int smallest = 0;
      for (int i = 0; i <= n; i++) {
        if(dp[m][i]){
          smallest = i;
          break;
        }
      }
      return smallest;
    }
};

int main (int argc, char *argv[])
{
  int cost[] = {2,7,4,1,8,1};
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  std::cout << sol.lastStoneWeightII(test) << std::endl;
  return 0;
}
