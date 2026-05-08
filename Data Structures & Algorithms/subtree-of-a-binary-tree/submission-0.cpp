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
    bool issame(TreeNode* s,TreeNode* t)
    {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        if(t->val != s->val)
            return false;
        return issame(s->left,t->left) && issame(s->right,t->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)
            return false;
        if(issame(root,subRoot))
            return true;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};
