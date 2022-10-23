















#include <iostream>
#include <vector>

using namespace std;




class Solution {
  private:
    void travel(vector<string>& res, string s, int end, int num){
      if(end < 0 && num==0){
        res.push_back(string());
        return;
      }
      if(end < 0 || num <= 0) return;
      int min_len = end+1 < 3 ? end+1 : 3;
      for (int i = 1; i <= min_len; i++) {
        string temp = string(s, end-i+1, i);
        if(temp.size() != 1 && temp[0]=='0') continue;
        int part = stoi(temp);
        if(part < 0 || part > 255){
          continue;
        }
        int size = res.size();
        travel(res, s, end-i, num-1);
        for (int j = size; j < res.size(); j++) {
          res[j] += temp;
          res[j] += ".";
        }
      }
    }
  public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      travel(res, s, s.size()-1, 4);
      for (auto& i : res) {
        i.pop_back();
      }
      return res;
    }
};
