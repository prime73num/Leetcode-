








#include <iostream>
#include <vector>
#include <stack>




class Solution {
  public:
    bool isValid(std::string s) {
      std::stack<char> res;
      for (char i : s) {
        if(i == ']'){
          if(res.empty() || res.top() != '['){
            return false;
          }
          res.pop();
        } else if (i == '}') {
          if(res.empty() || res.top() != '{'){
            return false;
          }
          res.pop();
        } else if(i == ')'){
          if(res.empty() || res.top() != '('){
            return false;
          }
          res.pop();
        } else {
          res.push(i);
        }
      }
      return res.empty();
    }
};
