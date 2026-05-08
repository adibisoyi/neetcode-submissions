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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        queue<TreeNode*> nodeq;
        nodeq.push(root);

        while(!parent.count(p)|| !parent.count(q))
        {
            TreeNode* node = nodeq.front();nodeq.pop();
            if(node->left)
            {
                parent[node->left]=node;
                nodeq.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                nodeq.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestor;
        while(p)
        {
            ancestor.insert(p);
            p=parent[p];
        }
        while(!ancestor.count(q))
        {
            q=parent[q];
        }
        return q;
    }
};