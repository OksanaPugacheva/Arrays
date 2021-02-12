#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    mt19937 gen(time(0));
    uniform_int_distribution<> uid(1, 50); // диапазон чисел в массиве
    uniform_int_distribution<> uid1(2, 26); // диапазон длин массивов

    int n, dynamic_size;

    do {
        cout << "Please enter a number between 0 and 25: ";
        cin >> n;
    } while (n>26 || n<0);

    vector<vector<int>> vs(n);

    for (auto& v : vs) 
    {
        do {
            dynamic_size = uid1(gen);
            for (int k = 0; k < n;++k) 
                if (dynamic_size == vs[k].size()) {
                    dynamic_size = -1;
                }
        } while (dynamic_size == -1);

        v.resize(dynamic_size); //резервирование длины вектора
    }

     
    cout << "Source arrays: " << endl;
    for (int i = 0; i < n; i++) {     
        cout << i << ") ";
        for (int j = 0; j < vs[i].size(); j++) 
        {
            vs[i][j] = uid(gen); // Заполнение вектора 
            cout << vs[i][j] << ' ';  
        }
        cout << endl;
    }

    cout << "Sorted arrays:  " << endl;
    for (int i = 0; i < n; i++) {   
        if (i % 2 == 0) {
            sort(vs[i].begin(), vs[i].end());
        }
        else
        {
            sort(vs[i].begin(), vs[i].end(), greater<int>());
        }
        cout << i << ") ";
        for (int j = 0; j < vs[i].size(); j++) 
        {
            cout << vs[i][j] << ' ';
        }
            cout << endl;  
    }
    return 0;
}
