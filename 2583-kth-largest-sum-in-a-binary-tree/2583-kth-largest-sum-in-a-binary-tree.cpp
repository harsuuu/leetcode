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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)   return -1;
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(temp);
        vector<long long>ans;
        while(!q.empty())
        {
            long long res=0;
            long long size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* a = q.front(); 
                q.pop();
                res+=a->val;
                if(a->left)
                {
                    q.push(a->left);
                }
                if(a->right)
                {
                    q.push(a->right);
                }
            }
            ans.push_back(res);
        }
    if (k > ans.size()) return -1;  //edge case
    sort(ans.begin(),ans.end());
    return ans[ans.size()-k];
    }
};