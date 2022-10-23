














#include <iostream>
#include <vector>

using namespace std;






class Solution {
  private:
    void travel(vector<vector<int> >& res, vector<int>& candidates, int end, int target){
      if(target<0) return;
      if(target==0){
        res.push_back(vector<int>());
      }
      int prev = -1;
      for (int i = end; i>=0; i--) {
        if(candidates[i] == prev){
          continue;
        }
        prev = candidates[i];
        int size = res.size();
        travel(res, candidates, i-1 , target - candidates[i]);
        for (int j = size; j < res.size(); j++) {
          res[j].push_back(candidates[i]);
        }
      }
    }
  public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int> > res;
      std::sort(candidates.begin(), candidates.end());
      travel(res, candidates, candidates.size()-1, target);
      return res;
    }
};

bool ord(int a, int b){
  return a==b;
}

int main (int argc, char *argv[])
{
  int temp[] = { 1,1,1,7,6,1,5 };
  vector<int> can(temp, temp+7);
  for (int i = 0; i < can.size(); i++) {
    printf("%d ", can[i]);
  }
  printf("\n");
  auto last = std::unique(can.begin(), can.end(), ord);
  can.erase(last, can.end());
  for (int i = 0; i < can.size(); i++) {
    printf("%d ", can[i]);
  }
  printf("\n");
  Solution sol;
  auto res = sol.combinationSum2(can, 8);
  for (auto i: res) {
    for (auto n : i) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
