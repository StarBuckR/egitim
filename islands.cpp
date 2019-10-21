#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num){
    if(num < 2)
        return false;

    for(int i = 2; i <= num / 2; i++)
        if(num % i == 0)
            return false;

    return true;
}

int recurIsland(vector<vector<int>> &list, int x, int y){
    int temp = 0;

    temp += list[x][y];
    list[x][y] = -1;

    if(x < list.size() - 1 && list[x + 1][y] != -1 && !isPrime(list[x + 1][y])){
        temp += recurIsland(list, x + 1, y);
    }
    if(x != 0 && list[x - 1][y] != -1 && !isPrime(list[x - 1][y])){
        temp += recurIsland(list, x - 1, y);
    }

    if(y < list.size() - 1 && list[x][y + 1] != -1 && !isPrime(list[x][y + 1])){
        temp += recurIsland(list, x, y + 1);
    }
    if(y != 0 && list[x][y - 1] != -1 && !isPrime(list[x][y - 1])){
        temp += recurIsland(list, x, y - 1);
    }

    return temp;
}

int getMaxPrimesIsland(vector<vector<int>> &list){
    int temp = 0, biggest = 0;
    
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list.size(); j++){
            if(!isPrime(list[i][j])){
                temp = recurIsland(list, i, j);
                if(temp > biggest)
                    biggest = temp;
            }
        }
    }
    return biggest;
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> list(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int input;
            cin >> input;
            list[j][i] = input;
        }
    }

    cout << getMaxPrimesIsland(list);
    return 0;
}