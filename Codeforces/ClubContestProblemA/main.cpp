#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> filas(n);
    vector<long long> columnas(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            int temp;
            cin >> temp;
            filas[i] += temp;
            columnas[j] += temp;
        }
    }
    for(int i=0; i<filas.size(); i++){
        cout << filas[i] << " ";
    }
    cout << endl;
    for(int i=0; i<filas.size(); i++){
        cout << columnas[i] << " ";
    }
    return 0;
}
