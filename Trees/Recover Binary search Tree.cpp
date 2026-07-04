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
   // IN BST -> Inorder Traversal always produces increasing sorted array!!
    void dfs(TreeNode *root, vector<pair<TreeNode* ,int>> &v){
        if(root == NULL){
            return;
        }
        dfs(root->left, v);
        v.push_back({root, root->val});
        dfs(root->right, v);
    }
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode* ,int>> v;
        dfs(root, v);
        TreeNode *firstNode = NULL;
        TreeNode *secondNode = NULL;
        for(int i = 0; i<v.size() -1 ; i++){
            if(v[i].second > v[i+1].second){
                if(firstNode == NULL){
                    firstNode = v[i].first;
                }
                secondNode = v[i+1].first;
            }
        }
        if(firstNode && secondNode){
            swap(firstNode->val, secondNode->val);
        }
    }
};
