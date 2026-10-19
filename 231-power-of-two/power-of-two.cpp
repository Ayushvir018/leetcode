// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) return false;
//         while (n % 2 == 0) {
//             n /= 2;
//         }
//         return n == 1;
//     }
// };

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0)
//             return false;
//         return (n & (n - 1)) == 0;
//     }
// };

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n==1) return true;
        if(n%2==0){
            n=n/2;
            return isPowerOfTwo(n);
        }
        
        return false;
        
    }
};
