class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int k=nums.size()-1;
        int i=0;
        long long sum=0;
        while(i<k){
            sum+=nums[k]*nums[k]-nums[i]*nums[i];
            i++;
            k--;
        }
        if(i==k){
            sum+=nums[k]*nums[k];
        }
        return sum;
        
    }
};