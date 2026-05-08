class Solution {
public:
    int maxProfit(vector<int>& prices) {
       /*int maxprofit=0;
       for(int i=0;i<prices.size();i++)
       {
        for(int j=i+1;j<prices.size();j++)
        {
            int profit=0;
            if(prices[j]>prices[i])
            {
                profit= prices[j]-prices[i];
                maxprofit = max(profit,maxprofit);
            }
        }
       }
       return maxprofit;*/
       
       int l=0,r=1;
       int maxprofit=0;

        while(r<prices.size())
        {
            int profit=0;
            if(prices[r]>prices[l])
            {
                profit = prices[r]-prices[l];
                maxprofit = max(profit,maxprofit);
            }
            else
                l=r;
            r++;
        }
        return maxprofit;
    }
};
