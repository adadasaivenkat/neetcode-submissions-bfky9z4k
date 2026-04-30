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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;
        while(head!=nullptr && head->val==val){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        ListNode* temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val==val){
                ListNode* dummy=temp->next;
                temp->next=temp->next->next;
                delete dummy;
            }
            else temp=temp->next;
        }
        return head;
    }
};