















#include <iostream>
#include <vector>

using namespace std;



class Solution {
  private:
    bool backtrack(vector<vector<char>>& board, int next_pos){
      if(next_pos==81) return true;
      int x = next_pos/9;
      int y = next_pos%9;
      if(board[x][y] != '.') return backtrack(board, next_pos+1);
      vector<bool> check(10, false);
      int cx = x/3;
      int cy = y/3;
      cx = 3*cx + 1;
      cy = 3*cy + 1;
      for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
          char temp = board[cx+i][cy+j];
          if(temp != '.'){
            int idx = temp -'0';
            check[idx] = true;
          }
        }
      }
      for (int i = 0; i < 9; i++) {
        char temp = board[x][i];
        if(temp != '.'){
          int idx = temp -'0';
          check[idx] = true;
        }
      }
      for (int i = 0; i < 9; i++) {
        char temp = board[i][y];
        if(temp != '.'){
          int idx = temp -'0';
          check[idx] = true;
        }
      }
      for (int i = 1; i < 10; i++) {
        if(check[i]) continue;
        board[x][y] = '0' + i;
        if(backtrack(board, next_pos+1)) return true;
      }
      board[x][y] = '.';
      return false;
    }
  public:
    void solveSudoku(vector<vector<char>>& board) {
      backtrack(board, 0);
    }
};
