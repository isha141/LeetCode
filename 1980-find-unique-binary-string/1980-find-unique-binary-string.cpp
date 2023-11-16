class Solution {
    private:
    int n;
    string ans="";
    set<string>st;
    bool solve(int i,int n,string &temp){
        if(temp.size()==n){
             // cout<<temp<<"-->"<<endl;
            if(st.find(temp)==st.end()){
                  ans=temp;
                return 1;
            }
            return 0;
        }
        if(temp.size()>n) return 0;
        temp+='0';
        if(solve(i+1,n,temp))
             return 1;
        temp.pop_back();
        temp+='1';
        if(solve(i+1,n,temp))
              return 1;
        temp.pop_back();
        return 0;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
          n=nums.size();
          for(auto itr: nums){
              st.insert(itr);
          }
          string temp="";
          solve(0,n,temp);
          return ans;
    }
};