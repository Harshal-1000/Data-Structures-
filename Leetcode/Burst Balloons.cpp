   class Solution {
        public:
            int pre(int i,int j,vector<int> & nums){
                if(i > j) return 0;
                long mini = -1e9; // int error ⭐
                for(int ind=i;ind<=j;ind++){ // ind < j error ⭐
                    long burst = nums[i-1]*nums[ind]*nums[j+1] + pre(i,ind-1,nums)+pre(ind+1,j,nums);
                    mini = max(mini,burst);
                }
                return mini;
            }
            
            int maxCoins(vector<int>& nums) {
                int c = nums.size();
                nums.insert(nums.begin(),1);
                nums.push_back(1);
                return pre(1,c,nums); // c + 2 => giving error ⭐
            }
        };
    
    // memo
        class Solution {
        public:
            int pre(int i,int j,vector<int> & nums,vector<vector<int>> &dp){
                if(i > j) return 0;
                if(dp[i][j] != -1) return dp[i][j];
                
                long mini = -1e9;
                for(int ind=i;ind<=j;ind++){
                    long burst = nums[i-1]*nums[ind]*nums[j+1] + pre(i,ind-1,nums,dp)+pre(ind+1,j,nums,dp);
                    mini = max(mini,burst);
                }
                return dp[i][j] = mini;
            }
            
            int maxCoins(vector<int>& nums) {
                int c = nums.size();
                nums.insert(nums.begin(),1);
                nums.push_back(1);
                
                vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
                return pre(1,c,nums,dp);
            }
        };
    
    // tab
        class Solution {
        public:
            int maxCoins(vector<int>& nums) {
                int c = nums.size();
                nums.insert(nums.begin(),1);
                nums.push_back(1);
                
                vector<vector<int>> dp(c+3,vector<int> (c+3,0)); // wrong declaration
                
                for(int i=c;i>=1;i--){ // wrong intialied for loop 
                    for(int j=1;j<=c;j++){ // wrong intiated for loop
                        if(i > j) continue;
                        long mini = -1e9;
                        for(int ind=i;ind<=j;ind++){
                            long burst = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+ dp[ind+1][j];
                            mini = max(mini,burst);
                        }
                        dp[i][j] = mini;
                    }
                }
                
                return dp[1][c];
            }
        };
