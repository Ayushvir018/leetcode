// int mov(vector<int>& nums, int k){
//     sort(nums.begin(),nums.end());
//     if(nums[2]==nums[0]){
//         return k;
//     }
//     while(nums[0]!=nums[2]){
//         nums[0]+=1;
//         nums[1]+=1;
//         k++;
//     }
//     mov(nums,k);
//     return k;
// }
// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int k=0;
//         return mov(nums,k);
//     }
// };

class Solution {
public:
    int minMoves(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int k=0,i=0,m=0;
    while(k!=nums.size()){
        m+=nums[i];
        k++;
        i++;
    }

    return m-(long long)nums.size()*nums[0];
        
    }
};
