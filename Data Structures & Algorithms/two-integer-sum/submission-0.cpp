class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        int sum = 0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(ump.find(rem)!=ump.end()){
                return {ump[rem],i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};
