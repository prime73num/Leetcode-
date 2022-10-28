










#include <iostream>
#include <vector>

using namespace std;







class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      vector<int> dis = gas;
      int size = gas.size();
      for (int i = 0; i < gas.size(); i++) {
        dis[i] -= cost[i];
      }
      int pos = 0;
      while (pos < size) {
        int sum = 0;
        printf("%d ", pos);
        bool satisify = true;
        for (int i = pos; i < pos+size; i++) {
          sum += dis[i%size];
          if(sum < 0){
            pos = i+1;
            satisify = false;
            break;
          }
        }
        if(satisify){
          return pos;
        }
      }
      return -1;
    }
};
