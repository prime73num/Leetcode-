











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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      TreeNode** pos = &root;
      while (*pos != nullptr)
      {
        TreeNode* temp = *pos;
        pos = temp->val > val ? &temp->left : &temp->right;
      }
      *pos = new TreeNode(val);
      return root;
    }
};
