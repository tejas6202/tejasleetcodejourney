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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* Second = newhead;

        while (Second != NULL) {
            if (first->val != Second->val) {
                reverseList(newhead);
                return false;
            }
           first = first->next;
            Second = Second->next;
        }
        reverseList(newhead);
        return true;
    }
};
