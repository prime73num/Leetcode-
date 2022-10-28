















#include <iostream>
#include <vector>

using namespace std;








class Solution {
  public:
    int candy(vector<int>& ratings) {
      vector<int> candy = vector<int>(ratings.size(), 0);
      candy[0] = 1;
      for (int i = 1; i < candy.size(); i++) {
        if(ratings[i] > ratings[i-1]){
          candy[i] = candy[i-1] + 1;
        } else {
          candy[i] = 1;
        }
      }
      for (int i = candy.size()-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]){
          int temp = candy[i+1] + 1;
          candy[i] = temp > candy[i] ? temp:candy[i];
        }
      }
      int sum = 0;
      for (int i = 0; i < candy.size(); i++) {
        printf("%d ", candy[i]);
        sum += candy[i];
      }
      return sum;
    }
};
