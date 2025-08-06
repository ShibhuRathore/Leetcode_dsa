class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
     bool placed=false;
     int unplaced=0;
     int i=0;
     int j=0;
     int n=fruits.size();
     vector<bool>vis(n,false);
     while(i<n){
        placed=false;
        while(j<n){
            if(vis[j]==false&&fruits[i]<=baskets[j]){
                placed=true;
                vis[j]=true;
                break;
            }
            j++;
        }
        if(!placed)unplaced++;
        i++;
        j=0;
     }
      return unplaced;
    }
};