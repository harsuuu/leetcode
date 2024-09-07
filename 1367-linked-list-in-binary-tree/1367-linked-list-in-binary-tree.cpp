/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
            bool dfs(TreeNode* root, ListNode* head) {
            if (head == NULL) return true;  // List is exhausted, it's a match
            if (root == NULL) return false; // Tree is exhausted, no match
            if (root->val != head->val) return false; // Mismatch in values

            // Try both left and right subtrees
            return dfs(root->left, head->next) || dfs(root->right, head->next);
        }

        bool isSubPath(ListNode* head, TreeNode* root) {
            if (root == NULL) return false; // No tree means no match possible
            if (dfs(root, head)==true)
            {
                return true; // Try matching from the current node
            } 

            // Otherwise, recursively try left and right subtrees
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
};