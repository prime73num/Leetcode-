




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
  private:
    bool getheight(TreeNode* root, int& height){
      if(root == nullptr){
        height = 0;
        return true;
      }
      int left;
      int right;
      if(getheight(root->left, left) && getheight(root->right, right)){
        if(left > right){
          height = left+1;
          return left-right <= 1;
        } else {
          height = right+1;
          return right-left <= 1;
        }
      }
      return false;
    }
  public:
    bool isBalanced(TreeNode* root) {
      int height;
      return getheight(root, height);
    }
};
