/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // created a dfs which return a integer value based on which we will decide the bool value in main function.
    int dfs(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        // condition for the non-leaf node is OR and condition for the non-leaf node is AND.
        // else it got to be 1 or 0... then just return their values no operations required.
        if(root->val == 2 && root->left != NULL && root->right != NULL){
            return (dfs(root->left) | dfs(root->right));
        }if(root->val == 3 && root->left != NULL && root->right !=NULL){
            return (dfs(root->left) & dfs(root->right));
        }else{
            return root->val;
        }
    }
    bool evaluateTree(TreeNode* root) {
        // if dfs return 1 -> True else False!
        if(dfs(root)){
            return true;
        }else{
            return false;
        }
        
    }
};
