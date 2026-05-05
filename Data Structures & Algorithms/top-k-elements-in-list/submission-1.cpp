class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]] = 1;
            }
        }

        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(), [](const auto& a,const auto& b){
            return a.second>b.second;
        });
        
        int count = k;
        for(auto i:v){
            if(count>0){
                result.push_back(i.first);
                count--;
            }
            else
                break;
        }
        return result;
    }
};
