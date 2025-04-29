class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int num : nums)
        {
            mp[num]++;
        }

        // creating bucket
        vector<vector<int>> buckets(n+1);
        for(auto& [num, count] : mp)
        {
            buckets[count].push_back(num);
        }

        // collecting top k frequent elements
        for(int i=buckets.size()-1; i>=0 && ans.size()<k; i--)
        {
            for(int num : buckets[i])
            {
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};