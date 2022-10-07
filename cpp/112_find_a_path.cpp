





#include <iostream>
#include <vector>

using namespace std;

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
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root==nullptr) {
        return false;
      }
      int rest = targetSum - root->val;
      if(root->left == nullptr && root->right == nullptr && rest == 0){
        return true;
      }
      if(hasPathSum(root->left, rest)){
        return true;
      }
      if(hasPathSum(root->right, rest)){
        return true;
      }
      return false;
    }
};
