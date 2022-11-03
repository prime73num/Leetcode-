















#include <iostream>
#include <vector>

using namespace std;






static vector<vector<int>>* inter;
class Solution {
  private:
    static bool cmp(int i, int j){
      int a = (*inter)[i][0];
      int b = (*inter)[j][0];
      return a < b;
    }
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      inter = &intervals;
      vector<int> idx(intervals.size(), 0);
      for (int i = 0; i < intervals.size(); i++) {
        idx[i] = i;
      }
      std::sort(idx.begin(), idx.end(), cmp);
      vector<vector<int>> res;
      int big_inter[2];
      big_inter[0] = intervals[idx[0]][0];
      big_inter[1] = intervals[idx[0]][0];
      for (int i = 0; i < intervals.size(); i++) {
        int temp_idx = idx[i];
        if(intervals[temp_idx][0] > big_inter[1]){
          res.emplace_back(big_inter, big_inter+2);
          big_inter[0] = intervals[temp_idx][0];
          big_inter[1] = intervals[temp_idx][1];
        } else {
          int temp = intervals[temp_idx][1];
          big_inter[1] = temp > big_inter[1] ? temp:big_inter[1];
        }
      }
      res.emplace_back(big_inter, big_inter+2);
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  return 0;
}
