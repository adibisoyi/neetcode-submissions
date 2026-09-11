/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)   {
        unordered_map<TreeNode*,TreeNode*> parent;
        if(!root)
            return nullptr;   
        parent[root] = nullptr;
        queue<TreeNode*> tq;
        tq.push(root);

        while(!parent.count(p) || !parent.count(q))
        {
            TreeNode* node = tq.front();
            tq.pop();

            if(node->left)
            {
                tq.push(node->left);
                parent[node->left] = node;
            }

            if(node->right)
            {
                tq.push(node->right);
                parent[node->right] = node;
            } 
        }
            unordered_set<TreeNode*> ancestor;
            while(p)
            {
                ancestor.insert(p);
                p = parent[p];
            }
            while(!ancestor.count(q))
            {
                q = parent[q];
            }
            return q;

     }
};