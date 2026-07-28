#include <cstring>
class Solution {
int dp[105][105];
private:
    int dfs(int r, int c, int &m, int &n){
        if(r>=m || c>=n) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=dfs(r+1,c,m,n)+dfs(r,c+1,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,m,n);
    }
};

// memset is a C/C++ library function used to fill a block of memory with the same byte value.
// Syntax: memset(array, value, sizeof(array));
// array → the array you want to initialize.
// value → the byte value to fill.
// sizeof(array) → total number of bytes to fill.
// Example : Initialize all elements to 0
// int arr[5];
// memset(arr, 0, sizeof(arr));
// Result:
// 0 0 0 0 0
// memset() fills memory BYTE BY BYTE, not element by element.
// What is a Byte?
// - A byte is the smallest unit of memory that memset can write.
// - 1 byte = 8 bits.
// - An int usually occupies 4 bytes (32 bits).
// Example:
// int x;
// Memory of x (4 bytes):
// +--------+--------+--------+--------+
// | Byte 1 | Byte 2 | Byte 3 | Byte 4 |
// +--------+--------+--------+--------+
// memset changes each byte individually.
// Why does memset(arr, 0, ...) work?
// - It fills every byte with 0x00.
// Memory:
// 00 00 00 00
// This represents:
// 0x00000000 = 0
// So every int becomes 0.
// Why does memset(arr, -1, ...) work?
// - -1 is represented in two's complement as all bits = 1.
// - So every byte becomes 0xFF.
// Memory:
// FF FF FF FF
// This represents:
// 0xFFFFFFFF = -1
// So every int becomes -1.
// Why doesn't memset(arr, 1, ...) work?
// - It fills every byte with 0x01.
// Memory:
// 01 01 01 01
// This represents:
// 0x01010101 = 16843009 (not 1)
// Similarly:
// 02 02 02 02 -> 0x02020202 (not 2)
// 05 05 05 05 -> 0x05050505 (not 5)
// Rule:
// memset(arr, 0, sizeof(arr));
// memset(arr, -1, sizeof(arr));
// Don't use memset for 1, 2, 5, 100, etc.
// Use loops or std::fill() instead.
// Works for:
// 1D, 2D, 3D, 4D, 5D, 6D, ... arrays.
// Reason:
// Multi-dimensional arrays are stored as one contiguous block of memory.
// memset simply fills the entire block byte by byte, regardless of the number of dimensions.