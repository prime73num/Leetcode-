








#include <iostream>
#include <vector>




class Solution {
  public:
    int strStr(std::string haystack, std::string needle) {
      std::vector<int> kmp(needle.size(), 0);
      for (int i = 1; i < needle.size(); i++) {
        int start = i-1;
        int res = 0;
        while (start >= 0) {
          start = kmp[start];
          if(needle[start] == needle[i]){
            res = start + 1;
            break;
          }
          start--;
        }
        kmp[i] = res;
      }
      int match = 0;
      int point = 0;
      while (point < haystack.size()) {
        if(haystack[point] == needle[match]){
          match++;
          point++;
        } else {
          if(match==0){
            point++;
          } else {
            match = kmp[match-1];
          }
        }
        if(match==needle.size()){
          return point-match;
        }
      }
      return -1;
    }
    bool repeatedSubstringPattern(std::string s) {
      std::string target(s, 1, s.size()-1);
      target += s;
      target.resize(target.size()-1);
      if(strStr(target, s) == -1){
        return false;
      }
      return true;
    }
};
