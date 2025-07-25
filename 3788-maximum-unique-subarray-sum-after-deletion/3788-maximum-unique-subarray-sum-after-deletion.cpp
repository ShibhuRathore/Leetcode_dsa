class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> pt;
        for(auto& num:nums) pt.insert(num);
        int result = 0,Max = INT_MIN;
        for(auto& num:pt){
            if(num>0)   result+=num;
            Max = max(Max,num);
        }
        if(result==0)   return Max;
        return result;
    }
};