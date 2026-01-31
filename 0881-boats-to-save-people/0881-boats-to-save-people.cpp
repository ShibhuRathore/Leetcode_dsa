class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
         if(people.size()==0||limit==0)return 0;
        int count=0;
        while(i<=j){
            if(people[i]>limit||people[j]>limit)return -1;
           int sum=people[i]+people[j];
           if(sum>limit){count++;
           j--;}
            else{
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
};