


#include <iostream>
#include <vector>



class Solution {
  public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
      int min_times[26] = {0};
      bool first = true;
      for(std::string& i: words){
        int hash_map[26] = {0};
        for(char c: i){
          hash_map[c-'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
          if(first || hash_map[i] < min_times[i]){
            min_times[i] = hash_map[i];
          }
        }
        first = false;
      }
      std::vector<std::string> res;
      int point = 0;
      while (point!=26) {
        if(min_times[point] != 0){
          printf("%d ", min_times[point]);
          std::string temp;
          temp.push_back(point+'a');
          res.push_back(temp);
          min_times[point]--;
        } else {
          point++;
        }
      }
      return res;
    }
};
