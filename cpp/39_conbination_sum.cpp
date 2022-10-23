


















#include <iostream>
#include <vector>

using namespace std;





class Solution {
  private:
    void travel(vector<vector<int>>& res, vector<int>& candidates, int end, int target){
      if(target<0) return;
      if(target==0){
        res.push_back(vector<int>());
      }
      for (int i = end; i>=0; i--) {
        int size = res.size();
        travel(res, candidates, i , target - candidates[i]);
        for (int j = size; j < res.size(); j++) {
          res[j].push_back(candidates[i]);
        }
      }
    }
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      int end= candidates.size()-1;
      travel(res, candidates, end, target);
      return res;
    }
};
