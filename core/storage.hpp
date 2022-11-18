#ifndef STORAGE_HPP
#define STORAGE_HPP
#include <string>

class ISerialize
{
public:
    // ISerialize();
    virtual std::string serializeInfo() = 0;
};

class CacheStorage
{
private:
    int _size = 0;
    std::string *_array = nullptr;
    std::string _path;
    bool _sizeCache;
    bool _arrayCache;

protected:
    void expired();

public:
    CacheStorage(std::string);
    void save(ISerialize *);
    void save();
    int getSize();
    std::string *getContentAsArray();
};
#endif