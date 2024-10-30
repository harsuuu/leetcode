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
    bool solve(TreeNode* root,int targetSum,int sum)
    {
        if(root==NULL)  return false;
        sum += root->val;
        //if leaf node
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                return true;
            }else{
                return false;
            }
        }

        bool leftSide = solve(root->left,targetSum,sum);
        bool rightSide = solve(root->right,targetSum,sum);

    return leftSide || rightSide;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)   return false;
        int sum=0;
        return solve(root,targetSum,sum);
    }
};