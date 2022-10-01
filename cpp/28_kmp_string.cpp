









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
};

int main (int argc, char *argv[])
{
  std::string test = "ll";
  Solution sol;
  int res = sol.strStr("a", "a");
  printf("%d\n", res);
  return 0;
}
