




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
  private:
    TreeNode* res;
    int find(TreeNode* root, TreeNode* p, TreeNode* q){
      if(root == nullptr){
        return 0;
      }
      
      int left_res = find(root->left, p, q);
      if(left_res==3) return left_res;
      int right_res = find(root->right, p, q);
      if(right_res==3) return right_res;
      int final_res = left_res + right_res;
      if(root == p){
        final_res += 1;
      }
      if(root == q){
        final_res += 2;
      }
      if(final_res==3){
        res = root;
      }
      return final_res;
    }
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(find(root, p, q) == 3){
        return res;
      }
      return nullptr;
    }
};
