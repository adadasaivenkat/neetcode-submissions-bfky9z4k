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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        if(cnt==n) head=head->next;
        else{
            ListNode* prev=nullptr;
            int pos=cnt-n,i=0;
            while(i<pos){
                i++;
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
        }
        delete temp;
        return head;
    }
};