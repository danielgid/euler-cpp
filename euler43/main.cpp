//
//  main.cpp
//  euler43
//
//  Created by Daniel on 15/10/2018.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <iostream>
#include <chrono>

using namespace std;


/****************************************/

void euler43();
bool ifPandigital(long int num);
bool isDivide(long int num);

int sumDigits(long int num);
int product(long int num);

/****************************************/

int main(int argc, const char * argv[]) {
    auto t1 = chrono::high_resolution_clock::now();

    //ifPandigital(2359847616l);
    euler43();
    
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed = t2 - t1;
    
    cout << "Algorithm Runtime is: " << elapsed.count() << " milliseconds.";
    
    return 0;
}


/****************************************/

void euler43(){
    long int sum=0;
    
    for (long int p = 1023456789l; p < 9876543210l; p++) {
        if(isDivide(p)){
            if(ifPandigital(p)){
                cout << p << endl;
                cout << "*************************" << endl;
                sum+=p;
            }
        }
    }
    
    cout << sum << endl;
}

bool ifPandigital(long int num){
    int tmp=0;
    bool digits[10];
    
    for (int i = 0; i<10; i++) {
        digits[i]=false;
    }
    
    while(num>0){
        tmp = num % 10;
        
        if(digits[tmp])
            return false;
        else
            digits[tmp]= true;
        
        num = num /10;
    }
    
    for(int i=0;i<10;i++)
        if(!digits[i])
            return false;
    
    return true;
}

//362880
//45

int product(long int num){
    int prod =1,digit=0;
    
    while(num>0){
        digit = num % 10;
        
        if(digit!=0)
            prod *= digit;
        
        num = num /10;
    }
    
    return prod;
}

int sumDigits(long int num){
    int sum =1,digit=0;
    
    while(num>0){
        digit = num % 10;
        
        sum += digit;
        
        num = num /10;
    }
    
    return sum;
}


bool isDivide(long int num){
    long int nums[] = {17,13,11,7,5,3,2};
    long int tmp = num % 1000, digit;
    num /=1000;
    
    for(int i = 0; i < 7 ; i++){
        if(tmp % nums[i] !=0)
            return false;
        
        tmp /= 10;
        digit =num%10;
        num /=10;
        
        digit*=100;
        tmp+=digit;
    }
    
    /*if(tmp % 17 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 13 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 11 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 7 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 5 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 3 !=0)
        return false;
    
    tmp /= 10;
    digit =num%10;
    num /=10;
    
    digit*=100;
    tmp+=digit;
    
    if(tmp % 2 !=0)
        return false;
    */
    return true;
}


/****************************************/

