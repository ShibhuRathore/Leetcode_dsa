class Solution 
{

    void helper(vector<int>& nums , int index , int& size , vector<vector<int>>& ans , vector<int>& curr)
    {
        // base case 
        if(index == size)
        {
            ans.push_back(curr);
            return;
        }

        // pick up the current element
        curr.push_back(nums[index]);
        helper(nums , index + 1 , size , ans , curr);
        curr.pop_back();

        // not pick up
        // while not picking up skip all the duplicates of the element you are not picking up 
        int j = index;
        while (j < nums.size() && nums[j] == nums[index]) {
            j++;
        }
        helper(nums, j, size, ans, curr);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int size = nums.size();
        vector<int> temp;
        helper(nums , 0 , size , ans , temp);

        return ans;
    }
};