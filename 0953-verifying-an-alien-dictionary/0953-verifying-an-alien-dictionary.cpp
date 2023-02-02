class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int i=0;
        map<char,int>mp;
        for(auto itr: order)
            mp[itr]=i++;
        int maxi=0;
        for(int i=0;i<words.size()-1;++i){
            string a=words[i];
            string b=words[i+1];
            int k=0;
            int l=0;
            while(k<a.size() && l<b.size() && a[k]==b[l]){
                maxi=max(mp[a[k]],maxi);
                k++;
                l++;
            } 
            if(k>=a.size() && l>=b.size()){
                continue;
            }
            if(k>=a.size()) {
                k--; 
               continue;
             }
            else if(l>=b.size()) {
                l--; 
                if(a[k]==b[l]) return 0;
            if(mp[a[k]]<mp[b[l]])
                return 0; 
                continue;
            }
            if((mp[a[k]]>mp[b[l]]) )
                return 0;
            maxi=max(maxi,mp[b[l]]);
        }
        return 1;
         
    }
};