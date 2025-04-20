#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char character;
        vector<TrieNode*> next;
        bool isLast;
        
        TrieNode(char character){
            this->character = character;
            this->isLast = false;
            this->next = vector<TrieNode*>(26, NULL);
        }
        
        TrieNode(char character, int isLast){
            this->character = character;
            this->isLast = isLast;
            this->next = vector<TrieNode*>(26, NULL);
        }
};


class Trie {
  private:
  
    void insertWord(TrieNode* &root, string &word, int index){
        if (index >= word.size()){
            return;
        }
        
        if (root->next[word[index]-'a'] == NULL){
            if (index == word.size()-1){
                root->next[word[index]-'a'] = new TrieNode(word[index], true);
            } else {
                root->next[word[index]-'a'] = new TrieNode(word[index]);    
            }
        } else if (index == word.size()-1){
            root->next[word[index]-'a']->isLast = true;
        }
        insertWord(root->next[word[index]-'a'], word, index+1);
    }
    
    bool searchWord(TrieNode* &root, string &word, int index){
        cout << "Index: " << index << endl;
        cout << root->character << " " << word[index] << endl;
        if (root->next[word[index]-'a'] != NULL){
            if (index == word.size()-1){
                return root->next[word[index]-'a']->character==word[index] && root->next[word[index]-'a']->isLast;
            } else {
                return searchWord(root->next[word[index]-'a'], word, index+1);
            }
        } else {
            return false;
        }
    }
    
    bool isPrefixCheck(TrieNode* &root, string &word, int index){
        if (root->next[word[index]-'a'] == NULL){
            return false;
        } else if (index == word.size()-1){
            return root->next[word[index]-'a']->character==word[index];
        } else {
            return isPrefixCheck(root->next[word[index]-'a'], word, index+1);
        }
    }
    
  public:

    TrieNode* root;
        
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string &word) {
        insertWord(root, word, 0);
    }

    bool search(string &word) {
        return searchWord(root, word, 0);
    }

    bool isPrefix(string &word) {
        return isPrefixCheck(root, word, 0);
    }
};

int main(){
    Trie* trie = new Trie();
    string x = "z", y = "zlwql", z = "ynfk";
    trie->insert(x);
    cout << trie->isPrefix(x) << endl;
    cout << trie->search(y) << endl;
    cout << trie->isPrefix(z) << endl;
}