class Solution {
public:
    int bestClosingTime(string& customers) {
        // int penalty =INT_MAX;
        // int ans=INT_MAX;
        // int close=0;
        // while(close<=customers.size()){
        //     int current_penalty=0;
        //     // till close 
        //     for(int i=0;i<close;i++){
        //         if(customers[i]=='N'){current_penalty++;}
        //     }
        //     // after close ;
        //     for(int i=close;i<customers.size();i++){
        //         if(customers[i]=='Y'){current_penalty++;}
        //     }
        //     if(current_penalty<penalty){
        //         penalty=current_penalty;
        //         ans=close;
        //     }
        //     close++;
        // }
        // return ans;
        int currpenalty=0;
        int minpenalty=0;
        int ans=0;
        int close=0;
        while(close<customers.size()){
            if(customers[close]=='Y')currpenalty--;
            else{
                currpenalty++;
            }
            if(currpenalty<minpenalty){
                minpenalty=currpenalty;
                ans=close+1;
            }
            close++;
        }
        return ans;
    }
};