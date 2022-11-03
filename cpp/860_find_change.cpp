













#include <iostream>
#include <vector>

using namespace std;








class Solution {
  public:
    bool lemonadeChange(vector<int>& bills) {
      int nums[3] = {0};
      for (int i = 0; i < bills.size(); i++) {
        int bill = bills[i];
        if(bill == 20){
          nums[2] ++;
        } else if (bill == 10){
          nums[1]++;
        } else {
          nums[0]++;
        }
        int bill_change = bills[i] - 5;
        int temp;
        temp = nums[2] * 20 > bill_change? bill_change/20 : nums[2];
        nums[2] -= temp;
        bill_change -= temp*20;

        temp = nums[1] * 10 > bill_change? bill_change/10 : nums[1];
        nums[1] -= temp;
        bill_change -= temp*10;

        temp = nums[0] * 5 > bill_change? bill_change/5 : nums[0];
        nums[0] -= temp;
        bill_change -= temp*5;

        if(bill_change != 0) return false;
      }
      return true;
    }
};
