class Solution {
private:
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find the end of the first half.
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;  

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(secondHalf);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = (left != nullptr) ? left : right;
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};