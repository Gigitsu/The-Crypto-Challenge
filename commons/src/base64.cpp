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
    }

    string encodeTriple(int c1, int c2, int c3) {
        const char b[4] = {
                toASCII(c1 >> 2 & 0x3F),
                toASCII((c1 << 4 & 0x30) | (c2 >> 4 & 0xF)),
                toASCII((c2 << 2 & 0x3C) | (c3 >> 6 & 0x3)),
                toASCII(c3 & 0x3F)
        };


        return string(b, 4);
    }

    string encode(vector<int> hex) {
        string encoded = "";

        for (int i = 0; i < hex.size(); i = i + 3) {
            encoded = encoded + encodeTriple(hex[i], hex[i + 1], hex[i + 2]);
        }

        return encoded;
    }

    int decode() {
        return 0;
    }
}