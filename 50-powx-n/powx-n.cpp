

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        bool negative = (N < 0);

        if (N < 0) {
            N = -N;
        }

        long double base = x;
        long double ans = 1.0L;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= base;
            }

            base *= base;
            N /= 2;
        }

        if (negative) {
            ans = 1.0L / ans;
        }

        return (double)ans;
    }
};



// double pow(double x, int n){
//     if(n==0){
//         return 1.0;
//     }
//     if(n%2==1){
//         return x*pow(x,n-1);
//     }
//     else{
//         return pow(x*x,n/2);
//     }

// }
// class Solution {
// public:
//      double myPow(double x, int n) {
//         long long N = n;
//          if (N < 0) {
//                x = 1.0 / x;
//                N = -N;
//         }
//         return pow(x,N);
        
        
//     }
// };

// double power(double x, long long n) {
//     if (n == 0) {
//         return 1.0;
//     }

//     double half = power(x, n / 2);

//     if (n % 2 == 0) {
//         return half * half;
//     }

//     return half * half * x;
// }

// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n;

//         if (N < 0) {
//             x = 1.0 / x;
//             N = -N;
//         }

//         return power(x, N);
//     }
// };
