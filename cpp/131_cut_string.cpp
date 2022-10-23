


















#include <iostream>
#include <vector>

using namespace std;




class Solution {
  private:
    bool isPalindrome(const string& s, int start, int end) {
      for (int i = start, j = end; i < j; i++, j--) {
        if (s[i] != s[j]) {
          return false;
        }
      }
      return true;
    }
    void travel(vector<vector<string>>& res, string& s, int end){
      if(end < 0){
        res.push_back(vector<string>());
        return;
      }
      for (int i = end; i >= 0; i--) {
        if(!isPalindrome(s, i, end)) continue;
        int size = res.size();
        travel(res, s, i-1);
        string temp = string(s, i, end-i+1);
        for (int j = size; j < res.size(); j++) {
          res[j].push_back(temp);
        }
      }
    }
  public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      travel(res, s, s.size()-1);
      return res;
    }
};
