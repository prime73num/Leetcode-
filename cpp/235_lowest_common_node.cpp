






#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* res;
      TreeNode* next = root;
      while (next != nullptr)
      {
        res = next;
        next = nullptr;
        if(p->val < res->val && q->val < res->val){
          next = res->left;
        }
        if(p->val > res->val && q->val > res->val){
          next = res->right;;
        }
      }
      return res;
    }
};
