








#include <iostream>
#include <vector>


class Solution {
  public:
    void reverseString(std::string& s, int b, int e) {
      int start = b;
      int end = e;
      while (start < end) {
        int temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
      }
    }
    std::string reverseWords(std::string s) {
      int p=0;
      for (int i = 0; i < s.size(); i++) {
        if(s[i] == ' ' && (i==0 || s[i-1] == ' ')){
          continue;
        }
        s[p] = s[i];
        p++;
      }
      if(s[p-1] == ' ')
        p--;
      s.resize(p);
      reverseString(s, 0, s.size()-1);
      int begin = 0;
      int point = 0;
      while (point < s.size()) {
        if(point==s.size()-1 || s[point+1] == ' '){
          reverseString(s, begin, point);
          begin = point+2;
        }
        point++;
      }
      return s;
    }
};

int main (int argc, char *argv[])
{
  std::string test = "  hello world   ";
  Solution sol;
  auto res = sol.reverseWords(test);
  printf("%s\n", test.c_str());
  printf("%s\n", res.c_str());
  return 0;
}
