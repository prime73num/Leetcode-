#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
      std::vector<int> min_cost;
      min_cost.push_back(0);
      min_cost.push_back(0);
      for (int i = 2; i <= cost.size(); i++) {
        int one_step_cost = min_cost[i-1] + cost[i-1];
        int two_step_cost = min_cost[i-2] + cost[i-2];
        int min = (one_step_cost < two_step_cost)? one_step_cost : two_step_cost;
        min_cost.push_back(min);
      }
      return min_cost.back();
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  int cost[] = { 1,100,1, 1,1,100,1,1,100,1 };
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  std::cout << sol.minCostClimbingStairs(test) << std::endl;
  return 0;
}
