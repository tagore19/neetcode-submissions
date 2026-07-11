class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int areaMax = 0;

        while(i<j){
            int area = min(heights[i],heights[j])*(j-i);
            if(heights[i] < heights[j]){
                i++;
            }
            else if(heights[i] > heights[j]){
                j--;
            }
            else{
                j--;
            }
            areaMax = max(areaMax, area);
   
        }
        return areaMax;
        
    }
};
