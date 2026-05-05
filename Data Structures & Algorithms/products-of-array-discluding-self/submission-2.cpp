class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0;
        int n = nums.size();
        int prod = 1,prod2 = 0;
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                countZero++;
            }
        }
        if(countZero>1){
            return result;
        }
        else if(countZero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    continue;
                }
                else{
                    prod *= nums[i];
                }
            }
            for(int k=0;k<n;k++){
                if(nums[k]==0)
                    result[k] = prod;
                else
                    result[k] = 0;
            }
        }
        else if(!countZero){
            for(int i=0;i<n;i++){
                prod *= nums[i];
            }
            for(int j=0;j<n;j++){
                result[j] = prod/nums[j];
            }
        }
        return result;
    }
};
