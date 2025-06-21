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
    ListNode* swapPairs(ListNode* head) {
        ListNode*temp=head;
        ListNode* prev=head;
        while(temp!=NULL && temp->next!=NULL){

            ListNode*temp2=temp->next;
            prev->next=temp2;
            temp->next=temp->next->next;
            temp2->next=temp;
            prev=temp;
            if(temp==head){
                head=temp2;
            }
            temp=temp->next;
        }
        return head;
    }
};