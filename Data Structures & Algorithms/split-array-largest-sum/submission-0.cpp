class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        long long high =0;

        for(int n:nums)
        {
            low = max(low,n);
            high += n;

        }

        while(low<high)
        {
            long long mid = low+(high-low)/2;

            long long cursum=0;
            int parts=1;

            for(int n:nums)
            {
                if(cursum+n > mid)
                {
                    parts++;
                    cursum =0;
                }
                cursum += n;
            }

            if(parts <= k)
                high =mid;
            else
                low =mid+1;
        }
        return low;
    }
};