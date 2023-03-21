class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int res=0,cnt =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                cnt++;
            else
            {
                res += ((cnt)*(cnt+1))/2;
                cnt =0;
            }
        }
         res += ((cnt)*(cnt+1))/2;
        return res;
    }
};