class Solution{
private:
    // Lower Bound
    int getStart(vector<int> &nums, int x){
        int n=nums.size();
        int ans=n,low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    // Upper Bound
    int getEnd(vector<int> &nums, int x){
        int n=nums.size();
        int ans=n,low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans-1;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n=nums.size();
        int start=getStart(nums,target);
        if(start==n || nums[start]!=target) return {-1,-1};
        else{
            int end=getEnd(nums,target);
            return {start,end};
        }
    }
};

// Lower Bound -> Smallest index such that arr[idx] >= x
// Upper Bound -> Smallest index such that arr[idx] > x

// start == n
// Means no element >= target exists in the array,
// so target is definitely not present.
// Example:
// nums = {1,2,3}
// target = 10
// start = 3 (n)

// nums[start] != target
// Lower bound gives first index with value >= target.
// That value may be greater than target,
// so we must check whether target actually exists.
// Example:
// nums = {1,2,4,5}
// target = 3
// start = 2
// nums[2] = 4 != 3

// We only check start because lower bound itself
// determines whether target is present or not.

// If start is valid and nums[start] == target,
// then end will also be valid automatically.
// Example:
// nums = {1,2,4,4,4,5}
// target = 4
// start = 2
// end = 4