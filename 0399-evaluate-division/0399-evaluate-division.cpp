class Solution { 
    private:
   double solve(string a,string &b,map<string,map<string,double>>&mp,set<string>&st){ 
       if(mp[a].find(b)!=mp[a].end())
           return mp[a][b];
       // double temp=1.0000;
        for(auto itr: mp[a]){
            double t=itr.second;
            if(st.find(itr.first)==st.end()){
                 st.insert(itr.first); 
                double temp=solve(itr.first,b,mp,st);
                if(temp){
                    mp[a][b]=temp*itr.second;
                    return mp[a][b];
                }
            }
        }
        return 0.0000;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& va, vector<vector<string>>& q) {
       map<string,map<string,double>>mp;
        int n=eq.size();
        for(int i=0;i<n;++i){
            mp[eq[i][0]][eq[i][1]]=va[i];
            mp[eq[i][1]][eq[i][0]]=1/va[i];
        } 
        // for(auto itr: mp){
        //     for(auto it: itr.second){
        //         cout<<itr.first<<" "<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        vector<double>ans;
        for(int i=0;i<q.size();++i){
            set<string>st;
            double c=1.0000;
            double temp=solve(q[i][0],q[i][1],mp,st);
            if(temp==0)
            ans.push_back(-1.0000);
            else
            ans.push_back(temp);
        }
        return ans;
    }
};