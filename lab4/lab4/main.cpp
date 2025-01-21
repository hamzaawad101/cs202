// Lab 04: Adding List-Based Integers
/* Author:Hamza Awad
*Date:9/20/24
* Program uses list and node class to creat singley linked lists
* that takes in numbers puts them into nodes and adds them.
*using add function that takes two lists and return a list with the sum
*/

#include "list.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cstdio>
#include <stdlib.h>  
using namespace std;
int main(int argc, char *argv[]) {
    string n1;
    string n2;
        while(cin>>n1>>n2){//while file is not empty
	List ll1; //instance of lists
    	List ll2;
         int len1=n1.length();//get length of strings (numbers)
         int len2=n2.length();
    for (int i =len1-1;i>=0; i--) { 
        int num1 = n1[i] - '0';  // Convert each character to integer
        ll1.addNode(num1); //push each digit to node to make list
    }
    for (int i=len2-1; i>=0; i--) { //push_back to add properley
        int num2 = n2[i] - '0'; 
        ll2.addNode(num2);
    }
   
  // Print result of adding the two lists
    List ll3 = ll1.add(ll1,ll2); // Call the add function
    ll3.printList();
}
 return 0;   
} 

    
    
   
