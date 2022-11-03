









#include <iostream>
#include <vector>

using namespace std;






class Solution {
  public:
    vector<int> partitionLabels(string s) {
      int biggest_idx[26] = {0};
      for (int i = 0; i < s.size(); i++) {
        biggest_idx[s[i]-'a'] = i;
      }
      vector<int> res;
      int size = 0;
      int end = 0;
      for (int i = 0; i < s.size(); i++) {
        int temp = biggest_idx[s[i]-'a'];
        end = end > temp ? end:temp;
        size++;
        if(end == i){
          res.push_back(size);
          size = 0;
        }
      }
      return res;
    }
};
