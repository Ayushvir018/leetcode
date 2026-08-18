class Solution {
public:

    int piv(vector<int>& nums) {
        int n = nums.size();

        // Array not rotated
        if (nums[0] <= nums[n - 1])
            return 0;

        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[0]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }

    int bin(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0)
            return -1;

        int pivot = piv(nums);

        
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return bin(nums, target, pivot, n - 1);
        }
        else {
            return bin(nums, target, 0, pivot - 1);
        }
    }
};