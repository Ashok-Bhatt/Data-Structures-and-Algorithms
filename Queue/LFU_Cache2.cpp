#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> keyPair;
    unordered_map<int, list<int>> frequencies;
    int minFrequency, cacheSize, capacity;

    LFUCache(int capacity) {
        minFrequency = 1;
        cacheSize = 0;
        this->capacity = capacity;
    }

    void updateFrequency(int key, int value, int frequency, list<int>::iterator location){
        frequencies[frequency].erase(location);
        if (frequencies[frequency].empty() && minFrequency==frequency) minFrequency = frequency + 1;
        frequencies[frequency+1].push_back(key);
        keyPair[key].first = value;
        keyPair[key].second.first = frequency + 1;
        keyPair[key].second.second = prev(frequencies[frequency+1].end(), 1);
    }
    
    int get(int key) {
        if (keyPair.find(key) == keyPair.end()){
            return -1;
        } else {
            auto temp = keyPair[key];
            int value = temp.first, frequency = temp.second.first;
            list<int>::iterator location = temp.second.second;

            updateFrequency(key, value, frequency, location);
            return value;
        }
    }
    
    void put(int key, int value) {
        if (keyPair.find(key) != keyPair.end()){
            auto temp = keyPair[key];
            int oldValue = temp.first, frequency = temp.second.first;
            list<int>::iterator location = temp.second.second;
            updateFrequency(key, value, frequency, location);
        } else {
            if (cacheSize < capacity){
                frequencies[1].push_back(key);
                keyPair[key] = {value, {1, prev(frequencies[1].end())}};
                cacheSize++;
            } else {
                int keyToDelete = frequencies[minFrequency].front();
                frequencies[minFrequency].pop_front();
                keyPair.erase(keyToDelete);
                frequencies[1].push_back(key);
                keyPair[key] = {value, {1, prev(frequencies[1].end())}};
            }
            minFrequency = 1;
        }
    }
};

int main(){
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1,1);
    lfu->put(2,2);
    cout << lfu->get(1) << " ";
    lfu->put(3,3);
    cout << lfu->get(2) << " ";
    cout << lfu->get(3) << " ";
    lfu->put(4,4);
    cout << lfu->get(1) << " ";
    cout << lfu->get(3) << " ";
    cout << lfu->get(4) << " ";
}