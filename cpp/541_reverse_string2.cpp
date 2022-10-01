








#include <iostream>
#include <vector>


class Solution {
  public:
    std::string reverseStr(std::string s, int k) {
      int sum;
      for (int i = 0; i < s.size(); i++) {
        int time = i/k;
        int mod = i%k;
        if( time%2 == 0){
          if(mod == 0){
            int end = i+k-1;
            if( end >= s.size()){
              end = s.size()-1;
            }
            sum = i + end;
          }
          if(i*2 < sum){
            char temp = s[i];
            s[i] = s[sum-i];
            s[sum-i] = temp;
          }
        }
      }
      return s;
    }
};
