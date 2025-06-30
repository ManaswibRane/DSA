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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* temp=head;
        while(temp!=NULL){
              values.push_back(temp->val);
              temp=temp->next;
        }
        int maxSum=INT_MIN;
        int i=0,n=values.size();
        int j=n-1;
        while(i<j){
            int sum=values[i++]+values[j--];
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};