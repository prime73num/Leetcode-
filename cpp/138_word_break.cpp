

#include <iostream>
#include <vector>

class Solution {
  public:
    bool dp[301];
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
      dp[0] = true;
      for (int i = 0; i < s.size(); i++) {
        bool can = false;
        for (int j = 0; j <= i; j++) {
          std::string temp(s, j, i+1-j);
          if(std::find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end() && dp[j]){
            can = true;
            break;
          }
        }
        dp[i+1] = can;
      }
      return dp[s.size()];
    }
};

int main (int argc, char *argv[])
{
  std::string tmp[] = {"apple", "pen"};
  std::vector<std::string> test = std::vector<std::string>(std::begin(tmp), std::end(tmp));
  Solution sol;
  std::cout<< sol.wordBreak("applepenapple", test) << std::endl;
  return 0;
}
