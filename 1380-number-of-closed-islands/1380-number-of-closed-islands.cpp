class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

    // ye jo likha hai bo neeche smjh aayega, kesa likha hai
    int dir_x[4]={1,-1,0,0};
    int dir_y[4]={0,0,1,-1};

     int ans=0; //answer hai jo hm return kra rhe hai.  
     //number of rows
     int m=grid.size();
     //number of column
     int n=grid[0].size();
     //ab visited name ki same size ki matrix bna li.
     // isse ye hoga ek bar hmne jis par visit kr liya than dubara visit krne ki jrurat nhi hai.
     vector<vector<bool>>vis(m,vector(n,false));

    //ab for loop lgakr traverse kro.

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j] || grid[i][j]==1)
            continue;

            // ab queue bna li ek jisme pair store krayenge jb zero milega.
            //jaise first row m itration hoga jaise hi last zeo pr phuchenge to uska row and column queue m store kra lenge.
            queue<pair<int, int>> q({{i,j}});

            //intially hmne man liye close loop hoga to true man liya.
            bool is_closed = true;

            while(!q.empty())
            {
                //ab q m jo bhi value pair thi use front m pop kra li.
                auto front =q.front();
                q.pop();

                //ab loop lgayenge jo charo direction m check krega.
                for(int k=0;k<4;k++)
                {
                   // ab jaise man le hm hai (5,2) pr mtlb 5 row 2 column pr hai agr hme uper jana hai to row m minus krna pdega (4,2) and agr right m jana hai to row same rhegi column m plus krna pdega (5,3) and agr hme left m jana hai to row same colmn m minus krna pdega (5,1) and bottom jane k liye column same rhega row m plus krna pdega (6,2).

                //    ab hm dekh skte hai right,left,top and bottom m difference (1,0),(0,1),(0,-1),(1,0) --> ye difference hme present state - new state se nikala hai.
                int dy=front.first + dir_y[k];
                int dx=front.second + dir_x[k];

                if(dy<0 || dy >=m || dx <0 || dx >=n)
                {
                    is_closed =false;
                    continue;
                }
                if(grid[dy][dx]==1) continue;
                if(vis[dy][dx])   continue;
                vis[dy][dx]=true;
                q.push({dy,dx});
                }
            }
            if(is_closed)
            ans++;
        }
    }
    return ans;
    }
};