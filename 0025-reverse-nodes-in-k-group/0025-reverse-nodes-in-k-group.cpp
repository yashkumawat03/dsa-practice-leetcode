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
    ListNode* reverse(ListNode* temp){
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }
        return prev;
    }
    ListNode* getkthnode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp != NULL){
            ListNode* kthnode = getkthnode(temp, k);
            if(kthnode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthnode->next;
            kthnode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthnode;
            }
            else{
                prevLast->next = kthnode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};