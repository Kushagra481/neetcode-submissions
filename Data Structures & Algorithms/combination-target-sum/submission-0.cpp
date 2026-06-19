class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dfs(0,{},0,target,nums);
        return res;
    }
    void dfs(int i,vector<int> curr,int total,int target,vector<int>& nums){
        if(total == target){
            res.push_back(curr);
        }
        for(int j = i;j<nums.size();j++){
            if(nums[j]+total>target){
                return;
            }
            //recursive call
            curr.push_back(nums[j]);
            dfs(j,curr,total+nums[j],target,nums);
            curr.pop_back();

        }
    }
};
