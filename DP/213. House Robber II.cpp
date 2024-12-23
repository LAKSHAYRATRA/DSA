class Solution {
    private:
        int max_profit(vector<int>nums){
            int prev2=0;
            int prev=nums[0];
            int temp;
            for(int i=1;i<nums.size();i++){
                int pick=nums[i]+prev2;
                int not_pick=prev;
                temp=max(pick,not_pick);
                prev2=prev;
                prev=temp;
            }
            return temp;
        }
    public:
        int rob(vector<int>& nums) {
            vector<int>temp1;
            vector<int>temp2;
            if(nums.size()==2)return max(nums[0],nums[1]);
            for(int i=0;i<nums.size();i++){
                if(i!=0)temp1.push_back(nums[i]);
                if(i!=nums.size()-1)temp2.push_back(nums[i]);
            }
            if(nums.size()==1)return nums[0];
            return max(max_profit(temp1),max_profit(temp2));
        }
};
