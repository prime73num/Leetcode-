




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
    TreeNode* searchBST(TreeNode* root, int val) {
      TreeNode* res = root;
      while (res != nullptr) {
        if(res->val == val){
          return res;
        } else if (res->val > val){
          res = res->left;
        } else {
          res = res->right;
        }
      }
      return nullptr;
    }
};
