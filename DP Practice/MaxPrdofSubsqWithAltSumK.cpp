// P.Link - https://leetcode.com/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/description

const int MIN=-5000;
class Solution {
public: 
    // flag=0 -> not picked yet (just starting)
    // flag=1 -> this index would contribute + to sum
    // flag=2 -> this index would contribute - to sum

    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int,int>>>> dp;
    int rec(int ind, int sum, int flag, int prd, int k, int limit, vector<int>& nums) {
        // pruning
        // if(prd>limit) return MIN;

        // base case
        int n=nums.size();
        if(ind==n) {
            if(sum==k && prd<=limit && flag!=0)  return prd;
            else return MIN;
        }

        // caching
        if(dp.count(ind) && dp[ind].count(sum) && dp[ind][sum].count(prd) && dp[ind][sum][prd].count(flag)) {
            return dp[ind][sum][prd][flag];
        }

        // transitions
        int ans = rec(ind+1,sum,flag,prd,k,limit,nums);  // not pick
        if(flag==0){
            ans=max(ans, rec(ind+1,sum+nums[ind],2,nums[ind], k,limit,nums));
        } else if(flag==1) {
            ans=max(ans, rec(ind+1,sum+nums[ind],2,min(prd*nums[ind],limit+1), k,limit,nums));
        }
        else if(flag==2) {
            ans=max(ans, rec(ind+1, sum-nums[ind],1,min(prd*nums[ind],limit+1),k,limit,nums));
        }

        return dp[ind][sum][prd][flag]=ans;
    }

    int maxProduct(vector<int>& nums, int k, int limit) {
        int n=nums.size();

        int sum=0;
        for(auto x:nums)  sum+=x;

        if(k>sum || k<-sum)  return -1;

        dp.clear();
        int ans=rec(0,0,0,0,k,limit,nums);
        return ((ans==MIN)?-1:ans);

    }
};
