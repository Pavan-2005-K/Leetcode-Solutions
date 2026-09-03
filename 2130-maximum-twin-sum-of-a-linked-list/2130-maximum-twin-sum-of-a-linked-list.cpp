












class Solution {
public:
     int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid =slow;

        ListNode* nextnode=NULL;
        ListNode* prev=NULL;
        while(mid!=NULL){
            nextnode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextnode;
        }

        int result=0;
        ListNode* curr=head;
        while(prev!=NULL){
            result=max(result,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return result;
     }
};






// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int> vec;
//         while(head!=NULL){
//             vec.push_back(head->val);
//             head=head->next;
//         }
//         int result=0;
//         int i=0,j=vec.size()-1;
//         while(i<j)
//         {
//             result=max(result,vec[i]+vec[j]);
//             i++;
//             j--;
//         }
//         return result;
//     }
// };




// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         stack<int> st;

//         ListNode* curr=head;

//         while(curr!=NULL){
//             st.push(curr->val);
//             curr=curr->next;
//         }
//         int N=st.size();
//         curr=head;

//         int count=1;
//         int result=0;
//         while(count<=N/2){
//             result=max(result,curr->val+st.top());
//             curr=curr->next;
//             st.pop();
//             count++;
//         }
//         return result;
//     }
// };