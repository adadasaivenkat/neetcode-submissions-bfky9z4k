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
        while(list1!=nullptr){
            res.push_back(list1->val);
            list1=list1->next;
        }
        while(list2!=nullptr){
            res.push_back(list2->val);
            list2=list2->next;
        }
        sort(res.begin(),res.end());
        ListNode* head=nullptr;
        ListNode* temp=nullptr;
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
