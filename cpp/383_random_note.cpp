




#include <iostream>
#include <vector>




class Solution {
  public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
      int hash_map[26] = {0};
      for (auto i: ransomNote) {
        hash_map[i-'a'] += 1;
      }
      for (auto i: magazine) {
        hash_map[i-'a'] -= 1;
      }
      for (int i = 0; i < 26; i++) {
        if(hash_map[i] > 0){
          return false;
        }
      }
      return true;
    }
};
