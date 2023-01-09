class Solution {
    private:
    int distance(vector<int>&p1,vector<int>&p2){
        return (p2[0]-p1[0])*(p2[0]-p1[0])+ (p2[1]-p1[1])*(p2[1]-p1[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int>ans={
            distance(p1,p2),
            distance(p1,p3),
            distance(p1,p4),
            distance(p2,p3),
            distance(p2,p4),
            distance(p3,p4),
        }; 
        for(auto itr: ans) cout<<itr<<" ";
        cout<<"*****";
       map<int,int>mp;
       for(auto itr: ans)
           mp[itr]++; 
        // cout<<mp.size()<<endl;
        if(mp.size()!=2) return 0;
        int c=0;
        int c2=0;
        for(auto itr: mp){ 
             if(itr.first==0) return 0;
            if(itr.second==4)
                c=1;
            if(itr.second==2)
                c2=1; 
            cout<<itr.second<<endl;
        }
        return c& c2;
    }
};