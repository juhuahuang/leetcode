class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> forward,backward;
        forward.insert(beginWord);
        backward.insert(endWord);
        vector<vector<string> > paths;
        vector<string> path(1,beginWord);
        unordered_map<string, vector<string> > tree;
        if( buildTree(forward, backward, wordList, tree, false)){
            printPath(beginWord,endWord,tree,path,paths);
        }
        return paths;
        
    }
    
    bool buildTree(unordered_set<string> forward, unordered_set<string> backward, unordered_set<string> &dict, unordered_map<string, vector<string> > &tree, bool reverse){
        if( forward.empty()) return false;
        if( forward.size() > backward.size()) return buildTree(backward, forward, dict,tree, !reverse);
        for( auto &word : forward) dict.erase(word);
        for( auto &word : backward) dict.erase(word);
        bool done = false;
        unordered_set< string> nextLevel;
        for( auto &it:forward){
            string word = it;
            for(auto &c :word){
                char c0 = c;
                for( c = 'a';c<='z';++c){
                    if( c!=c0){
                        if( backward.find(word) != backward.end() ) {
                            done = true;
                            !reverse?tree[it].push_back(word):tree[word].push_back(it);
                        }
                        else if (!done && dict.find(word) != dict.end() ){
                            nextLevel.insert(word);
                            !reverse?tree[it].push_back(word):tree[word].push_back(it);
                        }
                    }
                }
                c = c0;
            }
        }
        return done || buildTree(nextLevel,backward,dict, tree, reverse);
    }
    
    void printPath(string beginWord,string endWord,unordered_map<string, vector<string> > tree, vector<string> &path,vector<vector<string> > &paths){
        if( beginWord == endWord){
            paths.push_back(path);
            return;
        }
        for( auto &word : tree[beginWord]){
            path.push_back(word);
            printPath(word, endWord,tree,path,paths);
            path.pop_back();
            
        }
        
    }
};