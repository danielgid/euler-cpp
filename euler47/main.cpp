//
//  main.cpp
//  euler47
//
//  Created by Daniel on 18/10/2018.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

/****************************************/

void euler47(int countPrime);
bool distnict(int num, int countPrime);

void prime();
bool ifPrime(int num);

/****************************************/

int size;
int primes[100000];

/****************************************/


int main(int argc, const char * argv[]) {
    auto t1 = chrono::high_resolution_clock::now();
    
    euler47(4);
    
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed = t2 - t1;
    
    cout << "Algorithm Runtime is: " << elapsed.count() << " milliseconds.";
    
    
    return 0;
}

/****************************************/

void euler47(int countPrime){
    int j=0;
    size = 0;
    prime();
    
    //cout << distnict(16, countPrime) << endl;
    
    for (int i =2 ; i < 1000000; i++) {

        if(distnict(i, countPrime)){
            for (j = 1; j < countPrime; j++) {
                if(!distnict((++i), countPrime)){
                    j=0;
                    break;
                }
            }
            
            if(j==countPrime){
                cout << i-countPrime+1 << endl;
                break;
            }
        }
    }
    
}

bool distnict(int num, int countPrime){
    int counter = 0, index =0;
    
    while(num > 1 && index < size){
        if(num % primes[index]==0){
            while(num % primes[index]==0){
                num/=primes[index];
                
                if(counter > countPrime)
                    return false;
            }
            counter++;
        }
           
        index++;
    }
    
    if(counter == countPrime)
        return true;
    
    return false;
}

/****************************************/


void prime(){
    primes[size++]=2;
    primes[size++]=3;

    for (int i =5; i<1000000; i+=2) {
        if(ifPrime(i))
            primes[size++]=i;
    }
}

bool ifPrime(int num){
    
    for (int i =0; i < size && primes[i] < num; i++) {
        if(num%primes[i]==0)
            return false;
    }
    
    return true;
}

/****************************************/
