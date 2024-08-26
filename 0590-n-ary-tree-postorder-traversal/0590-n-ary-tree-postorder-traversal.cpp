/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>result;
    void traverse(Node* root)
    {
        if(!root)       return;
        //phle child ke deapth m jate rho at returning time store krlo.
        for(Node* x:root->children)
        {
            traverse(x);
        }
    result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        //N-ary m postorder hota hai --> child,root

        traverse(root);

    return result;
    }
};