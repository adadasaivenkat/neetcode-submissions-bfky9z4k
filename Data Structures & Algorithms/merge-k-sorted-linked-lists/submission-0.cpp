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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(auto &lst:lists){
            while(lst!=nullptr){
                arr.push_back(lst->val);
                lst=lst->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head=nullptr;
        ListNode* temp=nullptr;
        for(int i=0; i<arr.size(); i++){
            ListNode* newNode=new ListNode(arr[i]);
            if(head==nullptr){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        return head;
    }
};
