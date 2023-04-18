class Solution { 
    private:
    
public:
    int shortestSequence(vector<int>& r, int k) {
        int n=r.size(); 
        set<int>s; 
        int ans=1;
        for(int i=0;i<n;++i){
            s.insert(r[i]);
            if(s.size()==k){
                ans+=1;
                s.clear();
            }
        }
        return  ans;
    }
};