class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        next=nullptr;
    }
    ListNode(int val, ListNode* next){
        this->val=val;
        this->next=next;
    }
};

class LinkedList {
private:
    ListNode* head;
    ListNode* temp;
public:
    LinkedList() {
        head=nullptr;
        temp=nullptr;
    }

    int get(int index) {
        temp=head;
        int i=0;
        while(i<index && temp!=nullptr){
            i++;
            temp=temp->next;
        }
        if(temp!=nullptr) return temp->val;
        else return -1;
    }

    void insertHead(int val) {
        ListNode* newNode=new ListNode(val);
        if(head==nullptr) head=newNode;
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    
    void insertTail(int val) {
        ListNode* newNode=new ListNode(val);
        if(head==nullptr) head=newNode;
        else{
            temp=head;
            while(temp->next!=nullptr) temp=temp->next;
            temp->next=newNode;
        }
    }

    bool remove(int index) {
        if(head==nullptr) return false;
        if(index==0){
            ListNode* toDelete=head;
            head=head->next;
            delete toDelete;
            return true;
        }
        temp=head;
        ListNode* prev=nullptr;
        int i=0;
        while(i<index && temp!=nullptr){
            i++;
            prev=temp;
            temp=temp->next;
        }
        if(temp!=nullptr){
            prev->next=temp->next;
            delete temp;
            return true;
        }
        else return false;
    }

    vector<int> getValues() {
        vector<int> res;
        temp=head;
        while(temp!=nullptr){
            res.push_back(temp->val);
            temp=temp->next;
        }
        return res;
    }
};
