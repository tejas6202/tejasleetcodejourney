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
// reverse the ll
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        return prev;
    }

// find thee kth node
    ListNode* getKnode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while (temp != NULL) {
            ListNode* Kthnode = getKnode(temp, k);
            if (Kthnode == NULL) {
                if (prevnode)
                    prevnode->next = temp;
                break;
            }

            ListNode* nextnode = Kthnode->next;
            Kthnode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = Kthnode;
            } else {
                prevnode->next = Kthnode;
            }

            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};