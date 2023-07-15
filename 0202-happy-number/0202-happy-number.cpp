class Solution {
public:
    bool isHappy(int n) { 
             if(n==1) return 1;
           if(n==2) return 0;
        if(n==3) return 0; 
         map<int,int>mp;
          while(1){
               if(mp.find(n)!=mp.end())
                   break;
              mp[n]++;
              int temp=n; 
              int sum=0;
              while(temp!=0){
                  int res=temp%10; 
                  sum+=(res*res);
                  temp/=10;
              }
              n=sum; 
              
          }
        if(n==1) return 1; 
        return 0;
    }
};