/* Author: Hamza Awad 
* Date 10/02/24
* Program implements a hash table using two different hashing methods XOR or Last7 
* it takes input of table size hash method and collision either Linear or Double 
*checks error inputs like hash table already set up and cannot insert 

*/
#include "hash_202.hpp"
#include <iostream>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iomanip>
using namespace std;

string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision) {
        //check if table is set up
        if (!Keys.empty()&&!Vals.empty()) {
                return "Hash table already set up";
        }
	// Check table size
        if (table_size == 0) {
                return "Bad table size";
        }
	//check and set hash function
        if (fxn == "XOR") {
                Fxn = 0;
        } else if (fxn == "Last7") {
                Fxn = 1;
        } else {
                return "Bad hash function";
        }
	// Check the collision resolution strategy
        if (collision == "Linear") {
                Coll = 'L';
        } else if (collision == "Double") {
                Coll = 'D';
        } else {
                return "Bad collision resolution strategy";
        }
	//resize table
        Keys.resize(table_size);
        Vals.resize(table_size);
        Nkeys = 0;
        Nprobes = 0;
        return "";
}
int XOR_Hash(const string& key) { // Changed to const string&
        size_t hash = 0;
        istringstream ss; 
        size_t i = 0;
        while (i < key.length()) { 
                string seven = key.substr(i, 7); //substr to split the string 
                size_t value;
                ss.clear(); // Clear the stringstream state
                ss.str(seven);  //Set the stringstream to the substring
                ss >> hex >> value;  //convert hexadecimal value
                hash ^= value; // Update hash with XOR operation
                i += 7; // Move to Next 7
        }
	return hash;
}
int Last7_Hash(const string& key) { // Changed to const string&
        size_t hash = 0;
        istringstream ss;
        string Last7 = ""; // Variable to hold the last 7 characters
        if (key.length() > 7) {
                Last7 = key.substr(key.length() - 7, 7); //get last 7 characters 
                ss.str(Last7); // Set the stringstream to the last 7 characters
        } else {
                ss.str(key); //else use the whole key
        }
	ss >> hex >> hash;// Convert to hexadecimal value
        return hash;
}
string Hash_202::Add(const string &key, const string &val) {
        // Check if the table is set up
        if (Keys.empty()) {
                return "Hash table not set up";
        }

	// Check for empty key
        if (key.empty()) {
                return "Empty key";
        }

	// Check if digits are hex
        for (size_t i = 0; i < key.length(); ++i) {
                if (!isxdigit(key[i])) {
                        return "Bad key (not all hex digits)";
                }
        }

	// Check for empty value
        if (val.empty()) {
                return "Empty val";
        }


	// Check if the table is full
        if (Nkeys>=Keys.size()) {
                return "Hash table full";
        }
        size_t index = 0;

        // XOR Hash Function
        if (Fxn == 0) {
                index = XOR_Hash(key) % Keys.size();
        }

	// Last7 Hash Function
        if (Fxn == 1) {
                index = Last7_Hash(key) % Keys.size();
        }



	
        if(Keys[index%Keys.size()].empty()) {
                //no need to re hash
                Keys[index] = key;
                Vals[index] = val;
                Nkeys++;
                return "";
        }
	else if(Keys[index%Keys.size()] == key){
         return "Key already in the table";
        }
        size_t count = 0;
        istringstream ss;
        string Last7 = "";
        size_t hash2 = 0;
        do {
                if (Coll == 'D') {
                        // If the function is XOR, use Last7 as hash2
                        if (Fxn == 0) {
                                // I need to create new hash using last 7 and I do that by calling Last7_hash
                                        hash2 = Last7_Hash(key);
                                        if(hash2 % Keys.size()==0){
                                         index = (index +1 ) % Keys.size();
                                        }  else{
                                                index += hash2 % Keys.size();
                                                }

                                
                        }
                        // If the function is Last7, use XOR as hash2
                        else if (Fxn == 1) {
                                 hash2 = XOR_Hash(key);
                                if(hash2 % Keys.size() == 0){
                                index = (index +1 ) % Keys.size();
                                }
                                else{
                                index += hash2 % Keys.size();
                                }
                        }
               	} else {
                        index = (index + 1) % Keys.size();

                }
                count++;
                 if(count==Keys.size()){
                        return "Cannot insert key";

                }

        } while(index%Keys.size() < Keys.size()&& Keys[index%Keys.size()] != key && !Keys[index%Keys.size()].empty() && count< Keys.size());     // Secondary hash for double hashing
        if(Keys[index%Keys.size()] == key){
        return "Key already in the table";
        }
	Keys[index%Keys.size()] = key;
       Vals[index%Keys.size()] = val;
        Nkeys++;
        return "";
}
string Hash_202::Find(const string &key) {
        //check if table is empty
        if(Keys.size()==0) {
                return "";
        }
	//check if keys are hex
        if(key.length()==0) {

                return "";
        }
	for(size_t i=0; i<key.length(); i++) {
                if(!isxdigit(key[i])) {
                        return"";
                }
        }
	size_t index = 0;
        istringstream ss;
        string Last7 = "";
        // XOR Hash Function
        if (Fxn == 0) {
                index = XOR_Hash(key) % Keys.size();
        }

	// Last7 Hash Function
        if (Fxn == 1) {
                       	index = Last7_Hash(key) % Keys.size();
        }
        if(Keys[index%Keys.size()]==key) {
                return Vals[index];
        } else {
                //i need to try to rehash atleast 1 more time
                size_t count=0;
                do {
                        Nprobes++;
                        size_t hash2 = 0;
                        if (Coll == 'D') {
                                // If the function is XOR, use Last7 as hash2
                                if (Fxn == 0) {
                                         hash2 = Last7_Hash(key);
                                        if(hash2 % Keys.size()==0){
                                                index = (index +1 ) % Keys.size();
                                        } else{
                                               	index += hash2 % Keys.size();
                                               }

                                }

                                // If the function is Last7, use XOR as hash2
                                else if (Fxn == 1) {

                                                 hash2 = XOR_Hash(key);
                                        if(hash2 % Keys.size() == 0){
                                                index = (index +1 ) % Keys.size();
                                        }else{
                                              	index += hash2 % Keys.size();
                                        }       

                                }
                        }
                        if (Coll == 'L') {
                                // Linear probing
                        index = (index + 1) % Keys.size();
                        } 

                        count++;
                } while(Keys[index%Keys.size()]!=key && count<Keys.size());
        }
	if(Keys[index%Keys.size()]==key) {
                return Vals[index%Keys.size()];
        }
	return"";
}
void Hash_202::Print() const { //print function 
        if(Keys.empty()) {
                return;
        }
	for(size_t i=0; i<Keys.size(); i++) {
                if(!Keys[i].empty()) {
                        cout<<setw(5)<<i<<" "<<Keys[i]<<" "<<Vals[i]<<endl;
                }
        }
}
size_t Hash_202::Total_Probes() { //total probes
    if(Keys.empty()) {
        return 0;
    }

    Nprobes = 0;

    for(size_t i = 0; i < Keys.size(); i++) {
        if (!Keys[i].empty()) {  // Only count for non-empty index
            Find(Keys[i]);  // Find increments Nprobes
        }
    }

    return Nprobes;
}






