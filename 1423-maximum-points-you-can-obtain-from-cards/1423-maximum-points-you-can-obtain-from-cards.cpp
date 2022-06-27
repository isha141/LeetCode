class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int ans=0;
        int n=card.size();
        vector<int>presum(n+1,0);
        vector<int>postsum(n+1,0); 
        //presum[0]=card[0]; 
        int sum=0;
        for(int i=0;i<n;++i)
        {
                sum+=card[i];
                presum[i+1]=sum;
        }
        reverse(card.begin(),card.end());
        sum=0;
        for(int i=0;i<n;i++){
             sum+=card[i];
             postsum[i+1]=sum;
        }  
        for(int i=0;i<n;++i)
            cout<<presum[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;++i)
            cout<<postsum[i]<<" ";
        cout<<endl;
        // k=k-1;
        for(int i=0;i<=k;++i){
            ans=max(ans,presum[i]+postsum[k-i]);
        } 
        return ans;
    }
};