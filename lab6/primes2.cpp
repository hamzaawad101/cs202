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
            getPrimes(2, num, primes); // Get all primes from 2 to the input number
        
         /* if (find(primes.begin(), primes.end(), num) != primes.end()) {
                cout << "prime" << endl;
            } else {
                cout << "not prime" << endl;
            }
            */
        //tesing using vector of max value size 
            primesVector.clear();
            vectorCheck(num,primesVector);

        if (primesVector[num]==1) {
            cout << "prime (maxVector)" << endl;
        } else {
            cout << "not prime (maxVector))" << endl;
        }
        

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

void getPrimes(int start, int end, vector<int>& primes){
    for(int i=start; i<=end; i++){
       if(isPrime(i)){ //if i is prime we add it to the vector
          primes.push_back(i);
       }
    }  
}
//function for vector of max size that sets v[i]=1
void vectorCheck(int max,vector<int>& primesVector){
    int counter=0;
    primesVector.resize(max);
    for(int i=2; i<=max; i++){
       if(isPrime(i)){ //if i is prime we add it to the vector
          primesVector[i]=1;
          counter++;
       }
    }  
    cout<<counter<<endl;
}
bool isPrime(int n)
{
      // Since 0 and 1 are not prime return false.
      if(n == 1 || n == 0){
         return false;
      }
      // Run a loop from 2 to n-1
      for(int i = 2; i < sqrt(n); i++){
        // if the number is divisible by i then n is not a prime number.
        if(n % i == 0){
             return false;
        }
      }
      // Otherwise n is a prime number.
      return true;
}
