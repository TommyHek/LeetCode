/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head; 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (true) {
    
            ListNode* check = prev;
            for (int i = 0; i < k && check; i++) {
                check = check->next;
            }
            if (!check) {
                break;
            }

            ListNode* cur = prev->next;        
            ListNode* next = nullptr;
            ListNode* groupTail = cur;         

            ListNode* prevGroup = nullptr;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = prevGroup; 
                prevGroup = cur;        
                cur = next;
            }

            prev->next = prevGroup;
            groupTail->next = cur;
            prev = groupTail;
        }

        return dummy->next;
    }
};
// @lc code=end

