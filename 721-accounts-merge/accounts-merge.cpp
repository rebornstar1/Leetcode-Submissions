class Solution {
public:
    // Function To Get The Ultimate Parent
    int UltParent(vector<int>&parent,int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = UltParent(parent,parent[x]);
    }

    void fUnion(vector<int>&parent,vector<int>&size,map<int,set<string>>&mp,int x, int y,vector<vector<string>>& accounts)
    {
        int px = UltParent(parent,x);
        int py = UltParent(parent,y);
        if(px == py) return;

        if(size[px] > size[py])
        {
            parent[py] = px;
            size[px] += size[py];
            // I need to push these strings into mp[px];
            for(int i = 1 ; i < accounts[py-1].size() ; i++ )
            {
                mp[px].insert(accounts[py-1][i]);
            }
            for(auto it : mp[py])
            {
                mp[px].insert(it);
            }
        }
        else
        {
            parent[px] = py;
            size[py] += size[px];
            for(int i = 1 ; i < accounts[px-1].size() ; i++ )
            {
                mp[py].insert(accounts[px-1][i]);
            }
            for(auto it : mp[px])
            {
                mp[py].insert(it);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // First Task Is to find the edges
        set<vector<int>>edge;
        int n = accounts.size();

        // As of Now Everything Else Seems Right But I need to make changes in the way of evaluation of edges
        map<pair<string,string>,vector<int>>mp;
        for(int i = 0 ; i < n ; i ++ )
        {
            for(int j = 1 ; j < accounts[i].size() ; j++ )
            {
                mp[{accounts[i][j],accounts[i][0]}].push_back(i+1);
            }
        }
        // O(N*N);

        // Now All In one types are the connected Component Itself'
        for(auto it : mp)
        {
            pair<string,string>flex = it.first;
            vector<int>jump = it.second;
            for(int i = 0 ; i < (jump.size()-1) ; i++)
            {
                if(jump[i] != jump[i+1])
                {
                edge.insert({jump[i],jump[i+1]});
                }
            }
        }

        vector<vector<int>>edges;
        for(auto it : edge)
        {
            edges.push_back(it);
        }

        map<int,set<string>>tp;
        vector<int>parent(n+1, 0);
        for(int i = 0 ; i <= n ; i++ )
        {
           parent[i] = i; // Respectively Here
        }
        vector<int>size(n+1,1);

        for(int i = 0 ; i < edges.size() ; i++ )
        {
            fUnion(parent,size,tp,edges[i][0],edges[i][1],accounts);
        }

        for(int i = 1 ; i <= n ; i++ )
        {
            if(parent[i] == i)
            {
                // If That is the Ultimate Parent Node
                for(int j = 1 ; j < accounts[i-1].size() ; j++ )
                {
                    tp[i].insert(accounts[i-1][j]);
                }
            }
        }

        vector<vector<string>>ans;
        for(auto it : tp )
        {
            if(it.first != parent[it.first]) continue;
            string jump = accounts[it.first-1][0];
            vector<string>hp;
            hp.push_back(jump);
            for(auto pp : it.second)
            {
                hp.push_back(pp);
            }
            sort(hp.begin()+1,hp.end());
            ans.push_back(hp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Try to bring it's Time Complexity Below 20/30 Ms