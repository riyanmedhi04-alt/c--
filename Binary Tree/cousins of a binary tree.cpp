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
// we first initialized dx and dy which are the depths of x and y respectively. also initialized px and py for parent nodes of the same.
    int dx = -1;
    int dy = -1;
    TreeNode *px = NULL;
    TreeNode *py = NULL;
    // dfs search storing the above values of depth and parent in depth variable and parent node and then assigning them to dx,dy,px & py when we find x & y .
    void dfs(TreeNode *root, int x, int y, int depth, TreeNode *parent){
        if(root == NULL){
            return;
        }
        if(root->val == x){
            px = parent;
            dx = depth;
        }
        if(root->val == y){
            py = parent;
            dy = depth;
        }
        dfs(root->left, x, y, depth+1, root);
        dfs(root->right, x, y, depth+1, root);
        
    }
    // main function . just compare the conditions and get answer!.
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, NULL);
        if(dx == dy && px != py){
            return true;
        }else{
            return false;
        }
    }
};
