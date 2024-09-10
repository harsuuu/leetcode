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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
        return head; // No need to process if the list is too short
    }

        ListNode* temp = head;
        ListNode* forward = head->next;

        while (forward != nullptr) {
            int a = temp->val;
            int b = forward->val;
            int result = std::gcd(a, b);

            // Create a new node for the GCD
            ListNode* newN = new ListNode(result);

            // Insert the new node between temp and forward
            temp->next = newN;
            newN->next = forward;

            // Move temp and forward pointers
            temp = forward;
            forward = forward->next;
        }
        
    return head;
    }
};