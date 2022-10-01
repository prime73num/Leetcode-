


#include <iostream>
#include <vector>


class Solution {
  public:
    std::string replaceSpace(std::string s){
      int sum = 0;
      for (auto c : s) {
        if(c == ' '){
          sum++;
        }
      }
      int point1 = s.size()-1;
      s.resize(s.size()+2*sum);
      int point2 = s.size()-1;
      while(point1 >= 0){
        if(s[point1] == ' '){
          s[point2--] = '0';
          s[point2--] = '2';
          s[point2--] = '%';
        } else {
          s[point2--] = s[point1];
        }
        point1--;
      }
      return s;
    }
};
