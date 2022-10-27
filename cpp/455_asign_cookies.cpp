






#include <iostream>
#include <vector>

using namespace std;






class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      std::sort(g.begin(), g.end());
      std::sort(s.begin(), s.end());
      int p = g.size() - 1;
      int q = s.size() - 1;
      int sum = 0;

      while (q >= 0 && p >= 0)
      {
        if( g[p] <= s[q] ){
          p--;
          q--;
          sum++;
        } else {
          p--;
        }
      }
      return sum;
    }
};
