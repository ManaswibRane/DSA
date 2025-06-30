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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        ListNode* node1;
        ListNode* node2;
        
        while(temp!=NULL){
           n++;
           temp=temp->next;
        }
        int i=1;
        temp=head;
        while(temp!=NULL){
            if(i==k) node1=temp;
            if((n-i+1)==k) node2=temp;
            temp=temp->next;
            i++;
        }
        swap(node1->val,node2->val);
        return head;
    }
};