class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        vector<int> smallTillNow(n,prices[0]);
        vector<int> bigTillNow(n,prices[n-1]);
        for(int i=1;i<n;i++){
            smallTillNow[i] = min(prices[i],smallTillNow[i-1]);
        }
        for(int j=n-2;j>=0;j--){
            bigTillNow[j] = max(prices[j],bigTillNow[j+1]);
        }
        for(int k=0;k<n;k++){
            maxProfit = max(maxProfit,bigTillNow[k]-smallTillNow[k]);
        }
        return maxProfit;
    }
};
