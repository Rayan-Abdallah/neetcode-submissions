class LRUCache {
private:
    struct list_node{
        int key, val;
        list_node(int k, int v){
            key = k, val = v;
            prev = nullptr;
            next = nullptr;
        }
        list_node* prev;
        list_node* next;
    };
    struct linked_list{
        list_node* root = nullptr;
        list_node* end = nullptr;
    };
    linked_list* lst;
    int lstSize, cap;
    unordered_map<int, list_node*> keyToNode;
public:
    LRUCache(int capacity) {
        cap = capacity;
        lstSize = 0;
        lst = new linked_list;
    }
    
    int get(int key) {
        if(keyToNode.contains(key)){
            int ans = keyToNode[key]->val;
            if(keyToNode[key] == lst->end){
                return ans;
            }
            if(keyToNode[key] == lst->root){
                lst->root = lst->root->next;
                lst->root->prev = nullptr;
                lst->end->next = keyToNode[key];
                keyToNode[key]->prev = lst->end;
                keyToNode[key]->next = nullptr;
                lst->end = lst->end->next;
                return ans;
            }
            keyToNode[key]->prev->next = keyToNode[key]->next;
            keyToNode[key]->next->prev = keyToNode[key]->prev;
            lst->end->next = keyToNode[key];
            keyToNode[key]->prev = lst->end;
            keyToNode[key]->next = nullptr;
            lst->end = lst->end->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lstSize == 0){
            list_node* new_root = new list_node(key, value);
            lst->root = new_root;
            lst->end = new_root;
            keyToNode[key] = new_root;
            lstSize++;
            return;
        }
        if(keyToNode.contains(key)){
            keyToNode[key]->val = value;
            if(keyToNode[key] == lst->end){
                return;
            }
            if(keyToNode[key] == lst->root){
                lst->root = lst->root->next;
                lst->root->prev = nullptr;
                lst->end->next = keyToNode[key];
                keyToNode[key]->prev = lst->end;
                keyToNode[key]->next = nullptr;
                lst->end = lst->end->next;
                return;
            }
            keyToNode[key]->prev->next = keyToNode[key]->next;
            keyToNode[key]->next->prev = keyToNode[key]->prev;
            lst->end->next = keyToNode[key];
            keyToNode[key]->prev = lst->end;
            keyToNode[key]->next = nullptr;
            lst->end = lst->end->next;
            return;
        }
        lst->end->next = new list_node(key, value);
        keyToNode[key] = lst->end->next;
        keyToNode[key]->prev = lst->end;
        lst->end = lst->end->next;
        lstSize++;
        if(lstSize > cap){
            list_node* new_root = lst->root->next;
            new_root->prev = nullptr;
            keyToNode.erase(lst->root->key);
            delete lst->root;
            lst->root = new_root;
            lstSize--;
        }
    }
};
