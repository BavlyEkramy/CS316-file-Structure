#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int SizeOfRecords = 100;
int delimiter = 99999;
int delimiterDeleted = 99900;

//                                     Get all sets for test

void get() {
    ifstream file{"C:\\Users\\20128\\Desktop\\Lavel-3\\Term-2\\CS 316\\Projects\\CS316-file-Structure\\data.dat",
                  ios::in | ios::binary};
    file.seekg(0);
    vector<vector<int> > vecto;

    vector<int> rec;
    int val;
    while (!file.eof()) {
        file.read(reinterpret_cast<char *>(&val), sizeof(int));
        if (val == delimiter) {
            vecto.push_back(rec);
            rec.clear();
        } else if (val == delimiterDeleted) {
            rec.clear();
            vecto.push_back(rec);
        } else {
            rec.push_back(val);
        }
    }
    SizeOfRecords = vecto.size() - 1;
    for (int i = 0; i < SizeOfRecords; i++) {
        cout << "\n " << i + 1 << " ==> ";
        for (int j = 0; j < vecto[i].size(); j++) {
            cout << vecto[i][j] << " ";
        }
        cout << endl;
    }
}

void InsertSet() {
    int n, k;
    cout << "Enter the size of new set : ";
    cin >> n;
    cout << "\n Enter the integer numbers of new set separated by space : ";
    ofstream file_data{"C:\\Users\\20128\\Desktop\\Lavel-3\\Term-2\\CS 316\\Projects\\CS316-file-Structure\\data.dat",
                       ios::out | ios::binary | ios::app};
//    file_data.seekp(0, ios::end);
    while (n--) {
        cin >> k;
        file_data.write(reinterpret_cast<const char *>(&k), sizeof(int));
    }
    file_data.write(reinterpret_cast<const char *>(&delimiter), sizeof(int));
    SizeOfRecords++;
    cout << "\nThe new set has been added successfully. \n";
}

int sizeOfSeek(int n) {
    ifstream file{"C:\\Users\\20128\\Desktop\\Lavel-3\\Term-2\\CS 316\\Projects\\CS316-file-Structure\\data.dat",
                  ios::in | ios::binary};
    file.seekg(0);
    int ans = -1, val;
    while (n > 0) {
        file.read(reinterpret_cast<char *>(&val), sizeof(int));
        if (val == delimiter || val == delimiterDeleted) {
            n--;
        }
        ans++;
    }
    return ans * 4;
}

void DeleteSet() {
    cout << "\nEnter the index of the set to be deleted from 1 to " << SizeOfRecords << " : ";
    int DelIndex = -1;
    cin >> DelIndex;
    while (DelIndex <= 0 || DelIndex > SizeOfRecords) {
        cout << "\nInvalid Input";
        cout << "\nEnter the index of the set to be deleted from 1 to " << SizeOfRecords << " : ";
        cin >> DelIndex;
    }
    int seek = sizeOfSeek(DelIndex);
    fstream file_data{"C:\\Users\\20128\\Desktop\\Lavel-3\\Term-2\\CS 316\\Projects\\CS316-file-Structure\\data.dat",
                      ios::out | ios::in | ios::binary};
    file_data.seekp(seek, ios::beg);
    file_data.write(reinterpret_cast< char *>(&delimiterDeleted), sizeof(int));
    cout << "\nThe set has been deleted . \n";
}

void Request() {
    cout << "\nEnter request\n"
         << " 1 - Insert new set at the end\n"
         << " 2 - Delete set by the index\n"
         << " 3 - Get all sets\n"
         << " 0 - Close The Program\n";
    int type;
    do {
        cout << "\n? ";
        cin >> type;

        if (type == 1) {
            InsertSet();
        } else if (type == 2) {
            DeleteSet();
        } else if (type == 3) {
            get();
        } else if (type == 0) {
            exit(0);
        }
        cout << "\nError enter request\n"
             << " 1 - Insert new set at the end\n"
             << " 2 - Delete set by the index\n"
             << " 3 - Get all sets\n"
             << " 0 - Close The Program\n";
    } while (type != 0);
}

int main() {
    get();
    Request();
}

