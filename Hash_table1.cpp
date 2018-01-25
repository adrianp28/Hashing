#include "Hash_table1.h"
#include <string>

using namespace std;
Hash_table::Hash_table(int h)
{
	hashTableSize = h; // sets the hash size
	table= new string[hashTableSize]; //creates are hash table with the size
}
int Hash_table::insert(string key)
{
	//Error_code result = success;
	int probe = hash(key); //hash the key and store it into probr
	int probe_count = 0; // set probe count to 0
	//while loop will execute as long as there is not an empty index, the keys dont match and we did not go over the size of the hashtable
	while(table[probe] != "" && table[probe] != key && probe_count < hashTableSize-1)
	{
		probe++; // next index
		probe_count++; // increment probecount
		if(probe == hashTableSize-1) // if the index reaches the end of the table
			probe = 0; // then we go back to the beggining to the table
		
	}
	if(table[probe] == "") // if the current position is empty
	{
		table[probe] = key; // put key in that position
	}
	else 
		probe = -1; // set probe to -1
	return probe; // return the index
			
}
int Hash_table::hash(const string &key)
{
	int value = 1; // value starts at 1
	// loop will execute for the lenght of the key to be inserted
	for(int i = 0; i < key.length(); i++)
	{
		int n = (int)key[i]; // casts the index of the key to an int
		value = n * value; // times the value together (Folding method)
	}
	value = value % hashTableSize; //after we Fold, then we use Modular arithmitic
	if(value < 0) // check to make sure we are above 0
		value+=hashTableSize;
	return value; // return the index	
}
//retrieve is a duplicate of the hashing function only in reverse it returns -1 if not found
int Hash_table::retrieve(string key)
{
	int probe_count = 0;
	int probe;
	probe = hash(key);
	while(table[probe] != "" && table[probe] != key && probe_count <= hashTableSize-1)
	{
		probe_count++;
		probe++;
		if(probe == hashTableSize-1)
			probe = 0;
	}
	if(table[probe] != key)
	{
		probe = -1;
	}
	return probe;
}
