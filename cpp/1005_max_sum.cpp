



















#include <iostream>
#include <vector>

using namespace std;




class Solution {
  public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
      std::sort(nums.begin(), nums.end());
      int sum = 0;
      int min_pos = 0;
      while (k!=0) {
        printf("%d ", nums[min_pos]);
        if(nums[min_pos] < 0){
          nums[min_pos] = -nums[min_pos];
          k--;
        } else {
          if(k%2 == 1){
            nums[min_pos] = -nums[min_pos];
          }
          k = 0;
        }
        int next = min_pos+1;
        if(next == nums.size()) continue;
        if(nums[next] >= 0){
          min_pos = nums[min_pos] < nums[next] ? min_pos:next;
        } else {
          min_pos = next;
        }
      }
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
      }
      return sum;
    }
};
