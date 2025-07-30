class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int prefix=1;
     int suffix=1;
     int maxpro=INT_MIN;
     for(int i=0;i<nums.size();i++){
        prefix=prefix*nums[i];
        maxpro=max(prefix,maxpro);
        if(prefix==0){prefix=1;}
     }
     for(int j=nums.size()-1;j>=0;j--){
        suffix=suffix*nums[j];
        maxpro=max(suffix,maxpro);
        if(suffix==0){suffix=1;}
     
     }return maxpro;
    }
    
};