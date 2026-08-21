class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        // n == seats.length == students.length
        int n=seats.size(),moves=0;
        for(int i=0; i<n; i++) moves+=abs(seats[i]-students[i]);
        return moves;
    }
};