class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two halves
        ListNode* second = slow->next;
        slow->next = NULL;

        // Reverse second half
        ListNode* prev = NULL;

        while(second != NULL){
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        // Merge
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while(secondHalf != NULL){

            ListNode* firstNext = first->next;
            ListNode* secondNext = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = firstNext;

            first = firstNext;
            secondHalf = secondNext;
        }
    }
};