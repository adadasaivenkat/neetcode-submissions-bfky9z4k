class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> suff(n,0);
        suff[n-1]=-1;
        for(int i=n-2; i>=0; i--) suff[i]=max(suff[i+1],arr[i+1]);
        for(int i=0; i<n; i++) arr[i]=suff[i];
        return arr;
    }
};