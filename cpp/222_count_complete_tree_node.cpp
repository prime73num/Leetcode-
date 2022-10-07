
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
    int countNodes(TreeNode* root) {
      TreeNode* left = root;
      TreeNode* right = root;
      int level = 0;
      while (left==right) {
        if(left==nullptr){
          return (1<<level) - 1;
        }
        left = left->left;
        right = right->right;
        level++;
      }
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
