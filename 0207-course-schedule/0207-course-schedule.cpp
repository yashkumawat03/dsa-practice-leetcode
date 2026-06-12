class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int completed = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            completed++;
            for(auto next : adj[course]){
                indegree[next]--;
                if(indegree[next]==0)
                    q.push(next);
            }
        }
        return completed == numCourses;
    }
};