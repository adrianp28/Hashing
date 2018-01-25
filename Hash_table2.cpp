#include "Hash_table2.h"
#include <string>

using namespace std;
Hash_table2::Hash_table2(int h)
{
	hashTableSize = h; //set the size of the hash table
	table= new string[hashTableSize]; //creates our hash table
}
int Hash_table2::insert(string key)
{
	int probe = hash(key); //hashes the key and stores it into probe
	int probe_count = 0; //probe count starts at 0
	int increment = 1; // used for quadratic probing
	//look will execute as long as there is an element in the position, the key doest not equal a current element and we are under the probe count
	while(table[probe] != "" && table[probe] != key && probe_count < (hashTableSize + 1)/2)
	{
		probe_count++; //incrremnt probe count
		probe = (probe + increment) % hashTableSize; //quadratic probing
		increment += 2;	//increment to go along with quadratic probing 1^2 + 2^2 + 3^2 ... i^2
	}
	if(table[probe] == "") // if there is an empty position
		table[probe] = key; // store key in our table at that index
	else
		probe = -1; // make probe -1
	return probe; // returns the index
}
int Hash_table2::hash(const string &key)
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
//this works the same as our insert but backwards
int Hash_table2::retrieve(string key)
{
	int found = -1;
	int probe = hash(key);
	int probe_count = 0;
	int increment = 1;
	while(table[probe] != "" && table[probe] != key && probe_count < (hashTableSize + 1)/2)
	{
		probe_count++;
		probe = (probe + increment) % hashTableSize;
		increment += 2;	
	}
	if(table[probe] != key)
		probe = -1;

	return probe;

}
