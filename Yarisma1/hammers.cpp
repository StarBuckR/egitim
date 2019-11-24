#include <iostream>
#include <vector>

using namespace std;
int hammers(vector< vector<int> >, int, int);
bool isHammer(vector< vector<int> >, int, int, int,int, int);

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > arr(n, vector<int>(n));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[j][i];
        }
    }

    cout << hammers(arr, n, m);
}
// m tek sayılardan oluşacak
int hammers(vector< vector<int> > arr, int n, int m) {
    int middle = (m / 2);
    int count = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(arr[j][i] == 1 && isHammer(arr, j, i, n, m, middle)) {
                count++;
            }
        }
    }

    return count;
}

bool isHammer(vector <vector<int> > arr, int j, int i, int n, int m, int middle) {
    int count = 0;
    for(int k = 0; k < m; ++k) {
        if(j + k < n && arr[j + k][i] == 1){
            count++;
        }
    }

    for(int k = 1; k < m; ++k) {
        if(i + k < n && middle + j < n && arr[middle + j][i + k] == 1){
            count++;
        }
    }
    
    if(count == (2 * m - 1))
        return true;
    
    return false;
}