













#include <iostream>
#include <vector>

using namespace std;











class Solution {
  public:
    static bool cmp(vector<int>& a, vector<int>& b){
      return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      std::sort(intervals.begin(), intervals.end(), cmp);
      int sum = 0;
      int end = INT_MIN;
      for (int i = 0; i < intervals.size(); i++) {
        if(intervals[i][0] >= end){
          end = intervals[i][1];
        } else {
          sum++;
        }
      }
      return sum;
    }
};
