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
    // post order better as left checked then right checked then the main node
    // {included, not - included} ->
    pair<int,int> dfs(TreeNode *root){
        if(root == NULL){
            return {0,0};
        }
        pair<int,int> left_choices = dfs(root->left);
        pair<int,int> right_choices = dfs(root->right);
      // dekh agar rob karna hai toh obviously hum value + prev value not included wale cases include karenge 
      // agar skip karna hai then hum max of prev values not included or prev values included wale cases dekh sakte hai!
        int robbed = root->val + left_choices.second + right_choices.second;
        int skipped = max(left_choices.first,left_choices.second) + max(right_choices.first,right_choices.second);
        return {robbed,skipped};
    }
    int rob(TreeNode* root) {
        pair<int,int> x = dfs(root);
        return max(x.first,x.second);
    }
};
