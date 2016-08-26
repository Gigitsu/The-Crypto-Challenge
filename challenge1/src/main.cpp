#include <fstream>
#include <iostream>
#include <vector>

#include "config.h"
#include "base64.h"
#include "io.h"

using namespace std;

int main() {
    auto hex = io::readWholeFile(HEX_FILE, io::hex);
    auto b64 = io::readWholeFile(BASE64_FILE);

    if (base64::encode(hex) == b64 && base64::encode({65, 66}) == "QUI=" && base64::encode({65}) == "QQ==" && base64::encode({66}) == "Qg==")
        cout << "Base64 algorithm works fine" << std::endl;
    else
        cout << "Base64 algorithm produces wrong results" << std::endl;

    return 0;
}