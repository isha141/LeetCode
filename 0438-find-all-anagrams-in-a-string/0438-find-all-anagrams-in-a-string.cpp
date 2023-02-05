class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans; 
        map<char,int>mp1,mp2;
        for(auto itr: p){
            mp1[itr]++;
        }
        int n=s.size();
        int m=p.size();
        if(n<m) return ans;
        int i=0;
        while(i<m){
            mp2[s[i]]++; 
            i++;
        }
        int j=i;
        while(j<n){
            if(mp1==mp2){
                ans.push_back(j-m);
            }
            mp2[s[j]]++;
            mp2[s[j-m]]--;
            if(mp2[s[j-m]]==0){
                mp2.erase(s[j-m]);
            }
            j++;
        } 
        // for(auto itr: mp2)
            // cout<<itr.first<<" "<<itr.second<<endl;
        if(mp1==mp2){
            ans.push_back(j-m);
        }
        return ans;
    }
};