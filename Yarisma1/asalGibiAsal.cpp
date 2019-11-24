#include <iostream>
#include <math.h>
#include <string> 

using namespace std;

bool isPrime(int num) {
    if(num < 2)
        return false;
        
    for(int i = 2; i <= num / 2; ++i)
        if(num % i == 0)
            return false;

    return true;
}

bool isPrimeAll(int num) {
    // alttaki kod bloğu sayının tüm alt kümelerini digits dizisine aktarıyor
    string numberStr = to_string(num);
    int digitLength = numberStr.length(); // sayının basamak sayısını buluyoruz.
    int sum = 0; // sayının tüm alt kümelerini bulmak için bi toplam değişkeni
    
    for(int i = 1; i <= digitLength; i++)
        sum += i;
    
    int digits[sum]; // sayını tüm alt kümelerinin depolanacağı değişken
    int index = 0;

    for (int i = 0; i < digitLength; i++)  
        for (int len = 1; len <= digitLength - i; len++)
            digits[index++] = stoi(numberStr.substr(i, len));
    
    // herhangi bir alt küme asal değil ise değişkenimizi false yapıyor ve false değeri döndürüyor
    bool isAllPrime = true;
    for(int i = 0; i < sum; ++i) 
        if(!isPrime(digits[i]))
            return false;
    
    if(isAllPrime)
        return true;

    return false;
}

int main() {
    int sum = 0;
    for(int i = 2; i <= 1000; ++i)
        if(isPrimeAll(i)){
            //cout << i << endl; // eğer tüm sayıları görmek istiyorsanız bu satırı açın
            sum += i;
        }
    cout << sum;
    return 0;
}