





#include <iostream>
#include <vector>
#include <stack>

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
    long long min = LONG_MIN;
    bool isValidBST(TreeNode* root) {
      if(root==nullptr)
        return true;
      if(isValidBST(root->left) && min < root->val){
        min = root->val;
      } else {
        return false;
      }
      return isValidBST(root->right);
    }
};
