class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) { 
        vector<pair<int,int>>ans; 
        stack<pair<int,char>>st; 
        int n=pos.size(); 
        vector<pair<int,int>>ds;
        for(int i=0;i<n;++i){
            ds.push_back({pos[i],i});
        }
        sort(ds.begin(),ds.end());
        for(int j=0;j<n;++j){
            int i=ds[j].second;
            char ch=dir[i];
            while(ch=='L' && !st.empty() && st.top().second!=ch){
                auto itr=st.top();
                st.pop();
                int ind=itr.first;
                if(h[ind]>h[i]){
                    h[ind]-=1;
                    h[i]=0;
                    st.push(itr);
                    break;
                } 
                else if(h[ind]==h[i]){
                    h[i]=0;
                    break;
                }
                else{
                    h[i]-=1;
                }
            }
            if(h[i]!=0){
                st.push({i,ch});
            }
        }
        while(!st.empty()){
            auto itr=st.top();
            st.pop();
            ans.push_back({itr.first,h[itr.first]});
        }  
        vector<int>res;
        sort(ans.begin(),ans.end());
        for(auto itr: ans){
            res.push_back(itr.second);
        }
        // reverse(ans.begin(),ans.end());
        return res;
    }
};