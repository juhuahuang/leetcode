class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        if( numCourses == 0) return result;
        vector<vector<int> > graph(numCourses);
        vector<int> inDegree(numCourses,0);
        for( auto &p:prerequisites){
            graph[p.second].push_back(p.first);
            inDegree[p.first]++;
        }
        unordered_set<int> startNode;
        for( int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0) startNode.insert(i);
        }
        
        if( inDegree.empty()) return result;
        while( !startNode.empty()){
            int node = *(startNode.begin());
            result.push_back(node);
            startNode.erase(node);
            for(int neighbor : graph[node]){
                if(--inDegree[neighbor] == 0) startNode.insert(neighbor);
            }
        }
        if( result.size() == numCourses) return result;
        else return vector<int>();
        

    }
};