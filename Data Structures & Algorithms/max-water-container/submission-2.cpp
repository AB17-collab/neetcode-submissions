class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0,end = heights.size()-1;
        int area = 0;
        int res = INT_MIN;
        while(start<end){
            area = min(heights[start],heights[end])*(end-start);
            res = max(res,area);
            if(heights[start]<heights[end]){
                start++;
            }
            else
                end--;
        }
        return res;
    }
};
