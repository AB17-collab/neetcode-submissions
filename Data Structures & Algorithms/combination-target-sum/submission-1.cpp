class Solution {
public:
    void findSum(int ind,int target,vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds){
        if(ind==nums.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[ind] <= target){
            ds.push_back(nums[ind]);
            findSum(ind,target-nums[ind],nums,ans,ds);
            ds.pop_back();
        }

        findSum(ind+1,target,nums,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSum(0,target,nums,ans,ds);
        return ans;
    }
};
