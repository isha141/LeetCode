class Solution {
public:
    bool validateStackSequences(vector<int>& ps, vector<int>& po) {
        int n=ps.size();
        stack<int>s;
        int i=0;
        int j=0;
        if(ps.size()!=po.size())
            return 0;
        while(i<n && j<n )
        {
            bool flag=0;
            while(i<n && ps[i]!=po[j]){
                s.push(ps[i++]); 
                flag=1;
            }
            // cout<<i<<" "<<j<<endl;
            if (i<n && ps[i]==po[j]){
                i++;
                j++; 
                flag=1;
            }
            while(s.size() && s.top()==po[j]){
                s.pop();
                j++; 
                flag=1;
            }
            if(i>=n && j>=n && s.size()==0)
                return 1; 
            if(!flag)
                return 0; 
            
        } 
        return 0;
        
    }
};