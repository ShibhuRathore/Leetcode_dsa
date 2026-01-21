// step1-> make space for incoming element in the window size of k
// step2-> if the new coming element is greater than dq.back() remove it by using while loop
// step3-> insert the element
// step4-> if i>=k-1 start pushing the front of deque into the result 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int>dq;
    vector<int>ans;
    for(int i =0;i<nums.size();i++){
        while(!dq.empty()&&dq.front()<=i-k)dq.pop_front();
        while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();
        dq.push_back(i);
        if(i>=k-1)ans.push_back(nums[dq.front()]);
    }
    return ans;
    }
};
