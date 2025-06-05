class Solution {
public:
    int findParent(vector<int>&parent,int num)
    {
        if(parent[num] == num) return num;
        return findParent(parent,parent[num]);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        
        vector<int>parent(26,0);

        for(int i = 0 ; i < 26 ; i++ ) 
        {
            parent[i] = i;
        }

        for(int i = 0 ; i < n ; i++ )
        {
            // s1[i] can be a parent of s2[i]
            // let's keep this in such a way that the the least one valued will become the parent and another
            // will become the child here itself
            // Both should first find their root parents

            int u = findParent(parent,s1[i]-'a');
            int v = findParent(parent,s2[i]-'a');

            if(u > v)
            {
                parent[u] = v;
            }
            else
            {
                parent[v] = u;
            }
        }

        for(int i = 0 ; i < m ; i++ )
        {
            baseStr[i] = ('a'+findParent(parent,baseStr[i]-'a'));
        } 
        return baseStr;
    }
};