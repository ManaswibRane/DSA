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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sorted=NULL;
        ListNode*tail;
        while(list1!=NULL && list2!=NULL){
            if( (list1->val)> (list2->val) ){
                    ListNode* newNode=new ListNode(list2->val);
                   if(sorted==NULL){
                      sorted=newNode;
                      tail=newNode;

                   }
                   else{
                     tail->next=newNode;
                     tail=newNode;
                   }
                   list2=list2->next;
            }
            else{
                ListNode* newNode=new ListNode(list1->val);
                   if(sorted==NULL){
                      sorted=newNode;
                      tail=newNode;

                   }
                   else{
                     tail->next=newNode;
                      tail=newNode;
                   }
                  
                   list1=list1->next;
                }

          }
          while(list1!=NULL){
              ListNode* newNode=new ListNode(list1->val);
                   if(sorted==NULL){
                      sorted=newNode;
                      tail=newNode;

                   }
                   else{
                     tail->next=newNode;
                      tail=newNode;
                   }
                   list1=list1->next;
          }
          while(list2!=NULL){
                    ListNode* newNode=new ListNode(list2->val);
                   if(sorted==NULL){
                      sorted=newNode;
                      tail=newNode;

                   }
                   else{
                     tail->next=newNode;
                      tail=newNode;
                   }
                  
                   list2=list2->next;
                }
          

        return sorted;
       
    }
};