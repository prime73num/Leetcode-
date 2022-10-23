


















#include <iostream>
#include <vector>

using namespace std;



class Solution {
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
      vector<vector<int> > res;
      int end = 0;
      res.push_back(vector<int>());
      while (end != nums.size()) {
        int size = res.size();
        for (int i = 0; i < size; i++) {
          vector<int> temp = res[i];
          temp.push_back(nums[end]);
          res.push_back(temp);
        }
        end++;
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  int temp[] = {1, 2, 3};
  vector<int> can(temp, temp+3);
  Solution sol;
  auto res = sol.subsets(can);
  for (auto i: res) {
    for (auto n : i) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
