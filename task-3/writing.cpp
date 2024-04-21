#include <bits/stdc++.h>
#include <fstream>

using namespace std;
vector<vector<int> > vec;

int main() {
    int delimiter = 99999;
    int m;
    for (int i = 0; i < 100; i++) {
        m = (int) rand() % 6 + 5;
        vector<int> set;
        cout << "\n " << i + 1 << " : size " << m << " ==> ";
        for (int j = 0; j < m; j++) {
            int k = (int) (rand() % 3000) + 1;
            set.push_back(k);
            cout << k << " ";
        }
        vec.push_back(set);
    }
    ofstream file_data{"C:\\Users\\20128\\Desktop\\Lavel-3\\Term-2\\CS 316\\Projects\\CS316-file-Structure\\data.dat",
                       ios::out | ios::binary};
    for (int k = 0; k < vec.size(); ++k) {
        for (int j = 0; j < vec[k].size(); j++) {

            file_data.write(reinterpret_cast<const char *>(&vec[k][j]), sizeof(int));
        }
        file_data.write(reinterpret_cast<const char *>(&delimiter), sizeof(int));
    }
}

