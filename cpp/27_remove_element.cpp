

#include <iostream>
#include <vector>

class Solution {
  public:
    int removeElement(std::vector<int>& nums, int val) {
      int not_equal_elem_size = 0;
      for (int i = 0; i < nums.size(); i++) {
        if(nums[i] != val){
          int temp = nums[i];
          nums[i] = nums[not_equal_elem_size];
          nums[not_equal_elem_size] = temp;
          not_equal_elem_size++;
        }
      }
      return not_equal_elem_size;
    }
};
