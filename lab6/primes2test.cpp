#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <map>   
#include <set>    
using namespace std;

void getPrimes(int start, int end, vector<int>& primes);
bool isPrime(int n);
void vectorCheck(int max,vector<int>& primesVector);

int main(int argc, char *argv[]) {
    vector<int> primes;
    map<int, bool> primeMap;   
    vector<int> primesVector;
    int num;
    while(cin>>num){
        if (num > 1) { // handle non-positive numbers early
            primes.clear();
        for(int i=2; i<=num; i++){
            if(isPrime(i)){ //if i is prime we add it to the vector
          primes.push_back(i);
       }
    }  
         //testing using find()
           if (find(primes.begin(), primes.end(), num) != primes.end()) {
                cout << "prime" << endl;
            } else {
                cout << "not prime" << endl;
            }
        /* tesing using vector of max value size 
            primesVector.clear();
            vectorCheck(num,primesVector);

        if (primesVector[num]==1) {
            cout << "prime (maxVector)" << endl;
        } else {
            cout << "not prime (maxVector))" << endl;
        }
        */

        /*tesing using map()
          for (int i = 2; i <= num; i++) {
            if (isPrime(i)) {
                primeMap[i] = true;
            }
        }
          if (primeMap[num]) {
            cout << "prime (map)" << endl;
        } else {
            cout << "not prime (map)" << endl;
        }
         */

         /*testing using binary search
            if (binary_search(primes.begin(), primes.end(), num)) {
            cout << "prime" << endl;
        } else {
            cout << "not prime" << endl;
        }
        */
        }
        
          if(num==1){
                cout<<"not prime"<<endl;
            }
            
    }
    return 0;
}
//function for vector of max size that sets v[i]=1
/*void vectorCheck(int max,vector<int>& primesVector){
    primesVector.resize(max+1,0);
    for(int i=2; i<=max; i++){
       if(isPrime(i)){ //if i is prime we add it to the vector
          primesVector[i]=1;
       }
    }  
}
*/
bool isPrime(int n){
      if(n == 1 || n == 0){
         return false;
      }
      for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
             return false;
        }
      }
      return true;
}
