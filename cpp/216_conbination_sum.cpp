














#include <iostream>
#include <vector>

using namespace std;






class Solution {
  private:
    void tracel(vector<vector<int> >& res, int k, int n, int e){
      int min = 0;
      int max = 0;
      for (int i = 1; i <= k; i++) {
        min += i;
      }
      max = min + k*(e-k);
      if(n > max || n < min) return;

      if(k==0){
        res.push_back(vector<int>());
        return;
      }

      int size = res.size();
      tracel(res, k-1, n-e, e-1);
      for (int i = size; i < res.size(); i++) {
        res[i].push_back(e);
      }
      tracel(res, k, n, e-1);
    }
  public:
    vector<vector<int> > combinationSum3(int k, int n) {
      vector<vector<int> > res;
      tracel(res, k, n, 9);
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  auto res = sol.combinationSum3(3, 9);
  for (auto i: res) {
    for (auto n : i) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
