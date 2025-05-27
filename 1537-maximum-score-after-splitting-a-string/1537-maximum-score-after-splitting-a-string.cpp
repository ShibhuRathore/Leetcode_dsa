class Solution {
public:
    int maxScore(string s) {
        int oneseen=0;
        int score=0;
        int totalone=0;
        int maxscore=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                totalone++;
            }
        }

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                score++;
            }
            else{
                oneseen++;
                
            }
            maxscore=max(maxscore,score+totalone-oneseen);
        }
        return maxscore;
    }
};