// Lab 6: Is it prime?
/*Author:Hamza Awad 
 * Date: 10/11/24
 * Program generates a list of prime numbers up to a user-specified number.
 * It uses a vector to store the primes and displays them 20 per line.
 */
#include<iostream>
using namespace std;
void getPrimes(int number); // Function to get and print all prime numbers
bool isPrime(int n); // Function to check if a number is prime
int main(int argc, char *argv[]) {
  int number=0;
  cin>>number;
  getPrimes(number);
  return 0;

}
// Function to get prime numbers up to number and print them
void getPrimes(int number){
    int counter=0; // Counter to keep track of how many primes have been printed
    for(int i=1; i<number; i++){
       if(isPrime(i)){
          cout<<i<<",";
          counter++;
       }
       if(counter==20){
        cout<<endl;// Print a newline
        counter=0;
       }
    }  
    cout<<endl;
}
bool isPrime(int n)
{
      if(n == 1 || n == 0) return false; //0 and 1 not primes 
      for(int i = 2; i < n; i++){
        if(n % i == 0) return false; //id divisibile its not prime 
      }
      return true; //else its prime 
}

