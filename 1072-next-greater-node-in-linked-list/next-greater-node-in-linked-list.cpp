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
class Solution {
public:
    vector<int>nGE(vector<int>&dummy)
    {
        int n=dummy.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=dummy[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(dummy[i]);
        }
    return ans;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>dummy;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            dummy.push_back(temp->val);
            temp=temp->next;
        }

        return nGE(dummy);
    }
};