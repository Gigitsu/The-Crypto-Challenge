#include <fstream>
#include <iostream>
#include <vector>
#include "config.h"

using namespace std;

vector<char> readAllBytes(const char *file)
{
    ifstream fl(file, ios::ate | ios::in | ios::binary);
    size_t size = fl.tellg();

    vector<char> ret(size);

    fl.seekg(0, ios::beg);
    fl.read(&ret[0], size);

    return ret;
}

int main() {
    vector<char> hex = readAllBytes(HEX_FILE);

    for(int i = 0; i < hex.size(); ++i) {
        cout << hex[i];
    }

    cout << std::endl;

    return 0;
}