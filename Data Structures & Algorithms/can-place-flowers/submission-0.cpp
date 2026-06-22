class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        if(size==1){
            if(flowerbed[0]==0){
                flowerbed[0]=1;
                n--;
            }
            return n<=0;
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        for(int i=1; i<size-1; i++){
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        if(flowerbed[size-1]==0 && flowerbed[size-2]==0){
            flowerbed[size-1]=1;
            n--;
        }
        return n<=0;
    }
};

// KEY OBSERVATION:
// A flower can be planted only if:
// 1. The current plot is empty (0).
// 2. The left adjacent plot is empty or does not exist.
// 3. The right adjacent plot is empty or does not exist.

// GREEDY IDEA:
// Whenever a valid position is found, immediately plant a flower.
// This greedy choice is optimal because planting at the earliest
// possible position never reduces the number of flowers that can
// be planted later.

// APPROACH:
// 1. Handle the special case when the flowerbed contains only one plot.
// 2. Check the first plot separately because it has no left neighbor.
// 3. Traverse all middle plots and plant a flower whenever:
//       flowerbed[i-1] == 0 &&
//       flowerbed[i]   == 0 &&
//       flowerbed[i+1] == 0
// 4. Check the last plot separately because it has no right neighbor.
// 5. Decrease n whenever a flower is planted.
// 6. If we have planted all required flowers, return true.

// WHY return n <= 0 INSTEAD OF n == 0 ?
// Suppose:
// flowerbed = [0,0,0,0,0]
// n = 1
// We only need to plant 1 flower.
// After planting:
// n = 0
// If we continue traversing, we may find more valid positions and
// plant additional flowers:
// n = -1
// n = -2
// This still means we successfully planted AT LEAST the required
// number of flowers.
// Therefore: return n <= 0 is safer than: return n == 0
// because n may become negative after planting more flowers than
// actually required.

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)