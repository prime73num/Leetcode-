








#include <iostream>
#include <vector>
#include <stack>

class Solution {
  public:
    std::string removeDuplicates(std::string s) {
      std::stack<char> res;
      for (int i = s.size()-1; i>=0; i--) {
        char c = s[i];
        if(!res.empty() && res.top() == c){
          res.pop();
        } else {
          res.push(c);
        }
      }
      std::string ret;
      while (!res.empty()) {
        ret += res.top();
        res.pop();
      }
      return ret;
    }
};
