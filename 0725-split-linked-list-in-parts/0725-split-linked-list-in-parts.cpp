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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int L=0;
        ListNode* curr=head;
        while(curr){
            L++;
            curr=curr->next;
        }

        int Bucketnodes=L/k;
        int remainNodes=L%k;

        vector<ListNode*>result(k,NULL);

        curr=head;
        ListNode* prev=NULL;

        for(int i=0;curr!=NULL && i<k;i++){
            result[i]=curr;

            for(int count=1;count<=Bucketnodes+(remainNodes>0?1:0);count++){
                prev=curr;
                curr=curr->next;
            }
            
            prev->next=NULL;
            remainNodes--;
            
        }
        return result;
    }
};