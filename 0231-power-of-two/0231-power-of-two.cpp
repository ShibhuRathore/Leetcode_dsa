class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0,flag=0;
        while(pow(2,i)<=n)
        {
            if(pow(2,i)==n)
                flag++;
            i++;
        }
        if(flag==1)
            return true;
            
        else
            return false;

    }
};