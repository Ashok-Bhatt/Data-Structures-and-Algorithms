#include <bits/stdc++.h>
using namespace std;

class TrieNode {

    public:
    char data;
    bool isPresent;
    TrieNode* next[26];

    TrieNode(char data){
        this->data = data;
        this->isPresent = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }

};

class Trie {

    public:
    TrieNode* root;
    
    Trie(){
        this->root = new TrieNode('\0');
    }

    void insertWord(string data){

        TrieNode* temp = this->root;

        for (int i=0; i<data.length(); i++){
            int index = data[i] - 97;
            temp->next[index] = new TrieNode(data[i]);
            temp = temp->next[index];
        }

        temp->isPresent = true;
    }

    bool searchWord(string data){
        
        int i = 0;
        TrieNode* temp = root;

        while (i < data.length()){
            if (temp->next[i] == NULL){
                return false;
            } else {
                temp = temp->next[i];
                i++;
            }
        }

        return temp->isPresent == true;
    }
};

int main(){
    Trie* t1 = new Trie();
    cout << t1->searchWord("abcd") << endl;
    t1->insertWord("abcd");
    cout << t1->searchWord("abcd") << endl;
}