#include <vector>

using namespace std;

namespace io {
    static const int hex = 1;
    string readWholeFile(const char *file, int mode = 0);

    vector<char> readFileAsHex(const char *file);
    string readFileAsString(const char *file);
}