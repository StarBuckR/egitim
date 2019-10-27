#include <iostream>
#include <math.h>

bool isDimbillan(int);

using namespace std;
int main() {
    int count = 0;
    for(int i = 0; i <= 31; i++){
        int num = pow(2, i) - 1;
        if(isDimbillan(num)){
            count++;
        }
    }
    printf("%d", count);
}

bool isDimbillan(int num){
    int temp = num;
    int reverse = 0;
    int multiplier = 10;

    while(temp > 0){
        reverse *= 10;
        reverse += temp % 10; 
        temp /= 10;
    }

    if((num - reverse) % 2 == 0){
        return true;
    }
    return false;
}