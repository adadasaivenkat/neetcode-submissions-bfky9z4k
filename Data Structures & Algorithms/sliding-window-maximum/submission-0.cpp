class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        vector<int> res;
        deque<int> dq;
        while(r<n){
            while(!dq.empty() && dq.back()<nums[r]) dq.pop_back();
            dq.push_back(nums[r]);
            if(r-l+1<k) r++;
            else if(r-l+1==k){
                res.push_back(dq.front());
                // Slide
                if(nums[l]==dq.front()) dq.pop_front();
                l++;
                r++;
            }
        }
        return res;
    }
};