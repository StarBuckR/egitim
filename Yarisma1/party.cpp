#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> couples;
    vector<string> others(m * 2);

    for(int i = 0; i < n * 2; ++i){
        string person;
        cin >> person;
        couples.insert(pair<string, int> (person, 0));
    }
    for(int i = 0; i < m * 2; ++i)
        cin >> others[i];
    
    for(int i = 0; i < m * 2; ++i) { // couples ın içindeki elemanları tek tek gezerek bulunan değerlerin sayılarını bir artırıyoruz.
        couples.insert(pair<string, int> (others[i], couples.find(others[i])->second++));
    }

    for (map<string, int>::iterator it=couples.begin(); it!=couples.end(); ++it){ // bu döngü c++11'de çalışır
        if(it->second >= 2) // bulunduğumuz kişinin tanıdığı kişi sayısı 2 veya daha fazla ise bunu yazdırıyoruz
            cout << it->first << endl;
    }
    /*
    for(const auto &[k, v] : couples) { // bu döngü sadece c++17'de çalışır
        if(v >= 2)
            cout << k << endl;
    }*/
}