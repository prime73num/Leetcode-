


#include <iostream>
#include <vector>
#include <unordered_set>



class Solution {
  public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::unordered_set<int> set1;
      std::vector<int> res;
      for (int i = 0; i < nums1.size(); i++) {
        set1.insert(nums1[i]);
      }
      for (int i = 0; i < nums2.size(); i++) {
        if(set1.erase(nums2[i])){
          res.push_back(nums2[i]);
        }
      }
      return res;
    }
};
