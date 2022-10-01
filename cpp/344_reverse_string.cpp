







#include <iostream>
#include <vector>


class Solution {
  public:
    void reverseString(std::vector<char>& s) {
      int start = 0;
      int end = s.size()-1;
      while (start < end) {
        std::swap(s[start], s[end]);
        start++;
        end--;
      }
    }
};
