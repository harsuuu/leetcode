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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* temp = head;
        vector<int> ans;
        unordered_map<int, int> mpp;

        // 1st step--> take all the value in array and count frequency 
        while (temp) {
            ans.push_back(temp->val);
            mpp[temp->val]++;
            temp = temp->next;
        }

        //2nd step -> make another array and only unique values from map. 
        vector<int> ans2;
        for (auto& num : mpp) {
            if (num.second == 1) {
                ans2.push_back(num.first);
            }
        }

        sort(ans2.begin(),ans2.end());

        
        if (ans2.empty()) return nullptr;
        
        //Step 3:Now convert array into LL\U0001f60a
        ListNode* newHead = new ListNode(ans2[0]);
        ListNode* base = newHead;
        for (int i = 1; i < ans2.size(); i++) {
            ListNode* temp = new ListNode(ans2[i]);
            base->next = temp;
            base = temp;
        }

    return newHead;
    }
};