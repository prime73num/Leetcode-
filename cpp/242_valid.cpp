

#include <iostream>
#include <vector>


class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
      int hash_map[26] = {0};
      for (char i : s) {
        hash_map[i-'a'] += 1;
      }
      for (char i : t) {
        hash_map[i-'a'] -= 1;
      }
      for (int i = 0; i < 26; i++) {
        if(hash_map[i] != 0){
          return false;
        }
      }
      return true;
    }
};
