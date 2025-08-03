/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       /*     ListNode *temp1=headA;
            unordered_set<int> mp;
            while(temp1!=NULL){
               mp.insert(temp1->val);
               temp1=temp1->next;
            }
               ListNode *temp2=headB;
              while(temp2!=NULL){
                   if(mp.find(temp2->val)!=mp.end()){
                     return temp2;
               }
               temp2=temp2->next;
            
            }
            return NULL;  */
             ListNode *temp1=headA;
            while(temp1!=NULL){
             ListNode *temp2=headB;
                  while(temp2!=NULL){
                    if(temp1==temp2){
                        return temp1;
                    }
                    temp2=temp2->next;
                  }
                  temp1=temp1->next;
            }
            return NULL;
    }
};