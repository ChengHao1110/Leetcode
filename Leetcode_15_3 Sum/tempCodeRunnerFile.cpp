    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(i >= 1 && nums[i] == nums[i - 1]) continue;
            int target = -1 * nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j != k){
                if((nums[j] + nums[k]) == target){
                    //put ans
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    ans.push_back(triplet);
                    j++;
                }
                else if((nums[j] + nums[k]) > target){
                    k--;
                }
                else if((nums[j] + nums[k]) < target){
                    j++;
                }
            }
        }
        return ans;
    }