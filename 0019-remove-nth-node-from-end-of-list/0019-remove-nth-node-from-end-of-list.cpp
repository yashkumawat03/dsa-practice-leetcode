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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head->next == NULL and n==1 ){
            return NULL;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        if(count == n) return head->next;
        int len = count - n;
        temp = head;
        for(int i=0;i<len-1;i++){
            temp = temp->next;
        }
        ListNode* front = temp->next;
        if(temp->next) temp->next = front->next;
        delete front;
        return head;
    }
    
};