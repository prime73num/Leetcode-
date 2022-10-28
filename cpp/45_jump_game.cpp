









#include <iostream>
#include <vector>

using namespace std;







class Solution {
public:
    int jump(vector<int>& nums) {
      int res = 0;
      int size = 1;
      int max_size = 1;
      int p = 0;
      while (p != max_size && p != nums.size())
      {
        if(p==size){
          size = max_size;
          res++;
        }
        int next = p+1+nums[p];
        max_size = next > max_size ? next:max_size;
        p++;
      }
      return res;
    }
};
