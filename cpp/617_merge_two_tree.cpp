






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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      stack<TreeNode**> tree1;
      stack<TreeNode*> tree2;

      tree1.push(&root1);
      tree2.push(root2);

      while (!tree1.empty() || !tree2.empty()) {
        TreeNode** p1 = tree1.top();
        TreeNode* p2 = tree2.top();
        tree1.pop();
        tree2.pop();

        if((*p1) == nullptr && p2 == nullptr){ continue; }
        int sum = 0;
        if(p2 != nullptr){
          sum += p2->val;
          tree2.push(p2->left);
          tree2.push(p2->right);
        } else {
          tree2.push(nullptr);
          tree2.push(nullptr);
        }
        if(*p1 != nullptr){
          sum += (*p1)->val;
          tree1.push(&(*p1)->left);
          tree1.push(&(*p1)->right);
        } else {
          *p1 = new TreeNode();
          tree1.push(&(*p1)->left);
          tree1.push(&(*p1)->right);
        }
        (*p1)->val = sum;
      }
      return root1;
    }
};
