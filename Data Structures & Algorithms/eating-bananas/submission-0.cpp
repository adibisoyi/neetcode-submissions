class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right = *max_element(piles.begin(),piles.end());
        int best=0;
        while(left<=right)
        {
            int k = (left+right)/2;

            long long sum =0;
            for(auto x:piles)
            {
                sum += ceil(static_cast<double>(x)/k);
            }
            if(sum <= h)
            {
                best=k;
                right = k-1;
            }
            else
                left=k+1;
        }
        return best;
    }
};
