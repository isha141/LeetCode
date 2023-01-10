class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int ans=1e9;
        map<int,int>mp;
        int i=0;
        int j=0;
        while(j<n){
            if(mp.find(cards[j])==mp.end()){
                mp[cards[j]]++;
                j++;
            }
            else{
                ans=min(ans,j-i+1); 
                mp[cards[j]]++;
                while(i<j && mp[cards[j]]>=2){
                    mp[cards[i]]--; 
                    if(mp[cards[i]]==0)
                        mp.erase(cards[i]);
                    ans=min(ans,j-i+1);
                    i++;
                }
                j++;
            }
        } 
        if(ans==1e9) return -1;
        return ans;
    }
};
