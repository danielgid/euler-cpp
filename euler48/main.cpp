//
//  main.cpp
//  euler48
//
//  Created by Daniel on 18/10/2018.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <iostream>
#include <chrono>

using namespace std;

/****************************************/

void euler48();
long int selfPow(long int num);

/****************************************/

int main(int argc, const char * argv[]) {
    auto t1 = chrono::high_resolution_clock::now();
    
    euler48();
    
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed = t2 - t1;
    
    cout << "Algorithm Runtime is: " << elapsed.count() << " milliseconds.";
    
    
    return 0;
}


/****************************************/

void euler48(){
    long int sum=0;
    for (long int i = 1; i <=1000; i++) {
        sum+=selfPow(i);
    }
    
    sum = sum % 10000000000;
    
    cout << sum << endl;
}


long int selfPow(long int num){
    long int rc=num;
    
    for (long int i = 1; i<num; i++) {
        rc *= num;
        rc = rc % 10000000000;
    }
    
    return rc;
}


/****************************************/

