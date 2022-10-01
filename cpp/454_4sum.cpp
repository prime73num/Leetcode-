



#include <iostream>
#include <vector>
#include <unordered_map>






class Solution {
  public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
      std::unordered_map<int, int> set1;
      std::unordered_map<int, int> set2;
      for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
          int sum = nums1[i] + nums2[j];
          if(set1.find(sum) == set1.end()){
            set1[sum] = 1;
          } else {
            set1[sum] += 1;
          }
        }
      }
      for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j < nums4.size(); j++) {
          int sum = nums3[i] + nums4[j];
          if(set2.find(sum) == set2.end()){
            set2[sum] = 1;
          } else {
            set2[sum] += 1;
          }
        }
      }
      int res = 0;
      for (auto i: set1) {
        int temp = -i.first;
        auto it = set2.find(temp);
        if(it != set2.end()){
          res += i.second * it->second;
        }
      }
      return res;
    }
};
