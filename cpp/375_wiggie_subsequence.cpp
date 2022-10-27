










#include <iostream>
#include <vector>

using namespace std;




class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int res = 0;
      int state = 0;
      for (int i = 0; i < nums.size(); i++) {
        if(i==nums.size()-1){
          res++;
          continue;
        }
        int next = nums[i+1];
        int cur = nums[i];
        if(cur==next) continue;
        int next_state = next > cur ? 1 : -1;
        if(state != next_state){
          res++;
          state = next_state;
        }
      }
      return res;;
    }
};
