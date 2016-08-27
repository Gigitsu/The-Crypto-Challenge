#include <fstream>
#include <iostream>
#include <vector>

#include "config.h"
#include "binary.h"
#include "io.h"

using namespace std;

int main() {
    string first = io::readWholeFile(HEX_FIRST_FILE, io::hex);
    string second = io::readWholeFile(HEX_SECOND_FILE, io::hex);

    if(binary::exclusiveOr(first, second) == io::readWholeFile(EXPECTED_FILE, io::hex))
        cout << "Xor algorithm works fine" << std::endl;
    else
        cout << "Xor algorithm produces wrong results" << std::endl;

    return 0;
}