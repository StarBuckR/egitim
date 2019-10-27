#include <stdio.h>

int main() {
    int n;
    int m;
    int numberOfSquare = 0;
    scanf("%d %d", &n, &m);

    int min = (n>m)?m:n;

    for(int t=0; t<=min; t++) {
        for (int i=0; i<n-t; i++) {
            for (int j=0; j<m-t; j++) {
                numberOfSquare++;
            }
        }
    }
    
    printf("%d\n", numberOfSquare);
    return 0;
}