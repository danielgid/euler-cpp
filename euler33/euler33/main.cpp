//
//  main.cpp
//  euler33
//
//  Created by Daniel on 22/09/2018.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

/**************************************************************/

int euler33();
bool ifCancelling(double num1, double num2);


/**************************************************************/


int main(int argc, const char * argv[]) {
    int dom = 0;
    
    clock_t tStart = clock();
    dom = euler33();
    
    cout << "The answer on euler 33 : " << dom << endl;
    cout << "Runtime for euler 33 : " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    return 0;
}

/*
 in this function we check 4 options
 of digit cancelling
 we do 2 for loop by 10->99 numbers
 and check the option
 and check them the minimal denominator
 
 */
int euler33(){
    int rc = 10000;
    
    for (int i = 10; i < 100; i++) {

        for (int j = i; j < 100; j++) {

            if(ifCancelling((double) i, (double)j)){
                cout << i << " " << j << endl;
                if(i * j < rc)
                    rc = i*j;
            }
        }
    }
    
    
    return rc;
}

bool ifCancelling(double num1, double num2){
    int tmp = 0;
    double dx1,dx2,dy1,dy2;
    
    dx1 = (double)((int)num1 % 10);
    
    tmp = (int)num1 / 10;
    dx2 = (double)tmp;
    
    dy1 = (double)((int)num2 % 10);
    
    tmp = (int)num2 / 10;
    dy2 = (double)tmp;
    
    if((double)(dx1/dy1) == (double)(num1/num2) && (dx2 == dy2)){
        return true;
    }
    
    if((double)(dx1/dy2) == (double)(num1/num2) && (dx2 == dy1)){
        return true;
    }
    
    if((double)(dx2/dy1) == (double)(num1/num2) && (dx1 == dy2)){
        return true;
    }
    
    if((double)(dx2/dy2) == (double)(num1/num2) && (dx1 == dy1)){
        return true;
    }
    
    return false;
}
