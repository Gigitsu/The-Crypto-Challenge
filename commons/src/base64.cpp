#include <string>
#include <vector>

using namespace std;

namespace base64 {

    char toASCII(int e) {
        if (e < 26) return e + 65;
        else if (e < 52) return e + 71;
        else if (e < 62) return e - 4;
        else if (e == 62) return '+';
        else if (e == 63) return '/';
        else return '=';
    }

    string encodeTriple(char *chars, int size) {
        int c = 0;
        vector<char> encoded{'=', '=', '=', '='};

        for (int i = 0; i < size; ++i)
            c = c | chars[i] << 8 * (2 - i);

        for (int i = 0; i < size + 1; ++i)
            encoded[i] = toASCII(c >> 6 * (3 - i) & 0x3F);

        return string(&encoded[0], 4);
    }

    string encode(vector<char> bytes) {
        string encoded = "";

        for (int i = 0; i < bytes.size(); i = i + 3)
            encoded = encoded + encodeTriple(&bytes[i], min(3, (int) bytes.size() - i));

        return encoded;
    }

    int decode() {
        return 0;
    }
}