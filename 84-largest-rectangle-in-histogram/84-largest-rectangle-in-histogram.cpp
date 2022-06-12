class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n);
        vector<int>right(n);
        int ans=0;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                left[i]=0;
            else
                left[i]=s.top()+1;
           s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int j=n-1;j>=0;j--){
            while(!s.empty() && heights[s.top()]>=heights[j])
                s.pop();
            if(s.empty())
                right[j]=n-1;
            else
                right[j]=s.top()-1; 
            s.push(j);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]+1)*heights[i]);
        }
        return ans;
     }
};