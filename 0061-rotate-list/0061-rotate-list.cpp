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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0){
            return head;
        }
        int L=1;
        ListNode* tailnode=head;
        while(tailnode->next!=NULL)
        {
            tailnode=tailnode->next;
            L++;
        }
        int K=k%L;
        if(k==0){
            return head;
        }
        tailnode->next=head;
        int remain=L-K;
        ListNode* newtailnode=head;
        for(int c=1;c<remain;c++){
            newtailnode=newtailnode->next;
        }
        ListNode* newhead=newtailnode->next;
        newtailnode->next=NULL;
        return newhead;
    }
};