/*
    Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
    Where N is the number of queries and W is the average length of words.

    Space Complexity : O(N*W)
    Where N is the number of words inserted and W is the average length of words.
*/


class TrieNode {
public:
    TrieNode * child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
        }
        tem->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};
