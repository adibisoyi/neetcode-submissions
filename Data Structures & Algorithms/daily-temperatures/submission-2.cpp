class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> res(n,0);

        for(int i=0;i<n;i++)
        {
           int j=i+1;
           while(temperatures[i] >= temperatures[j] && j<n)
           {
                j++;
           }
           
            if(temperatures[j] > temperatures[i] && j<n)
                res[i] = j-i; 
                
        }
          
        
        return res;
    }
};
