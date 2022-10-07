





#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minsteps(string s) {
      vector<int> dp(s.size(), 0);
      vector<int> dp_from(s.size(), 0);
      for (int i = 0; i < s.size(); i++) {
        int min = INT_MAX;
        for (int j = 0; j < i; j++) {
          
        }
      }
    }
};
int main (int argc, char *argv[])
{
  Solution sol;
  return 0;
}
