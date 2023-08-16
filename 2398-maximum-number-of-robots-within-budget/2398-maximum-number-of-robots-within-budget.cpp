class Solution { 
    int n;
    long long ok(int mid,vector<int>&charge,vector<int>&run){
        if(mid==0)
             return INT_MIN;
        long long mini=LONG_MAX;
        deque<long long>q;
        map<long long,long>mp;
        long long sum=0;
        for(int i=0;i<mid;++i){
            sum+=run[i];
            while(!q.empty() && charge[q.back()]<=charge[i])
                q.pop_back();
            q.push_back(i);
        }
        mini=min(mini,1ll*charge[q.front()]+mid*sum);
        for(int i=mid;i<n;++i){
            sum-=run[i-mid];
            sum+=run[i];
            while(!q.empty() && q.front()<=i-mid)
                q.pop_front();
            while(!q.empty() && charge[q.back()]<=charge[i])
                q.pop_back();
            q.push_back(i);
            // while(!q.empty() && mp[pq.top()]==0)
            //     pq.pop();
            mini=min(mini,1ll*charge[q.front()]+mid*sum);
        }
        return mini;
        
    }
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long bud) { 
          n=charge.size();
        long long low=0; 
        long long high=n; 
        int ans=0;
          while(low<=high){
             long long mid=(low+high)>>1;
              long long temp=ok(mid,charge,run);
               if(temp<=bud){
                   ans=mid;
                   low=mid+1;
               }
              else{
                  high=mid-1;
              }
         }
        return ans;
    }
};