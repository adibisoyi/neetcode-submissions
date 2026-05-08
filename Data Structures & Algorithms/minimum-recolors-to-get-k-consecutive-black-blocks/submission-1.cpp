class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wcount=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i] == 'W')
                wcount++;
        }
        int res = wcount;
        for(int i=k;i<blocks.length();i++)
        {
            if(blocks[i-k] == 'W')
                wcount--;
            if(blocks[i]=='W')
                wcount++;
            
            res = min(res,wcount);
        }

        return res;
    }
};