class Solution {
public:
    int findUpar(vector<int>&parent, int temp)
    {
        if(temp == parent[temp]) return temp;
        return parent[temp] = findUpar(parent,parent[temp]);
    }

    int unionSize(vector<int>&parent, vector<int>&size, int x, int y)
    {
        int px = findUpar(parent,x);
        int py = findUpar(parent,y);
        if(px == py) return 1;
        
        if(size[px] > size[py])
        {
            parent[py] = px;
            size[px] += size[py];
        }
        else
        {
           parent[px] = py;
           size[py] += size[px];
        }
        return 0;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // Prepare A Minimum Spanning Tree for this
        vector<int>parent(n+1,0);
        for(int i = 0 ; i <= n ; i++ )
        {
            parent[i] = i;
        }
        vector<int>size(n+1,1);
        int cntOfSpare = 0;
        for(int i = 0 ; i < connections.size() ; i++ )
        {
           cntOfSpare += unionSize(parent,size,connections[i][0],connections[i][1]);
        }
        int cntSelf = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(parent[i] == i)
            {
                cntSelf++;
            }
        }

        cout<<cntOfSpare<<" "<<cntSelf<<endl;

        if((cntSelf-1) > cntOfSpare) return -1;
        return (cntSelf-1);

        // While Calculating the Minimum Spanning Tree I will keep the count of unused edges
        // Then I'll compare it with those elements whose parent is itself

    }
};