class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > result;
        vector<string> path;
        unordered_map<string,bool> visited;
        int min_len = INT_MAX;
        if( beginWord == endWord){
            path.push_back(beginWord);
            result.push_back(path);
            return result;
        }
        visited[beginWord] = true;
        for(auto word : wordList){
            visited[word] = false;
        }
        path.push_back(beginWord);
        DFS(beginWord,endWord,wordList,path,result,visited,min_len);
        return result;
    }
    
    void DFS(string beginWord,string endWord,unordered_set<string> &wordList, vector<string> &path,vector<vector<string> > &result,unordered_map<string,bool> &visited,int &min_len ){
        if( beginWord == endWord){
            int len = path.size();
            if( len < min_len){
                result.clear();
                result.push_back(path);
                min_len = len;
            }
            else if( len == min_len){
                result.push_back(path);
            }
            return;
        }
        
        
        for( int i = 0;i<beginWord.size();i++){
            for( char c = 'a';c<='z';c++){
                string newWord = beginWord;
                newWord[i] = c;
                if( newWord != beginWord && wordList.find(newWord) != wordList.end() && !visited[newWord] ){
                    visited[newWord] = true;
                    path.push_back(newWord);
                    DFS(newWord, endWord,wordList,path,result,visited,min_len);
                    visited[newWord] = false;
                    path.pop_back();
                }
            }
        }
        

    }
    
   
};