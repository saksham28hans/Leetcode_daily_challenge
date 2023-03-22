class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1,false);
        queue<int> q;
        int res = INT_MAX;
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        q.push(1);
        vis[1] = true;
        while(!q.empty())
        {
          int val = q.front();
          q.pop();
          
          for(auto nb : adj[val])
          {

              if(!vis[nb])
              {
                  vis[nb] = true;
                  q.push(nb);
              }
          }
        }
        
        for(int i=0;i<roads.size();i++)
        {
            if(vis[roads[i][0]])
            res = min(res,roads[i][2]);
        }
        return res;
    }
};