
#include <iostream>
#include <vector>


class Solution {
  public:
    int search(std::vector<int>& nums, int target) {
      int start = 0;
      int end = nums.size();
      while (start != end) {
        int mid = (start+end)/2;
        if(nums[mid] == target){
          return mid;
        } else {
          if(nums[mid] > target){
            end = mid;
          } else {
            start = mid + 1;
          }
        }
      }
      return -1;
    }
};
