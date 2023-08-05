// 6956. Minimum Seconds to Equalize a Circular Array

// O(n^2) solution Brute Force approch. 
class Solution {
public:
    int bfs(int val,vector<int> adjls[],vector<int>& nums){
        int n = nums.size(), cnt=0;
        vector<int> vis(n+1,0);
        queue<pair<int,int>> q;
        
        for(int i=0 ;i<n ;i++){
            if(nums[i]==val){ 
                q.push({i,0});
                vis[i] =1;
            }
        } 
        
        while(!q.empty()){
            int node = q.front().first,cost=q.front().second;
            q.pop();
            cnt = max(cost,cnt);
            
            // cout<<node<<"->";
            for(auto it:adjls[node]){
                if(vis[it]==0){
                    q.push({it,cost+1});
                    // cout<<it<<" ";
                    vis[it] =1;
                }
            
            }
            // cout<<endl;
            
        }
        return cnt;
    }
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size(),cnt=INT_MAX,curmax=0,idx=-1;
        vector<int> adjls[n], vis(n+1,0);
        queue<pair<int,int>> q;
        map<int,int> mp;
        for(int i=0 ;i<n ;i++){
            adjls[i].push_back((i - 1 + n) % n);
            adjls[i].push_back((1+i) % n);
            mp[nums[i]]++;
            curmax = max(curmax,mp[nums[i]]);
        }
        // cout<<curmax<<endl;
        // if(curmax)
        for(auto it:mp){
            if(it.second==curmax){
                cout<<it.first<<endl;
                cnt = min(cnt,bfs(it.first,adjls,nums));
            }
        }
        
        return cnt;
    }
};
