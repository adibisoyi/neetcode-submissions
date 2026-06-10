class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int  low=0,high=0;

       for(int w:weights)
       {
            low = max(low,w);
            high += w;
       } 

       while(low<high)
       {
            int mid = low+(high-low)/2;
            int useddays = 1;
            int curWeight =0;

            for(int w: weights)
            {
                if(curWeight+w>mid)
                {
                    useddays++;
                    curWeight=0;
                }
                curWeight += w;
            }

            if(useddays <= days)
                high =mid;
            else
                low =mid+1;
       }
       return low;
    }
};