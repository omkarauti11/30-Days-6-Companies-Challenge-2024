#include <bits/stdc++.h>
using namespace std;

// solution

class LRUCache
{
public:
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> address;
    list<int> l;
    int cap;
    int siz;

    LRUCache(int capacity)
    {
        cap = capacity;
        siz = 0;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }

        auto it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            auto it = address[key];
            l.erase(it);
            address.erase(key);
            m.erase(key);
            siz--;
        }

        if (siz == cap)
        {
            int del = l.back();
            l.pop_back();
            address.erase(del);
            m.erase(del);
            siz--;
        }

        siz++;
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
    }
};

// Time Complexity = O(1)
// Space Complexity = O(Capacity)
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */