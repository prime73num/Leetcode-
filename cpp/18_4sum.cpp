







#include <iostream>
#include <vector>
#include <unordered_map>



class Solution {
  public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int[2] > set;
      for (int i = nums.size()-1; i >= 0; i--) {
        if(set.find(nums[i]) != set.end()){
          set[nums[i]][0]++;
        } else {
          set[nums[i]][0] = 1;
        }
      }
      int index = 0;
      for (auto& it : set) {
        it.second[1] = index;
        index++;
      }
      std::vector<std::vector<int> > res;
      for (auto iter_i = set.begin(); iter_i != set.end(); ++iter_i) {
        iter_i->second[0]--;
        for (auto iter_j = iter_i; iter_j != set.end(); ++iter_j) {
          if(iter_j->second[0] != 0){
            iter_j->second[0]--;

            for (auto iter_k = iter_j; iter_k != set.end(); ++iter_k) {
              if(iter_k->second[0] != 0){
                iter_k->second[0]--;

                long big_sum = (long) target - iter_i->first - iter_j->first - iter_k->first;
                if(big_sum > INT_MAX || big_sum < INT_MIN){
                  iter_k->second[0]++;
                  continue;
                }
                int sum = big_sum;
                auto it = set.find(sum);
                if(it != set.end() && it->second[1] >= iter_k->second[1] && it->second[0]!=0) {
                  int temp[] = {iter_i->first, iter_j->first, iter_k->first, sum};
                  res.emplace_back(temp, temp+4);
                }

                iter_k->second[0]++;
              }
            }

            iter_j->second[0]++;
          }
        }
        iter_i->second[0]++;
      }
      return res;
    }
};
