class PrefixTree {
private:
    struct Node {
        char c;
        Node* children[27];
        Node(char x): c(x) {
            for(int i = 0; i < 27; i++){
                children[i] = nullptr;
            }
        }
        Node* add(char x){
            if(children[x - 'a'] != nullptr){
                return children[x - 'a'];
            }
            Node* child = new Node(x);
            children[x - 'a'] = child;
            return child;
        }
    };
    Node start = Node('a' + 26);
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* cur = &start;
       for(auto c: word){
            Node* next = cur->add(c);
            cur = next;
       }
       cur->add('a' + 26);
    }
    
    bool search(string word) {
        string s = word;
        s += ('a' + 26);
        return startsWith(s);
    }
    
    bool startsWith(string prefix) {
        Node* cur = &start;
        bool failed = false;
        for(auto c: prefix){
            if(cur->children[c - 'a'] != nullptr){
                Node* next = cur->children[c - 'a'];
                cur = next;
                continue;
            }
            failed = true;
            break;
        }
        return !failed;
    }
};
