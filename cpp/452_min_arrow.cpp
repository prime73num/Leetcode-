















#include <iostream>
#include <vector>

using namespace std;










class Solution {
  public:
    static bool cmp(vector<int>& a, vector<int>& b){
      return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
      std::sort(points.begin(), points.end(), cmp);
      int res = 0;
      int l = points[0][0];
      int r = points[0][1];
      for (int i = 0; i < points.size(); i++) {
        int temp_l = points[i][0];
        int temp_r = points[i][1];
        if(temp_l > r){
          res++;
          l = temp_l;
          r = temp_r;
        } else {
          l = temp_l > l ? temp_l : l;
          r = temp_r < r ? temp_r : r;
        }
      }
      return res+1;
    }
};
