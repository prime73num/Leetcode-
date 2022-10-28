









#include <iostream>
#include <vector>

using namespace std;






class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int size = 1;
      int p = 0;
      while (p != size && p != nums.size())
      {
        int next = p+1+nums[p];
        size = next > size ? next:size;
        p++;
      }
      return size>=nums.size();
    }
};
