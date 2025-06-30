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
    bool isPalindrome(ListNode* head) {
        vector<int> Data;
        ListNode* temp=head;
        while(temp!=NULL){
            Data.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=Data.size()-1;
        while(i<j){
           if(Data[i++]!=Data[j--]) return false;

        }
        return true;
    }
};