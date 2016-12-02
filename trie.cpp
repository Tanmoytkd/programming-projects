struct trie {
    int val;
    trie * child [257];
    trie() {
        val=0;
        for(int i=0; i<=256; i++) child[i]=NULL;
    }
};

struct dict {
    trie * t;
    dict() {
        t= new trie;
    }
    void insert(const char * s, int len) {
        int i=0;
        trie *tmp = t;
        while(i<=len) {
            if(tmp->child[s[i]]==NULL) {
                tmp->child[s[i]]=new trie;
            }
            tmp=tmp->child[s[i]];
            tmp->val++;
            i++;
        }
    }
    void insert(const string& s) {
        insert(s.c_str(), s.length());
    }

    int find(const char * s, int len, int prefix=0) {
        int i=0;
        trie * tmp= t;
        while(i<=len) {
            if(tmp->child[s[i]]==NULL || tmp->child[s[i]]->val==0) return 0;
            tmp=tmp->child[s[i]];
            i++;
        }
        return tmp->val;
    }
    int find(const string& s) {
        return find(s.c_str(), s.length());
    }

    int countprefix(const char * s, int len) {
        return find(s, len-1);
    }
    int countprefix(const string & s) {
        return find(s.c_str(), s.length()-1);
    }

    void erase(const char * s, int len) {
        if(find(s,len)==0) return;
        int i=0;
        trie * tmp=t;
        while(i<=len) {
            if(tmp->child[s[i]]==NULL || tmp->child[s[i]]->val<=0) break;
            tmp=tmp->child[s[i]];
            tmp->val--;
            i++;
        }
        if(tmp->val<=0) {
            for(int i=0; i<=256; i++) tmp->child[i]=NULL;
        }
    }
    void erase(const string& s) {
        erase(s.c_str(), s.length());
    }
};
