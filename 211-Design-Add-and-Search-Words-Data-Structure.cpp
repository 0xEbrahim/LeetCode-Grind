
class WordDictionary {
public:
    struct Node{
        Node*ch[26];
        int end;
        Node(){
            memset(ch, 0, sizeof ch);
            end = 0;
        }
    };

    Node*root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node*cur = root;
        for(auto&it:word){{
                int index = it - 'a';
                if(!cur -> ch[index]) cur -> ch[index] = new Node();
                cur = cur -> ch[index];}
        }
        cur -> end++;
    }
    bool x = false;
    bool search(string word, Node*curr){
        int i = 0;
        int id = 0;
        for( ; i < word.size() ; i++){
            if(word[i] != '.'){
                id++;
                int index = word[i] - 'a';
                if(!curr -> ch[index]) return false;
                curr = curr -> ch[index];
            }else{
                for(int j = 0 ; j < 26 && !x ; j++){
                    if(curr -> ch[j]){
                        if(i == word.size() - 1 && curr -> ch[j] -> end > 0) x = true;
                        else x |= search(word.substr(i + 1, word.size() - (i + 1)), curr -> ch[j]);
                    }
                }
                break;
            }
        }
        return (id == word.size() && curr -> end > 0) || x;
    }
    bool search(string word) {
        Node*cur = root;
        bool ret = false;
        int i = 0;
        int id = 0;
        for( ; i < word.size() ; i++){
            if(word[i] != '.'){
                int index = word[i] - 'a';
                id++;
                if(!cur -> ch[index]) return false;
                cur = cur -> ch[index];
            }else{
                for(int j = 0 ; j < 26 && !ret; j++){
                    if(cur -> ch[j]){
                        if(i == word.size() - 1 && cur -> ch[j] -> end > 0)
                            ret = true;
                        else
                            x = false, ret |= search(word.substr(i + 1, word.size() - (i + 1)), cur -> ch[j]);
                    }
                }
                break;
            }
        }
        return (id == word.size() && cur -> end > 0) || ret;
    }
};