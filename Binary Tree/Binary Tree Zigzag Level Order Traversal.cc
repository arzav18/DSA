class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> row(n);
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int index = leftToRight? i:(n-1-i);
                row[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight =! leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
