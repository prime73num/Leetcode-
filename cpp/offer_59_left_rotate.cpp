







#include <iostream>
#include <vector>

class Solution {
  public:
    std::string reverseLeftWords(std::string s, int n) {
      int point = n;
      int next_start = n;
      for (int i = 0; i < s.size(); i++) {
        printf("%d %d %d\n", i, point, next_start);;
        int temp = s[point];
        s[point] = s[i];
        s[i] = temp;
        if(i == next_start){
          next_start = point;
        }
        point++;
        if(point >= s.size()){
          if(next_start >= s.size())
            break;
          point = next_start;
        }
      }
      return s;
    }
};

int main (int argc, char *argv[])
{
  std::string test = "abcdefg";
  Solution sol;
  std::string res = sol.reverseLeftWords(test, 2);
  printf("%s\n", res.c_str());
  return 0;
}
