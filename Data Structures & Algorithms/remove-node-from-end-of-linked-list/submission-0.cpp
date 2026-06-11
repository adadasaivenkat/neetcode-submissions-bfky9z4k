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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* temp=head;
        ListNode* after=nullptr;
        while(temp!=nullptr){
            after=temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        head=prev;
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverseList(head);
        ListNode* temp=head;
        if(n==1) head=head->next;
        else{
            ListNode* prev=nullptr;
            int i=1;
            while(i<n){
                i++;
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
        }
        delete temp;
        head=reverseList(head);
        return head;
    }
};