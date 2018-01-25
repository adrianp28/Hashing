#include <string>
#include <iostream>
class Hash_table{
public:
   	//  methods of the List ADT
   	Hash_table(int h);
	int insert(std::string key);
	int hash(const std::string &key);
	int retrieve(std::string key);

protected:
   	//  data members for a contiguous list implementation
	std::string* table;
   	int hashTableSize;
};
