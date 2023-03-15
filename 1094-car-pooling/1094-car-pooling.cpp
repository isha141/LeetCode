class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int cap) {
        int n=t.size();
        sort(t.begin(),t.end(),[&](vector<int>a,vector<int>b){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            else
                return a[1]<b[1];
        });
        int curr=0; 
        map<int,int>mp;
        int j=0;
        for(int i=0;i<=1000 && j<n;++i){
            if(mp.find(i)!=mp.end()){
                curr-=mp[i]; 
                mp.erase(i);
            } 
             int start=t[j][1];
            int end=t[j][2];
            int pass=t[j][0];
            if(i<start) continue; 
            while(j<n && i==t[j][1]){
                 int start=t[j][1];
              int end=t[j][2];
               int pass=t[j][0];
             if(curr+pass<=cap){
                 mp[end]+=pass; 
                curr+=pass;
             }
             else
                  return 0;
            j++;
            }
        }
        return 1;
    }  
};