

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
  private:
    int state;
    int track(TreeNode* root){
      if(root == nullptr){
        state = 1;
        return 0;
      }
      int sum = 0;
      sum += track(root->left);
      int temp_state = state;
      sum += track(root->right);
      if(temp_state == 0 || state == 0){
        state = 2;
        return sum+1;;
      }
      if(temp_state == 2 || state == 2){
        state = 1;
      } else {
        state = 0;
      }
      return sum;
    }
  public:
    int minCameraCover(TreeNode* root) {
      int res = track(root);
      if(state == 0){
        return res+1;
      }
      return res;
    }
};
