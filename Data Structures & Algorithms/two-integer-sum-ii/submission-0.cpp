class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int req = 0;
        int  i  = 0;
        int  j = n -1;
        while(i<j){
            int req = target - numbers[i];
            if(req > numbers[j]){
                i++;
            }
            else{
                if(numbers[j] == req){
                    return {i+1,j+1};
                }
                else{
                    j--;
                }
            }


        }
        return {};
        
    }
};
