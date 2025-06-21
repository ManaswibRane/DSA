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
        int Lsize=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            Lsize++;
        }
        int idx=Lsize-n+1;
        if(idx<0) return NULL;
        temp=head;
        int x=1;
        while(temp!=NULL){
         if(x==idx) return temp->next;
         if(idx-1==x){
             temp->next=temp->next->next;
             return head;
         }
          temp=temp->next;
          x++;

        }
        return head;
    }
};