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
    bool checkCBT(TreeNode* root,int index,int cnt)
    {
        if(root==NULL)    return true;

        if(index > cnt)   return false;

        return checkCBT(root->left,2*index,cnt) && checkCBT(root->right,2*index+1,cnt);
    }
    int countNode(TreeNode* root)
    {
        if(root==NULL)  return 0;

        return 1 + countNode(root->left) + countNode(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        int cnt = countNode(root); 

        int index=1;
        return checkCBT(root,1,cnt);
    }
};