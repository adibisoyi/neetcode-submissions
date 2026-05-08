class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for(auto task :tasks)
        {
            count[task-'A']++;
        }

        priority_queue<int> maxHeap;

        for(auto i:count)
        {
            if(i>0)
                maxHeap.push(i);
        }

        queue<pair<int,int>> q;
        int time=0;

        while(!maxHeap.empty() || !q.empty())
        {
            time++;
            if(maxHeap.empty())
            {
                q.front().second;
            }
            else
            {
                int cnt = maxHeap.top()-1;
                maxHeap.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});    
                }
            }
            if(!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
