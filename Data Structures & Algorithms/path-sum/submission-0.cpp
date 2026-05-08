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
    int dfs(TreeNode* node,int cursum, int target)
    {
        
        if(!node)
            return 0;
        cursum += node->val;
        
        if(node->left == NULL && node->right == NULL)
            return cursum == target;
        return dfs(node->left,cursum,target) || dfs(node->right,cursum,target);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
};