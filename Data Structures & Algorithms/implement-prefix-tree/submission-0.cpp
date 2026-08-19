class PrefixTree {
private:
    class Node {
    public:
        char c;
        Node(char x): c(x) {
            // empty
        }
        vector<Node*> children;
        Node* add(char x){
            bool found = false;
            for(auto node: children){
                if(node->c == x){
                    return node;
                }
            }
            Node* child = new Node(x);
            children.push_back(child);
            return child;
        }
    };
    Node start = Node('0');
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* cur = &start;
       for(auto c: word){
            Node* next = cur->add(c);
            cur = next;
       }
       cur->add('0');
    }
    
    bool search(string word) {
        Node* cur = &start;
        bool failed = false;
        for(auto t: word){
            bool found = false;
            for(auto node: cur->children){
                //std::cout<<node->c<<" ";
                if(node->c == t){
                    found = true;
                    cur = node;
                    break;
                }
            }
            if(!found){
                failed = true;
                break;
            }
        }
        if(!failed){
            for(auto node: cur->children){
                if(node->c == '0'){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* cur = &start;
        bool failed = false;
        for(auto c: prefix){
            bool found = false;
            for(auto node: cur->children){
                if(node->c == c){
                    found = true;
                    cur = node;
                    break;
                }
            }
            if(!found){
                failed = true;
                break;
            }
        }
        return !failed;
    }
};
