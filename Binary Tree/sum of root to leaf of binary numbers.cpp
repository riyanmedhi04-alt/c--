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
    void dfs(TreeNode *root, int curr, int &sum){
        if(root == NULL){
            return;
        }
        // updating the current at every root.
        curr = (curr<<1) | root->val;
        if(root->left == NULL && root->right == NULL){
            // updating sum at every leaf we reached.
            sum += curr;
        }
        // recursive calling for left and right tree.
        dfs(root->left, curr, sum);
        dfs(root->right, curr, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        // created the final sum and also current variables and initialized them to 0.
        int sum = 0;
        int curr = 0;
        // function calling of dfs.
        dfs(root, curr, sum);
        return sum;

    }
};
