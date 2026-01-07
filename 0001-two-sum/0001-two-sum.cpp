class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
     // brute force 
    //  for(int i=0;i<nums.size()-1;i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]+nums[j]==target)return{i,j};
    //     }
    //  } 
    //  return {-1,-1}; TC---->O(n^2). SC----->O(1)
    
   

    // with sorting + pair of indices and element 
    // vector<pair<int,int>>vec(nums.size());
    // for(int i =0;i<nums.size();i++){
    //     vec[i]={nums[i],i};   //{element,indices}
    // }
    // sort(vec.begin(),vec.end());
    // int i=0;
    // int j=nums.size()-1;
    // while(i<j){
    //     if(vec[i].first+vec[j].first==target)return {vec[i].second,vec[j].second};
    //     else if(vec[i].first+vec[j].first<target){i++;}
    //     else{j--;}
    // }
    // return {-1,-1};  ------>Tc->O(NlogN)and SC--->O(N)

     // with map and complement 
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int complement=target-nums[i];
        if(mp.find(complement)!=mp.end()){
            return {i,mp[complement]};
        }
        mp[nums[i]]=i;
    }
       return {-1,-1}; // -----> TC->O(N) and map lookups are O(1) and SC->O(N)
    }
};