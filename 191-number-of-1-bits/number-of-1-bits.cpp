class Solution {
public:
    int hammingWeight(uint32_t n) {
        int k=0;
        while(n>0){
            if(n%2==0){
                n/=2;
            }
            else{
                n/=2;
                k++;
            }
        }
        return k;
    }
};