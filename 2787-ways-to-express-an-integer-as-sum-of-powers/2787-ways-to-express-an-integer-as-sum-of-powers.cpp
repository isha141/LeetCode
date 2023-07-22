// class Solution {
//     int power(int num,int n){
//         if(n==0)return 1;
//         return n==0?1:num*power(num,n-1);
//         // else if(n%2==0)return power(num,n/2)*power(num,n/2);
//         // else{
//         //     return num*power(num,n/2)*power(num,n/2);
//         // }
//     }
//     // int res=0;
//     // int number(int num,int x,int k,int n){
//     // // int res=0;
//     // //     int p=power(t,x);
//     // //     while(p+k<n){
//     // //         res+=number(n,x,t+1,p+k);
//     // //         t++;
//     // //         p=power(t,x);
//     // //     }
//     // //     if(p+k==n){
//     // //         res++;
//     // //     }
//     // //     return res;
//     //     if(x==0)res++;
//     //     int r=(int)floor(pow(num,1.0/n));
//     //     for(int i=k+1;i<=r;i++){
//     //         int a=x-(int)pow(i,n);
//     //         if(a>=0){
//     //             number(num,x-(int)pow(i,n),i,n);
//     //         }
//     //     }
//     //     return res;
//     // }
//     int geta(int r,int p,int b){
//         int res=pow(b,p);
//         if(r==res)return 1;
//         if(r<res)return 0;
//         int x=geta(r-res,p,b+1);
//         int y=geta(r,p,b+1);
//         return x+y;
//     }
//     int count(int x,int n,vector<int>&v){
//         int s=0;
//         for(int vec:v){
//             s+=power(vec,n);
//         }
//         if(s==x)return 1;
//         else{
//             int ans=0;
//             int vec=v.empty()?1:v.back()+1;
//             while(s+power(vec,n)<=x){
//                 v.push_back(vec);
//                 ans+=count(x,n,v);
//                 v.pop_back();
//                 vec++;
//             }
//             return ans;
//         }
//     }

// public:
//     int numberOfWays(int n, int x) {
//         int t=1;
//         int k=0;
//         //int p=number(n,n,0,x);
//         //int p=geta(n,x,1);
//         vector<int>v;
//         return count(n,x,v);
//         //return p;
        
//     }
//     };



long long d[303][303];
//long long dp[303][303]; 
class Solution {
     int mode=1e9+7;
      int solve(int i,int n,int x,long sum,vector<int>&vi){ 
             if(sum==n) { 
                   return 1; 
             }
             if(sum>n)
                   return 0;   
             if(i>n) return 0;  
            if(d[i][sum]!=-1) 
                  return d[i][sum];
           long long  res=pow(i,x);
           long long  le=0;
           long long  ri=0;
          if(vi[i]==0){ 
             vi[i]=1;
                     le=solve(i+1,n,x,sum+res,vi);  
              vi[i]=0;
          } 
           ri=solve(i+1,n,x,sum,vi);
           return d[i][sum]=(le+ri)%mode;
           
      }
public:
    int numberOfWays(int n, int x) {  
          vector<int>vi(n+1,0);
          memset(d,-1,sizeof(d));
           return solve(1,n,x,0,vi);  
    }
};