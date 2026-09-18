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
    void reverse(int startIdx, int endIdx, vector<int>& arr){
        while(startIdx<endIdx){
            swap(arr[startIdx],arr[endIdx]);
            startIdx++;
            endIdx--;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }
        int n=arr.size();
        for(int i=0; i<n; i+=k){
            if(i+k-1<n) reverse(i,i+k-1,arr);
        }
        ListNode* temp=nullptr;
        for(int i=0; i<n; i++){
            ListNode* newNode=new ListNode(arr[i]);
            if(head==nullptr){
                head=newNode;
                temp=newNode;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
        }
        return head;
    }
};