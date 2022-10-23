


















#include <iostream>
#include <vector>

using namespace std;








class Solution {
  private:
    void travel(int n, int k, vector<vector<int> >& res){
      if(k==0){
        res.push_back(vector<int>());
        return;
      }
      int size = res.size();
      travel(n-1, k-1, res);
      for (int i = size; i<res.size(); i++) {
        res[i].push_back(n);
      }
      if(n > k){
        travel(n-1, k, res);
      }
    }
  public:
    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > res;
      travel(n, k, res);
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  auto res = sol.combine(4, 2);
  for (auto i: res) {
    for (auto n : i) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
