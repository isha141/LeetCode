//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 

class Solution { 
    private:
    int mod=100000;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>pq;
        pq.push({start,0}); 
        unordered_map<int,int>mp;
        for(auto itr: arr)
        mp[itr]++;
        int ans=1e9; 
        vector<int>dis(100000,1e9);
        dis[start]=0;
        while(!pq.empty()){ 
              int n=pq.size();
               while(n--){
                auto itr=pq.front();
                pq.pop(); 
                int val=itr.first; 
                 int steps=itr.second; 
                //  cout<<val<<":::"<<steps<<endl;
                if(val==end){
                    ans=min(ans,steps); 
                    return ans;
                }
                // if(val>end) continue;
                for(auto it: arr){ 
                    int ans=(it*val)%mod;
                    if(dis[ans]>steps+1){
                    pq.push({ans,steps+1}); 
                    dis[ans]=steps+1;
                    }
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends