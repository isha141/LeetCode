class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
       queue<int>q; 
        int n;
        q.push(start);
    vector<bool>vis(1001,0);
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--){
                int temp=q.front();
                   q.pop();  
                if(temp==goal) return ans;
                if(temp<0 || temp >1000 || vis[temp])  continue;
                vis[temp]=1;
                for(auto itr : nums){
                    q.push(temp+itr);
                    q.push(temp-itr);
                    q.push(temp^ itr);
                    
                }
            }
            ans++;
        }
        return -1;
        }
};