









#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  string digits;
  const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
  };
  void travel(vector<string>& res, int end){
    if(end==-1) {
      res.push_back(string());
      return;
    }
    travel(res, end-1);
    int idx = digits[end] - '0';
    int size = res.size();
    for (int i = 0; i<size; i++) {
      string temp = letterMap[idx];
      char c = temp.back();
      temp.pop_back();
      res[i].push_back(c);
      for (auto c : temp) {
        res.push_back(res[i]);
        auto& temp = res[res.size()-1];
        temp[temp.size()-1] = c;
      }
    }
  }
  
public:
    vector<string> letterCombinations(string digits) {
      this->digits = digits;
      vector<string> res;
      if(digits.size()==0) return res;
      travel(res, digits.size()-1);
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  auto res = sol.letterCombinations("23");
  for (auto i: res) {
    for (auto n : i) {
      printf("%c", n);
    }
    printf("\n");
  }
  return 0;
}
