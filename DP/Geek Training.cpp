class Solution{
private:
    int max_points(vector<vector<int>>& arr,int n, int index,vector<vector<int>>&dp){
        int m=arr[0].size();
        for(int i=0;i<m;i++){
            dp[0][i]=arr[0][i];
            }
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                int maximum=INT_MIN;
                for(int k=0;k<m;k++){
                    if(k!=j){
                          maximum=max(maximum,dp[i-1][k]);
                    }
                }
                dp[i][j]=maximum+arr[i][j];
            }
        }
            int final=INT_MIN;
            for(int i=0;i<m;i++){
                final=max(final,dp[n][i]);
                
            }
            return final;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return max_points(arr,n-1,-1,dp);
    }
};
