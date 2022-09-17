

#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
      std::vector<int> res(nums.size(), 0);
      int start = 0;
      int end = nums.size()-1;
      for (int i = nums.size()-1; i >= 0; i--) {
        int first = nums[start] * nums[start];
        int second = nums[end] * nums[end];
        if(first > second){
          res[i] = first;
          start++;
        } else {
          res[i] = second;
          end--;
        }
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  int cost[] = { -4,-1,0,3,10 };
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  std::vector<int> res = sol.sortedSquares(test);
  for (int& i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
