class BrowserHistory {
public:
    struct Node {
        string val;
        Node*next;
        Node*prev;
        Node(string data){
            val = data;
            next = NULL;
        }
    };
    Node*starter;
    Node*last;
    BrowserHistory(string homepage) {
        starter = new Node(homepage);
        starter -> prev = NULL;
        last = starter;
    }

    void visit(string url) {
        Node*URL = new Node(url);
        URL -> prev = last;
        last -> next = URL;
        last = last -> next;
    }

    string back(int steps) {
        Node*cur = last;
        Node*ret = cur;
        while(cur && steps > 0){
            steps--;
            ret = cur;
            cur = cur -> prev;
        }
        last = cur ? cur : ret;
        return cur ? cur -> val : ret -> val;
    }

    string forward(int steps) {
        Node*cur = last;
        Node*ret = cur;
        while(cur && steps > 0){
            steps--;
            ret = cur;
            cur = cur -> next;
        }
        last = cur ? cur : ret;
        return cur ? cur -> val : ret -> val;
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */