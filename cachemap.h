#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>
#include "pointers.h"

using namespace std;

template <class K, class V>
class CacheMemory
{
public:
    CacheMemory()
    {
        std::map<K, V> cacheMemory;
    };

    void add(const K& key, const V& value)
    {
        if (nullptr != cacheMemory[key])
        {
            throw DuplicateKeyException;
        }
        CacheMemory[key] = value;
    }

    void erase(const K& key)
    {
        if (nullptr != CacheMemory.find(key))
        {
            CacheMemory.erase(key);
        }

        else
        {
            throw ObjectNotExistException;
        }
    }

    std::shared_ptr<V> get(const K& key)
    {
        return CacheMemory.find(key);
    }

    std::vector<V> getCacheValues()
    {
        for (auto it = CacheMemory.begin(); CacheMemory.end(); it + )
        {
            std::vector<V> newVec;
            newVec.push_back(it);
            return newVec;
        };
    }
};
