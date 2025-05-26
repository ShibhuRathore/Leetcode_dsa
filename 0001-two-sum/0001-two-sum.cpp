class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<pair<int,int>> numswithindex;
        for(int i =0;i<nums.size();i++){
            numswithindex.push_back({nums[i],i});
        }
        sort(numswithindex.begin(),numswithindex.end());
      int i=0;
      int j=nums.size()-1;
          vector<int> ans;
      while(i<j){
       int sum=numswithindex[i].first+numswithindex[j].first;
       if(sum<target){
        i++;
       } 
       else if(sum>target){
        j--;
       }
       else{
    
        ans.push_back(numswithindex[i].second);
        ans.push_back(numswithindex[j].second);
        return ans;
       }
      }
      return ans;
    }
};