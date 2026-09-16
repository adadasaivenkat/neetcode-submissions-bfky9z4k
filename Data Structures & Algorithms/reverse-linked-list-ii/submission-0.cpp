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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        while(head!=nullptr){
            arr.push_back(head->val);
            head=head->next;
        }
        left--;
        right--;
        while(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        ListNode* temp=nullptr;
        for(int i=0; i<arr.size(); i++){
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