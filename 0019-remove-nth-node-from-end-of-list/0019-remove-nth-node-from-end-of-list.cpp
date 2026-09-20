class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        for(int i=1;i<=n;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            ListNode* result=head->next;
            delete(head);
            return result;
        }

        ListNode* prev=head;

        while(temp->next!=NULL){
            prev=prev->next;
            temp=temp->next;
        }
        ListNode* delNode=prev->next;
        prev->next=prev->next->next;
        delete(delNode);

        return head;
    }
};

// class Solution {
// public:
//     int getLengthOfLinkedList(ListNode* head){
//         int length=0;
//         while(head!=NULL){
//             length++;
//             head=head->next;
//         }
//         return length;
//     }

//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int L=getLengthOfLinkedList(head);

//         if(n==L){
//             ListNode* temp=head->next;
//             delete(head);
//             return temp;
//         }

//         int travel_front=L-n;
//         ListNode* temp=head;
//         ListNode* prev=NULL;

//         while(travel_front--){
//             prev=temp;
//             temp=temp->next;
//         }
//         prev->next=temp->next;
//         delete(temp);
//         return head;
//     }
// };