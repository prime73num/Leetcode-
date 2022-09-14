
#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int rob(TreeNode* root) {
      TreeNode point = TreeNode(0, root, nullptr);
      TreeNode* ptr = &point;
      std::vector<TreeNode*> val;
      std::vector<int> parent;
      int idx = -1;
      while (true) {
        if(ptr->left != nullptr){
          val.push_back(ptr->left);
          parent.push_back(idx);
        }
        if(ptr->right != nullptr){
          val.push_back(ptr->right);
          parent.push_back(idx);
        }
        idx++;
        if (idx==val.size()) {
          break;
        }
        ptr = val[idx];
      }
      std::vector<int> first(idx, 0);
      std::vector<int> second(idx, 0);
      std::vector<int> dp(idx, 0);
      for (int i = idx-1; i >= 0; i--) {
        int temp = val[i]->val + second[i];
        dp[i] = (temp > first[i])? temp : first[i];
        int first_par = parent[i];
        if(first_par != -1){
          first[first_par] += dp[i];
          int sec_parent = parent[first_par];
          if(sec_parent != -1){
            second[sec_parent] += dp[i];
          }
        }
      }
      return dp[0];
    }
};

int main (int argc, char *argv[])
{
  TreeNode a(3);
  TreeNode b(1);
  TreeNode c(2, nullptr, &a);
  TreeNode d(3, nullptr, &b);
  TreeNode root(3, &c, &d);
  Solution sol;
  std::cout << sol.rob(&root) << std::endl;
  return 0;
}
