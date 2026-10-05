#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool validarData(const string& data) {
    if (data.length() != 10) {
        return false;
    }

    if (data[2] != '/' || data[5] != '/') {
        return false;
    }

    for (int i = 0; i < data.length(); i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    string data;

    cout << "Digite a data (dd/mm/aaaa): ";
    cin >> data;

    if (validarData(data)) {
        cout << "Data válida!" << endl;
    } else {
        cout << "Data inválida!" << endl;
    }

    return 0;
}