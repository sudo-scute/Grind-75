class Solution {
public:
    // main observation///  -- centroids of a tree always give the minimum height
    // trees (MHTs). 
    // Centroids are centrally located within the tree. This
    // central position ensures that the maximum distance from the root
    // (centroid) to any other node in the tree is minimized.


    // A tree can have either one or two centroids.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1){
            return {0};
        }
        vector<int> adjList[n]; // vvi with n vectors as rows
        vector<int> indegree(n, 0);

        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);

            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        queue<int>q;

        for(int i = 0 ; i < n ; i++){

            // leaf nodes have indegree = 1
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        int m = n; // remaining no. of nodes 
        // because final 2 elements are gonna be centroids
        while(m > 2){
            
            int siz = q.size(); // no. of leaf nodes
            m = m - siz;
            for (int i = 0; i < siz; ++i){
                int leafNode = q.front();
                q.pop();
                for(auto nbr : adjList[leafNode]){
                    indegree[nbr]--;

                    if(indegree[nbr] == 1){

                        q.push(nbr);
                    }
                }
            }
        }


        vector<int>ans;

        // pushing only final remaining centroids 
        while(!q.empty()){

            int i = q.front();
            q.pop();
            ans.push_back(i);
        }

        return ans;
    }
};
