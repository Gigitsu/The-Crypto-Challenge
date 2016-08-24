#include <fstream>
#include <iostream>
#include <vector>

#include "config.h"
#include "base64.h"

using namespace std;

string readBase64File() {
    ifstream in(BASE64_FILE, ios::ate | ios::in | ios::binary);

    string str(in.tellg(), ' ');

    in.seekg(0, ios::beg);
    in.read(&str[0], str.size());

    return str;
}

vector<char> readHexFile() {
    ifstream in(HEX_FILE, ios::ate | ios::in | ios::binary);
    auto size = in.tellg();

    if (size % 2 != 0) {
        throw runtime_error("The input string is not odd!");
    }

    vector<char> ret(size / 2);

    in.seekg(0, ios::beg);

    for (auto i = 0; i < ret.size(); ++i) {
        string str(2, ' ');
        in.read(&str[0], 2);
        ret[i] = (stoi(str, 0, 16));
    }

    return ret;
}

int main() {
    auto hex = readHexFile();
    auto b64 = readBase64File();

    if (base64::encode(hex) == b64 && base64::encode({65, 66}) == "QUI=" && base64::encode({65}) == "QQ==" && base64::encode({66}) == "Qg==")
        cout << "Base64 algorithm works fine" << std::endl;
    else
        cout << "Base64 algorithm produces wrong results" << std::endl;

    return 0;
}