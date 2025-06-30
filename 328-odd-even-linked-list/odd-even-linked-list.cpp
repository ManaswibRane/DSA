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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* oddhead=NULL;
         ListNode* oddnext=NULL;
          ListNode* evenhead=NULL;
           ListNode* evennext=NULL;
        int i=1;
        while(head!=NULL){
            if(i%2==0){
                 if(evenhead==NULL){
                    evenhead=head;
                    evennext=evenhead;
                 }
                 else{
                    evennext->next=head;
                    evennext=evennext->next;
                 }
            }else{
                 if(oddhead==NULL){
                    oddhead=head;
                    oddnext=oddhead;
                 }
                 else{
                    oddnext->next=head;
                    oddnext=oddnext->next;
                 }

            }
            i++;
            head=head->next;
        }
        if(evennext) evennext->next=NULL;
        oddnext->next=evenhead;
        return oddhead;
    }
};