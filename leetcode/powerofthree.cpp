/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

#include <stdlib.h>
#include <stdio.h>

bool isPowerOfThree(int n) {
       for(; n>0; n /= 3){
             if(n==1 || n==3)
                   return true;
              if(n%3 != 0)
                   return false;
   }
    return false;
}

int main(){
    bool b = isPowerOfThree(27);
    if(b)
        printf("27 is isPowerOfThree\n");
    return 0;
}
