#include <string>
//#include "utility.h"
class Hash_table2{
public:
   	//  methods of the List ADT
   	Hash_table2(int h);
	int insert(std::string key);
	int hash(const std::string &key);
	int retrieve(std::string key);

protected:
   	//  data members for a contiguous list implementation
	std::string* table;
   	int hashTableSize;
};

