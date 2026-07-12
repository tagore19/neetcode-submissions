class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n) ;
        
        
        int  left = 0;
        int right = n-1;
        int maxL = 0;
        int maxR = 0;
        int water = 0;
        for(int  i = 0; i<n;i++){
            
            maxL = max(maxL,height[i]);
            leftSum[i] = maxL;


        }
        for(int  i = n-1;i>=0;i--){
            maxR = max(maxR,height[i]);
            rightSum[i] = maxR;
        }
        for(int  i = 0;i<n;i++){
            water = water + (min(leftSum[i],rightSum[i])-height[i]);


        }
        return water;
        
    }
};
