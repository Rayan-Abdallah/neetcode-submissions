class WordDictionary {
private:
    struct Node {
        bool endOfWord = false;
        Node* children[26];
        Node() {
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    Node* start = new Node();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* cur = start;
        for(auto c: word){
            int ind = c - 'a';
            if(cur->children[ind] == nullptr){
                cur->children[ind] = new Node();
            }
            cur = cur->children[ind];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        std::function<bool(Node*, int)> dfs;
        dfs = [&](Node* node, int wordInd) {
            if(node == nullptr){
                return false;
            }
            if(wordInd == word.size()){
                return node->endOfWord;
            }
            bool res = false;
            if(word[wordInd] == '.'){
                for(int i = 0; i < 26; i++){
                    res |= dfs(node->children[i], wordInd + 1);
                }
            }
            else{
                res = dfs(node->children[word[wordInd] - 'a'], wordInd + 1);
            }
            return res;
        };
        return dfs(start, 0);
    }
};
