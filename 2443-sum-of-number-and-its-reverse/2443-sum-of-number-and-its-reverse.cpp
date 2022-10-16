class Solution { 
    private:
    int reverse(int i)
    {
        int ans=0;
        while(i!=0){
            int rem=i%10;
            ans=ans*10+rem;
            i/=10;
        }
        return ans;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0)
            return 1;
        for(int i=1;i<=num;++i){
            int temp=reverse(i);
            if(i+temp==num)
                return 1;
        }
        return 0;
    }
};