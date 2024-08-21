class Trie {
public:
    struct Node {
        Node*ch[26];
        int prefix;
        int end;
        Node(){
            memset(ch, 0, sizeof ch);
            prefix = 0;
            end = 0;
        }
    };
    Node*root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*cur = root;
        for(auto &it : word){
            int index = it - 'a';
            if(cur -> ch[index] == 0) cur -> ch[index] = new Node();
            cur = cur -> ch[index];
            cur -> prefix++;
        }
        cur -> end++;
    }
    
    bool search(string word) {
        Node*cur = root;
        for(auto&it:word){
            int index = it - 'a';
            if(cur -> ch[index] == 0) return 0;
            cur = cur -> ch[index];
        }
        return cur -> end > 0;
    }
    
    bool startsWith(string prefix) {
        Node*cur = root;
        for(auto&it:prefix){
            int index = it - 'a';
            if(cur -> ch[index] == 0) return 0;
            cur = cur -> ch[index];
        }
        return cur -> prefix > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */