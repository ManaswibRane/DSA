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
    bool hasCycle(ListNode *head) {
      unordered_set<int> s;
      ListNode* slow=head;
      ListNode* fast=head;

      while(fast!=NULL && fast->next!=NULL){
       fast=fast->next->next;
       slow=slow->next;
       if(slow==fast) return true;

      }  
      return false;
    }
};