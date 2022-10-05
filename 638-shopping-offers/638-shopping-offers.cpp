class Solution { 
    private:
    int direc(vector<int>&price,vector<int>&needs){
        int ans=0;
        for(int i=0;i<needs.size();++i)
            ans+=price[i]*needs[i];
        return ans;
    }
    private:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,map<vector<int>,int>&mp)
    {
        int mini=direc(price,needs);  
        if(mp.find(needs)!=mp.end())
            return mp[needs];
        for(int i=0;i<special.size();++i){
            vector<int>temp;
            vector<int>offer=special[i];
            for(int j=0;j<needs.size();++j){
                if(offer[j]>needs[j]){
                    temp.clear();
                    break;
                }
                temp.push_back(abs(offer[j]-needs[j]));
            } 
            if(!temp.empty()){
                mini= min(mini,offer[offer.size()-1]+solve(price,special,temp,mp));
            }
        }
        return mp[needs]=mini;
    } 
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) { 
        map<vector<int>,int>mp;
        return solve(price,special,needs,mp);
    }
};