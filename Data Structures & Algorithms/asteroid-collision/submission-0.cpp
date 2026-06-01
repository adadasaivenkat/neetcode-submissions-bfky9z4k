class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Stack stores asteroids that have survived so far
        stack<int> st;
        // Push first asteroid
        st.push(asteroids[0]);
        // Process remaining asteroids one by one
        for(int i=1; i<asteroids.size(); i++){
            // Case 1: Current asteroid is moving left (-ve)
            if(asteroids[i]<0){
                // destroyed = true means current asteroid is destroyed
                bool destroyed=false;
                // Collision is possible only when:
                // Stack top is positive  ---> moving right
                // Current asteroid is negative ---> moving left
                // Example:
                // 10  -5
                // They move towards each other, so collision occurs.
                while(!st.empty() && st.top()>0 && !destroyed){
                    int topEle=st.top();
                    // Example:
                    // topEle = 5
                    // current = -5
                    // Both destroy each other.
                    if(topEle==abs(asteroids[i])){
                        st.pop(); // remove positive asteroid
                        destroyed=true; // current asteroid also destroyed
                    }
                    else{
                        // Find smaller asteroid
                        // Example:
                        // topEle = 10
                        // current = -15
                        // minEle = 10
                        int minEle=min(topEle,abs(asteroids[i]));
                        // Positive asteroid is smaller
                        // Example:
                        // 10  -15
                        // 10 gets destroyed.
                        // Remove it and continue checking
                        // because -15 may collide with
                        // previous asteroids also.
                        if(minEle==topEle) st.pop();
                        // Current negative asteroid is smaller
                        // Example:
                        // 15  -10
                        // -10 gets destroyed.
                        // Stop further collisions.
                        else if(minEle==abs(asteroids[i])) destroyed=true;
                    }
                }
                // If current asteroid survived all collisions,
                // push it into stack.
                // Example:
                // [5,10,-15]
                // -15 destroys 10
                // -15 destroys 5
                // Stack becomes empty
                // Since -15 survives,
                // push -15 into stack.
                if(!destroyed && (st.empty() || st.top()<0)) st.push(asteroids[i]);
            }
            // Case 2: Positive asteroid
            else if(asteroids[i]>0){
                // Positive asteroids cannot collide with any asteroid
                // already present in the stack.
                // Cases:
                // + +
                // Example: 5 10
                // Both move right, so no collision.
                // - +
                // Example: -5 10
                // They move away from each other, so no collision.
                // Therefore, a positive asteroid can be pushed directly.
                st.push(asteroids[i]);
            }
        }
        // Store answer
        vector<int> res;
        // Stack contains survivors but in reverse order.
        // Example stack:
        // Bottom -> Top
        // 5 10 15
        // Popping gives:
        // 15 10 5
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        // Restore original order
        reverse(res.begin(),res.end());
        return res;
    }
};