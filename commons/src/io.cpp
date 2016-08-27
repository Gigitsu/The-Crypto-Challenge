#include <fstream>
#include <vector>

using namespace std;

namespace io {
    static const int hex = 1;

    string readWholeFile(const char *file, int mode = 0) {
        ifstream in(file, ios::ate | ios::in | ios::binary);
        auto size = in.tellg();
        in.seekg(0, ios::beg);
        string content;

        if (mode & hex == hex) {
            if (size % 2 != 0)
                throw runtime_error("The input string is odd!");

            content = string(size / 2, ' ');

            for (auto i = 0; i < content.size(); ++i) {
                string tmp(2, ' ');
                in.read(&tmp[0], 2);
                content[i] = (stoi(tmp, 0, 16));
            }
        } else {
            content = string(size, ' ');
            in.read(&content[0], content.size());
        }

        return content;
    }
}