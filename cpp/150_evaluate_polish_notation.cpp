











#include <iostream>
#include <vector>
#include <stack>

class Solution {
  public:
    int evalRPN(std::vector<std::string>& tokens) {
      std::stack<int> res;
      for (const auto& c : tokens) {
        if(c == "+" || c == "-" || c == "*" || c == "/"){
          int second = res.top();
          res.pop();
          int first = res.top();
          res.pop();
          int result;
          if(c == "+"){
            result = first + second;
          } else if(c == "-"){
            result = first - second;
          } else if(c == "*"){
            result = (long) first * (long) second;
          } else if(c == "/"){
            result = first / second;
          }
          res.push(result);
        } else {
          res.push(std::stoi(c));
        }
      }
      return res.top();
    }
};
