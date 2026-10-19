class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> arr;
        sort(nums.begin(),nums.end());
        //int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)arr.push_back(i);
        }
        return arr;
        
    }
};