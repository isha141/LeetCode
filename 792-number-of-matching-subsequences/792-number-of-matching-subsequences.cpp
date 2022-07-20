class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        vector<vector<int>>ds(26);
        for(int i=0;i<s.size();++i)
            ds[s[i]-'a'].push_back(i);
        int prev=-2;
        for(auto itr: words){ 
            prev=-1;
            bool flag=1; 
            
            
            for(auto itt: itr){
                auto ind=upper_bound(ds[itt-'a'].begin(),ds[itt-'a'].end(),prev);
                if(ind==ds[itt-'a'].end()){
                    flag=0; 
                break;
            } 
                prev=*ind;
            } 
            
            if(flag) 
                count++;
        }
        return count;
    }
};