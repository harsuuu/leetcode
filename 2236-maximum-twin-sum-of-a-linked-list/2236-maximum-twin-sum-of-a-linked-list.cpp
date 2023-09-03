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
    int pairSum(ListNode* head) {
        //first hmne ise vector m store kra liya linked list ko.
        vector<int>list;
        while(head!=NULL)
        {
           list.push_back(head->val);
           head=head->next;
        }
        int n = list.size();
        int maxsum=0;
        //now hm for loop lgaynge hai and max nikal lenge.
        for(int i=0;i<n;i++)
        {
            maxsum=max(maxsum,list[i]+list[n-1-i]);
        }
        return maxsum;
        
        
    }
};