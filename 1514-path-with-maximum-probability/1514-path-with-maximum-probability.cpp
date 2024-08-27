class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;

        vector<double>probab(n,0);
        probab[start_node]=1;
        //make adj list
        for(int i=0;i<edges.size();i++) 
        {
            int v = edges[i][0];
            int u = edges[i][1];

            double prob = succProb[i];
            
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        //max heap
        priority_queue<pair<double,int>>p;
        
        p.push({1.0,start_node});

        while(!p.empty())
        {
            auto it = p.top();
            p.pop();

            double pb = it.first;
            int n = it.second;

            if(n==end_node)     return pb; 
            
            for(auto it : adj[n])
            {
                double pro = it.second;
                int node = it.first;
                double x = pb*pro;
                if(x>probab[node])
                {
                   
                    probab[node]=x;
                    p.push({x,node});
                }
            }
        }

    return 0;
    }
};