class Compare
{
public:
    bool operator() (pair<int,char>&a, pair<int,char>&b)
    {
        if(a.first!=b.first)
        return a.first<b.first;
       else
        return a.second>b.second;
    }
};
class Solution { 
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int>mp;
        for(auto itr: s)
        mp[itr]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>,Compare>pq;
        for(auto itr: mp){
        pq.push({itr.second,itr.first});
        }
        string ans="";
        while(!pq.empty()){
            char ch=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            ans.append(val,ch);
        }
        return ans;
    }
};