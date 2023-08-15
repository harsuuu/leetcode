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
    ListNode* partition(ListNode* head, int x) {
        //we will make two linked list 
        //Step 1: x se choti balo k liye linked list.
        //Step 2: baki bache element k liye ek alag linked list.
        //Step 3: Then we will merge both of linked list.

        ListNode *First= new ListNode();
        ListNode* currFirst=First;

        ListNode *Second= new ListNode();
        ListNode* currSecond=Second;

        while(head)
        {
            if(head->val < x)
            {
                currFirst->next=new ListNode(head->val);
                currFirst=currFirst->next;
            }
            else
            {
                currSecond->next=new ListNode(head->val);
                currSecond=currSecond->next;
            }
            head=head->next;
        }

        currFirst->next=Second->next;
        return First->next;
    }
};