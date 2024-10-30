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
    void dfs(TreeNode* root, string temp, vector<string>&ans){
        if(root==NULL)  return;
        //if leaf Node
        if(root->left==NULL && root->right==NULL)
        {
            temp+=to_string(root->val);
            ans.push_back(temp);
        }

        temp+=to_string(root->val) + "->";
        //RECURSTION CALL
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        vector<string>ans;
        dfs(root,temp,ans);
    return ans;
    }
};