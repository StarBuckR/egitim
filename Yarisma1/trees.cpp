#include <iostream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;
double findHypotenuse(int x, int y, int x2, int y2) {
    return sqrt(pow((x2 - x), 2) + pow((y2 - y), 2));
}

int main() {
    int m;
    cin >> m;
    vector< vector<int> > trees(m, vector<int>(2));
    for(int i = 0; i < m; ++i) {
        cin >> trees[i][0] >> trees[i][1];
    }

    int lastX = 0;
    int lastY = 0;
    double spent = 0;
    double min;

    int erase;
    for(int i = 0; i < m; i++) {
        min = findHypotenuse(0, 0, trees[0][0], trees[0][1]);
        for(int j = 0; j < trees.size(); ++j) {
            double temp = findHypotenuse(lastX, lastY, trees[j][0], trees[j][1]);
            if(temp < min){
                min = temp;
                erase = j;
            }
        }
        lastX = trees[erase][0];
        lastY = trees[erase][1];
        spent += min;
        trees.erase(trees.begin() + erase);
    }

    cout << spent;
}