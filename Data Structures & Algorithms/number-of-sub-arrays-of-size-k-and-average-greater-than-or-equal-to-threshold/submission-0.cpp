class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int sum=0;int res=0;
        for(int i=0;i<k;i++)
        {
            sum += arr[i];
        }

        if((int)(sum/k) >= threshold)
                res++; 
        cout<<(sum/k)<<endl;
        for(int i=k;i<arr.size();i++)
        {
            sum -= arr[i-k];
            sum += arr[i];
            if((int)(sum/k) >= threshold)
                res++; 
            cout<<(sum/k)<<endl;
        }
        return res;
    }
};