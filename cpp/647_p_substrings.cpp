
#include <iostream>
#include <vector>


class Solution {
  public:
    bool dp[1001][1001];
    int countSubstrings(std::string s) {
      int res = 0;
      for (int i = s.size()-1; i>=0; i--) {
        for (int j = i; j < s.size(); j++) {
          dp[i][j] = false;
          if(s[i]==s[j]){
            if(j-i <= 1 || dp[i+1][j-1]){
              res++;
              dp[i][j] = true;
            }
          }
        }
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  sol.countSubstrings("aba");
  return 0;
}
