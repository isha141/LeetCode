class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int n=token.size();
        int score=0;
        sort(token.begin(),token.end());
        int i=0; 
        int ans=0; 
        int j=n-1;
        while(i<=j){
            if(token[i]<=power){
                power-=token[i];
                score++;
                ans=max(ans,score); 
                i++;
                // continue;
            }
            else if(score>=1){
                power+=token[j];
                j--;
                score--;
            }  
            else
                return score;
            // cout<<i<<" "<<j<<endl;
            // i++;
        } 
        ans=max(ans,score);
        return ans;
    }
};