class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res=blocks.length();

        for(int i=0;i<=blocks.length()-k;i++)
        {
            int nblock=0;
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j] == 'W')
                    nblock++;
                
            }
            res = min(res,nblock);
        }
        return res;
    }
};