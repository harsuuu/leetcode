class Solution {
public:
    void DFS(int src,unordered_map<int,bool>&visited, vector<int>adjList[])
    {
        visited[src]=true;
        for(auto neigh : adjList[src])
        {
            if(!visited[neigh])
            {
                DFS(neigh,visited,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adjList[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        unordered_map<int,bool>visited;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                DFS(i,visited,adjList);
            }
        }

    return cnt;
    }
};