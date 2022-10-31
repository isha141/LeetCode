class Solution {
public:
    string minWindow(string s, string t) {
       int ans=1e9;
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>mps,mpt;
        for(auto itr: t)
            mpt[itr]++;
        int count=0;  
        int l=0;
        int r=n;
        int target=t.size();
        while(j<n){ 
            mps[s[j]]++;
            if(mpt.find(s[j])!=mpt.end()){
                if(mpt[s[j]]>=mps[s[j]])
                    count++;
            }
            if(count==target){ 
                int  temp=j-i; 
                // cout<<i<<" "<<j<<endl;
                if(ans>temp){
                    ans=temp;
                    l=i;
                    r=j;
                }
                while(count==target && i<=j){
                    mps[s[i]]--;  
                     i++;
                    if(mpt.find(s[i-1])!=mpt.end()){
                        if(mps[s[i-1]]<mpt[s[i-1]]){
                            count-=1; 
                            continue;
                        }
                    }  
                 // cout<<i<<" "<<j<<endl;
                    int temp=(j-i);
                     if(ans>temp){
                         ans=temp;
                         l=i;
                         r=j;
                     }
                   
                }
            }
            j++;
        } 
        if(ans==1e9)
            return "";
        return s.substr(l,r-l+1);
    }
};