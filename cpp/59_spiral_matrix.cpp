

#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int> > generateMatrix(int n) {
      std::vector<std::vector<int> > res(n, std::vector<int>(n, 0));
      int direction = 0;
      int x = 0, y = 0;
      for (int i = 1; i <= n*n; i++) {
        res[x][y] = i;
        if(direction==0){
          y++;
          if( x >= 0 && x < n && y >= 0 && y < n ){
            if(res[x][y] == 0){
              continue;
            }
          }
          y--;
          x++;
          direction = 1;
          continue;
        }
        if(direction==1){
          x++;
          if( x >= 0 && x < n && y >= 0 && y < n ){
            if(res[x][y] == 0){
              continue;
            }
          }
          x--;
          y--;
          direction = 2;
          continue;
        }
        if(direction==2){
          y--;
          if( x >= 0 && x < n && y >= 0 && y < n ){
            if(res[x][y] == 0){
              continue;
            }
          }
          y++;
          x--;
          direction = 3;
          continue;
        }
        if(direction==3){
          x--;
          if( x >= 0 && x < n && y >= 0 && y < n ){
            if(res[x][y] == 0){
              continue;
            }
          }
          x++;
          y++;
          direction = 0;
          continue;
        }
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  sol.generateMatrix(3);
  return 0;
}
