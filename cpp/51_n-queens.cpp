












#include <iostream>
#include <vector>
#include <list>

using namespace std;



class Solution {
  struct Pos
  {
    int x;
    int y;
    Pos(int x, int y) :
      x(x), y(y)
    { }
  };
  private:
  vector<vector<Pos>> res;
    bool isconflict(vector<Pos>& coordi, Pos p){
      for (auto& i : coordi) {
        int x = i.x;
        int y = i.y;
        if(x==p.x || y==p.y) return true;
        if(p.y-y == p.x-x) return true;
        if(p.y-y == x-p.x) return true;
      }
      return false;
    }
    void backtrack(vector<Pos>& chessboard, int n, int next_row){
      if(next_row==n){
        res.push_back(chessboard);
        return;
      }
      for (int i = 0; i < n; i++) {
        Pos next_pos(next_row, i);
        if(isconflict(chessboard, next_pos)) continue;
        chessboard.push_back(next_pos);
        backtrack(chessboard, n, next_row+1);
        chessboard.pop_back();
      }
    }
  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ret;
      vector<Pos> chessboard;
      backtrack(chessboard, n, 0);
      for (auto& i: res) {
        vector<string> one_sol;
        for(auto& j: i){
          string row = string(n, '.');
          row[j.y] = 'Q';
          one_sol.push_back(row);
        }
        ret.push_back(one_sol);
      }
      return ret;
    }
};
