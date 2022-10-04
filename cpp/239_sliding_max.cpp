











#include <iostream>
#include <vector>
#include <queue>

class Solution {
  public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
      std::deque<int> q;
      std::vector<int> res;
      for (int i = 0; i < k; i++) {
        while(!q.empty() && q.back() < nums[i]){
          q.pop_back();
        }
        q.push_back(nums[i]);
      }
      res.push_back(q.front());
      for (int i = k; i < nums.size(); i++) {
        if(q.front() == nums[i-k]){
          q.pop_front();
        }
        while(!q.empty() && q.back() < nums[i]){
          q.pop_back();
        }
        q.push_back(nums[i]);
        res.push_back(q.front());
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  return 0;
}
