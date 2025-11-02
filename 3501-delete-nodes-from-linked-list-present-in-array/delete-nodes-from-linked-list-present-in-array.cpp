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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp;
        for(int x: nums){
            mp.insert(x);
        }
        while(head!=NULL && mp.find(head->val)!=mp.end()){
               head=head->next;
        }
        if(head==NULL){
            return head;
        }
       
        ListNode* crawl=head;
        
        while(crawl!=NULL && crawl->next!=NULL){
             while(crawl->next!=NULL && mp.find(crawl->next->val)!=mp.end()){
                  crawl->next=crawl->next->next;
             }
             crawl=crawl->next;
        }
        return head;
 }
};