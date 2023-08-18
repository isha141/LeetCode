class Solution { 
    int solve(vector<int>&a,vector<int>&b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       vector<int>ans;
      ans.push_back(solve(p1,p2));
      ans.push_back(solve(p1,p3));
      ans.push_back(solve(p1,p4));
      ans.push_back(solve(p2,p3));
      ans.push_back(solve(p2,p4));
      ans.push_back(solve(p3,p4));
     map<int,int>mp;  
        bool flag=0,flag1=0;
        for(auto itr: ans){
            mp[itr]++;
        }
         if(mp.size()!=2)
              return 0;
        for(auto itr: mp){
            if(itr.first==0)
                 return 0;
            if(itr.second==4)
                flag=1;
            if(itr.second==2)
                 flag1=1;
        }
         return (flag & flag1);
    }
};