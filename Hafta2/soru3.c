#include<stdio.h>
#include<stdlib.h>

// funcs
int sumOfPiece(int **, int, int, int);
int run(int **, int, int);
int show(int **, int);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if(M>N || N<0 || M < 0) {
        printf("-1");
        return 0;
    }
    int * matrix[N];
    for(int i = 0; i<N; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * N);
    }
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++)  {
            scanf("%d", &matrix[i][j]);
        }
    }
    run(matrix, N, M);
    show(matrix, N+1-M);
    return 0;
}

int sumOfPiece(int ** arr, int r, int c, int m) {
    int sum = 0;
    int limitR = r+m;
    int limitC = c+m;
    for(int i = r; i<limitR;i++) {
        for(int j = c; j<limitC; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int run(int ** arr, int n, int m) {
    for(int i=0; i<n+1-m; i++) {
        for(int j=0; j<n+1-m; j++) {
            arr[i][j] = sumOfPiece(arr, i, j, m);
        }
    }
}

int show(int ** arr, int until) {
    for(int i=0; i<until; i++) {
        for(int j=0; j<until; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
