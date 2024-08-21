class Solution {
public:
    struct Node{
    Node*ch[26];
    int prefix;
    int end;
    Node(){
        memset(ch, 0, sizeof ch);
        prefix = end = 0;
    }
};

struct Trie{
    Node*root;
    Trie(){
        root = new Node();
    }

    void insert(string&s){
        Node*cur = root;
        for(auto &it : s){
            int index = it - 'a';
            if(!cur -> ch[index]) cur -> ch[index] = new Node();
            cur = cur -> ch[index];
            cur -> prefix++;
        }
        cur -> end++;
    }
    bool ispre(string&s){
        Node*cur = root;
        for(auto &it : s){
            int index = it - 'a';
            if(!cur -> ch[index]) return false;
            cur = cur -> ch[index];
        }
        return cur -> prefix > 0;
    }
    bool check(string&s){
        Node*cur = root;
        for(auto &it : s){
            int index = it - 'a';
            if(!cur -> ch[index]) return false;
            cur = cur -> ch[index];
        }
        return cur -> end > 0;
    }
};
int n ;
int m;
set<string>res;

void dfs(int i , int j , string s, vector<vector<char>>&x, Node*trieNode){
    if(i < 0 || i >= n || j < 0 || j >= m || x[i][j] == '#' || !trieNode -> ch[x[i][j] - 'a']) return;

    char org = x[i][j];
    x[i][j] = '#';
    trieNode = trieNode -> ch[org - 'a'];
    s+=org;
    if(trieNode -> end > 0) res.insert(s);
    dfs(i - 1, j, s , x , trieNode);
    dfs(i + 1, j, s , x , trieNode);
    dfs(i, j - 1, s , x , trieNode);
    dfs(i, j + 1, s , x , trieNode);
    x[i][j] = org;
}
vector<string> findWords(vector<vector<char>>& v, vector<string>& words) {
    vector<string>s;
    n = v.size();
    m = v[0].size();
    Trie tr = Trie();
    for(int i = 0 ; i < words.size() ; i++) tr.insert(words[i]);
    string ss ="";
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) dfs(i, j,ss, v, tr.root);
    vector<string>ret(res.begin(), res.end());
    return ret;
}
};