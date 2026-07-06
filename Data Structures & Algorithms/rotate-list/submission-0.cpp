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
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode* temp=head;
        vector<int> v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        k=k%n;
        vector<int> arrTemp;
        for(int i=n-k; i<n; i++) arrTemp.push_back(v[i]);
        for(int i=n-1; i>=k; i--) v[i]=v[i-k];
        for(int i=0; i<arrTemp.size(); i++) v[i]=arrTemp[i];
        head=nullptr;
        temp=nullptr;
        for(int i=0; i<n; i++){
            ListNode* newNode=new ListNode(v[i]);
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