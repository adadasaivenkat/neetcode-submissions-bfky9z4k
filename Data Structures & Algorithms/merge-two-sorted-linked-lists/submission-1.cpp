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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> res;
        ListNode* temp=list1;
        while(temp!=nullptr){
            res.push_back(temp->val);
            temp=temp->next;
        }
        temp=list2;
        while(temp!=nullptr){
            res.push_back(temp->val);
            temp=temp->next;
        }
        sort(res.begin(),res.end());
        ListNode* head=nullptr;
        temp=nullptr;
        for(auto &r:res){
            ListNode* newNode=new ListNode(r);
            if(head==nullptr){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=temp->next;
            }
        }
        return head;
    }
};
