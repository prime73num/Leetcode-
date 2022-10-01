




#include <iostream>
#include <vector>
#include <unordered_set>


class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_set<int> set(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        if(set.find(target-nums[i]) != set.end()){
          std::vector<int> res;
          res.push_back(i);
          for (int j = i+1; j < nums.size(); j++) {
            if(nums[j] == target - nums[i]){
              res.push_back(j);
              return res;
            }
          }
        }
      }
      return std::vector<int>();
    }
};
