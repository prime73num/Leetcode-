



















#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
  private:
    vector<vector<int>> result;
    void backtrack(vector<int>& res, int next, vector<int>& nums){
      if(res.size() > 1){
        result.push_back(res);
      }
      unordered_set<int> num_set;
      for (int i = next; i < nums.size(); i++) {
        if ((!res.empty() && nums[i] < res.back())
            || num_set.find(nums[i]) != num_set.end()) {
          continue;
        }
        num_set.insert(nums[i]);
        res.push_back(nums[i]);
        backtrack(res, i+1, nums);
        res.pop_back();
      }
    }
  public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      vector<int> res;
      backtrack(res, 0, nums);
      return result;
    }
};
