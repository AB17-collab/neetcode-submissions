class Solution {
public:
    int findMin(vector<int> &nums) {
        int k = nums.size();
        int ans = INT_MAX;  
        int left = 0,right = k-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(mid==0){
                ans = min(nums[mid],nums[mid+1]);
                break;
            }
            else if(mid==k-1){
                ans = min(nums[mid],nums[mid-1]);
                break;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                if(nums[mid]<ans){
                    ans = nums[mid];
                    break;
                }
            }
            else if(nums[mid]>nums[right]){
                left = mid+1;
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1]){
                right = mid-1;
            }
        }
        return ans;
    }
};
