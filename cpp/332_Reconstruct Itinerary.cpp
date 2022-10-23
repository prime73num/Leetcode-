







#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;




class Solution {
  struct Cmp
  {
    bool operator() (vector<string> a, vector<string> b){
      return a[1] < b[1];
    }
  };
  private:
    unordered_map<string, vector<int>> ticket_map;
    void backtrack(vector<string>& res, string begin, vector<vector<string>>& tickets){
      auto const& next = ticket_map[begin];
      int size = res.size();
      for (auto& idx: next) {
        if(tickets[idx].empty()) continue;
        string next_pos = tickets[idx][1];
        res.push_back(next_pos);
        vector<string> temp = tickets[idx];
        tickets[idx] = vector<string>();
        backtrack(res, next_pos, tickets);
        tickets[idx] = temp;
        if(res.size()==tickets.size()+1) break;
        res.pop_back();
      }
    }
  public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      Cmp cmp;
      std::sort(tickets.begin(), tickets.end(), cmp);
      for (int i = 0; i < tickets.size(); i++) {
        string src = tickets[i][0];
        if(ticket_map.count(src) == 0){
          ticket_map[src] = vector<int>();
        }
        ticket_map[src].push_back(i);
      }
      vector<string> res;
      res.push_back("JFK");
      backtrack(res, "JFK", tickets);
      return res;
    }
};
