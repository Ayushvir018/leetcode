class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for(int i=1;i<nums.size();i++){
        for(int j=0;j<nums.size()-i;j++){
            if(nums[j]+nums[j+i]==target){
                return {j, j + i};
                break;

            }
        }
       } 
       return {};
    }
};