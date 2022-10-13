
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
  private:
    int sum;
    void travel(TreeNode* root){
      if(root == nullptr) return;
      travel(root->right);
      sum += root->val;
      root->val = sum;
      travel(root->left);
    }
  public:
    TreeNode* convertBST(TreeNode* root) {
      sum = 0;
      travel(root);
      return root;
    }
};
