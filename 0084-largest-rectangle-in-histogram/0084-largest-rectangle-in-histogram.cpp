class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>s;
        for(int i=0;i<n;++i){
            while(!s.empty() && heights[s.top()]>=heights[i])
                 s.pop();
            if(s.size()){
                left[i]=s.top()+1;
            }
            else{
                left[i]=0;
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.size())
                 right[i]=s.top()-1;
            else{
                right[i]=n-1;
            }
            s.push(i);
        }
        for(int i=0;i<n;++i){
            int width=right[i]-left[i]+1;
            ans=max(ans,width*heights[i]);
        }
         return ans;
    }
};