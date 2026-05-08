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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int sizee= q.size();

            for(int i=0;i<sizee;i++)
            {
                TreeNode* value = q.front();
                q.pop();

                if(value->left != nullptr)
                    q.push(value->left);
                
                if(value->right != nullptr)
                    q.push(value->right);
                
                temp.push_back(value->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
