class Solution {
public:
//used of bitset for space optimisation u could have used vector<vector<bool>>too...............


//Points to rememeber - Mistakes happening

//1-bitwise and to be zero means no two 1's are overlapping on same position means no character same

//2-why not previous lens of store[i].count() formula is used coz think may be in one word 2 letter are occured but in bitset they will be marked only once so if u count the freq of ones in bitset the count will be missed right so answer will come less
//as there is only condition that 2 different words should not have overlapping words but a single words can contain same letter more than one time.....
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<bitset<26>>store;
        for(int i=0;i<n;i++){
            bitset<26>b;
            for(auto x:words[i]){
                b.set(x-'a');
            }
            store.push_back(b);
        }
        int maxpro=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((store[i]&store[j])==0){
                    //int lens=(store[i].count())*(store[j].count());
                    int lens=(words[i].size())*(words[j].size());
                    maxpro=max(maxpro,lens);
                }
            }
        }
        return maxpro;
        
    }
};