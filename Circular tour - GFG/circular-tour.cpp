// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{ 
    private:
    int solve(int ind,int n,int amount,petrolPump p[]){ 
        int j=ind-1;
        while(ind!=j){
            amount+=p[ind].petrol;
            amount-=p[ind].distance;
            if(amount<=0)
            return 0;
            ind=(ind+1)%n;
        }
        return 1;
    }
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here   
       int ptr=0; 
       int dis=0;
       for(int i=0;i<n;++i){
           dis+=p[i].petrol-p[i].distance;
        //   dis+=p[i].distance;
       } 
       int bal=0; 
       int start=-1;
    if(dis<0) return -1; 
       int lackamount=0;
       for(int i=0;i<n;++i){  
           if(start==-1)
           start=i;
           bal+=p[i].petrol-p[i].distance;
           if(bal<0){ 
               lackamount+=bal;
               start=-1;
               bal=0;
           }
       }
       return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends