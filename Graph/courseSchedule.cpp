class Solution {
public:
    // example of cycle detection in a directed graph using BFS / DFS

    // if the courses are aligned as cycle then we cant finish them
    // course -> prereq -- directed edge

    // here solving using BFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);
        unordered_map<int, list<int>> adjList;

        for (auto it : prerequisites) {
            // it -- vector
            adjList[it[0]].push_back(it[1]); // course --> itsPreReqCourse
            indegree[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // if it gets equal to numCourses then valid topSort then
                       // we can finish all the courses

        while (!q.empty()) {
            int ele = q.front();
            q.pop();

            count++;
            // we have to destroy its outgoing edges to its neighbours

            for (auto nbr : adjList[ele]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return count == numCourses;
    }
};
