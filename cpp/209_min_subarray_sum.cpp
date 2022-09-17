



#include <iostream>
#include <vector>






class Solution {
  public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
      int end = 0;
      int sum = 0;
      int min = INT_MAX;
      for (int i = 0; i < nums.size(); i++) {
        if( i!= 0 ){
          sum -= nums[i-1];
        }
        while(end < nums.size()){
          if(sum >= target)
            break;
          sum += nums[end];
          end++;
        }
        if(sum >= target){
          if(min > end-i){
            min = end-i;
          }
        }
      }
      if(min == INT_MAX){
        return 0;
      }
      return min;
    }
};

int main (int argc, char *argv[])
{
  int cost[] = { 10,5,13,4,8,4,5,11,14,9,16,10,20,8 };
  std::vector<int> test = std::vector<int>(std::begin(cost), std::end(cost));
  Solution sol;
  sol.minSubArrayLen(80, test);
  return 0;
}
