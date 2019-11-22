#include <iostream>
#include <string.h>
using namespace std;

int getMinRemove(char s[], int length){
    int count = 0, tempCount = 1;
    char current = s[0];
    for(int i = 1; i < length; i++){
        if(s[i] != current){
            if(tempCount > 1 && count < tempCount){
                count = tempCount;
            }
            tempCount = 1;
            current = s[i];
        }
        else{
            tempCount++;
        }
    }
    if(tempCount == length || tempCount > count)
        return tempCount;
    return count;
}

int main() {
    int length;
    int a;
    cin >> length;
    char s[length];
    cin >> s;
    int min = getMinRemove(s, length);
    cout << length - min;
    return 0;
}
