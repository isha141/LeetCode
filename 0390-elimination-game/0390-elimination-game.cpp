class Solution { 
    private:
    long long solve(int n,int step,long long head,int diff,bool left){
        
        while(n>1){
            if( left || (n&1))
                head+=diff;
             diff*=2;
            // step+=1;
            left=(1^left);
            // cout<<left<<" ";
            n/=2;
        }
        return head;
    }
public:
    int lastRemaining(int n) { 
        int step=1; 
        long long head=1; 
        long long diff=1; 
        bool left=1;
        return solve(n,step,head,diff,left);
    }
};