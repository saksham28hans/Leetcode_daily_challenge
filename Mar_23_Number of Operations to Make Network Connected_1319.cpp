class Solution {
public:
     static void dfs(vector<vector<int>>& l,vector<bool>& visited,int src)
    {
        visited[src] = true;
        for(auto i:l[src])
        {
            if(visited[i] !=true)
            {
                visited[i] = true;
                dfs(l,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       vector<bool> visited(n);
       // list<int> l;
        int out = 0;
        vector<vector<int>> l(n);
        int m = connections.size();
        if(m<(n-1))
            return -1;
        //l = new list<int>[n];
        for(int i=0;i<connections.size();i++)
        {
            l[connections[i][0]].push_back(connections[i][1]);
            l[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(l,visited,0);
         for(int i=0;i<n;i++)
        {
            if(visited[i] != true)
            {
                out++;
                dfs(l,visited,i);
            }
        }
        return out;
    }
};