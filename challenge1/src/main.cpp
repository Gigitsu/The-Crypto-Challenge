#include <fstream>
#include <iostream>
#include <vector>

#include "config.h"
#include "base64.h"

using namespace std;

string readBase64File()
{
    ifstream in(BASE64_FILE, ios::ate | ios::in | ios::binary);

    string str(in.tellg(), ' ');

    in.seekg(0, ios::beg);
    in.read(&str[0], str.size());

    return str;
}

vector<int> readHexFile()
{
    ifstream in(HEX_FILE, ios::ate | ios::in | ios::binary);
    auto size = in.tellg();

    if(size % 2 != 0) {
        throw runtime_error("The input string is not odd!");
    }

    vector<int> ret(size / 2);

    in.seekg(0, ios::beg);

    for(auto i = 0; i < ret.size(); ++i) {
        string str(2, ' ');
        in.read(&str[0], 2);
        ret[i] = (stoi(str, 0, 16));
    }

    return ret;
}

int main() {
    auto hex = readHexFile();
    auto b64 = readBase64File();

    //cout << (base64::encode(hex) == b64) << std::endl;
    cout << base64::encode({65, 66, 67}) << std::endl;

    return 0;
}