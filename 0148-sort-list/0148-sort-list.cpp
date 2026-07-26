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
    ListNode* middle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val <= list2->val) {
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        } else {
            list2->next = merge2Lists(list2->next, list1);
            return list2;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = middle(head);
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge2Lists(lefthead, righthead);
    }
};