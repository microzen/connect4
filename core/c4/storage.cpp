#include "../storage.hpp"
#include "../common.hpp"
#include <string>
using namespace std;
CacheStorage::CacheStorage(string path) { this->_path = path; }
void CacheStorage::expired() {
  this->_array = nullptr;
  this->_size = -1;
}
int CacheStorage::getSize() {
  if (this->_size <= 0) {
    string *filesize = readFileToStringArray(this->_path, 1);
    this->_size = stoi(filesize[0]);
  }
  return this->_size;
}

string *CacheStorage::getContentAsArray() {
  int size = this->getSize();
  if (this->_array == nullptr) {
    string *newarray = readFileToStringArray(this->_path, size + 1);
    this->_array = &newarray[1];
    // free(&newarray[0]);
  }
  return this->_array;
}

void CacheStorage::save(ISerialize *serialize) {
  int size = this->getSize();
  string *array = this->getContentAsArray();
  string *newarray = new string[size + 2];
  newarray[0] = to_string(size + 1);
  for (size_t i = 1; i < size + 1; i++) {
    newarray[i] = array[i - 1];
  }
  newarray[size + 1] = serialize->serializeInfo();
  writeFileToStringArray(this->_path, newarray, size + 2);
  this->expired();
}
void CacheStorage::save() {
  int size = this->getSize();
  string *array = this->getContentAsArray();
  string *newarray = new string[size + 1];
  newarray[0] = to_string(size);
  for (size_t i = 1; i < size + 1; i++) {
    newarray[i] = array[i - 1];
  }
  writeFileToStringArray(this->_path, newarray, size + 1);
  this->expired();
}

// Score List Storage
C4Score::C4Score(CacheStorage *cache) { this->_cache = cache; }
int C4Score::getStorageByName(std::string name) {
  int score = 0;
  string *score_list = this->_cache->getContentAsArray();
  int size = this->_cache->getSize();
  for (int i = 0; i < size; i++) {
    string *sco =  convertToArray(score_list[i],";",3);
    
    if (sco[0]==name){
      score = stoi(sco[1]);
      break;
    }
  }
  return score;
}