



















#include <iostream>
#include <vector>

using namespace std;


class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int> > res;
      std::sort(nums.begin(), nums.end());
      int end = 0;
      res.push_back(vector<int>());
      while (end != nums.size()) {
        int begin = 0;
        int size = res.size();
        while(true) {
          for (int i = begin; i < size; i++) {
            vector<int> temp = res[i];
            temp.push_back(nums[end]);
            res.push_back(temp);
          }
          begin = size;
          size = res.size();
          end++;
          if(end == nums.size() || nums[end] != nums[end-1]) break;
        }
      }
      return res;
    }
};
