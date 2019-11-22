#include <iostream>

using namespace std;
int findMassCenter(int[], int);

int main() {
    int n;
    cin >> n;
    int array[n]; // elemanları tutacağımız dizi
    int sum = 0; // elemanların toplamını tutacağımız değer

    for(int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }

    cout << findMassCenter(array, sum);
}

int findMassCenter(int array[], int sum) {
    int index = 0;
    if(sum % 2 == 0) // eğer toplam çift ise sorunsuz olarak direkt yarısını alabiliriz
        sum /= 2;
    else            // fakat tek ise üstüne bir eklememiz gerekir
        sum = (sum / 2) + 1; 
    
    while(sum > array[index]) { // toplamımız dizinin indexinden küçük veya eşit olana kadar dönüyor
        sum -= array[index++];
    }

    return index;
}