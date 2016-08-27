#include <string>
#include <stdexcept>

using namespace std;

namespace binary {
    string exclusiveOr(string first, string second) {
        if(first.size() != second.size())
            throw runtime_error("Input sizes does not match!");

        string computed(first.size(), ' ');

        for(auto i = 0; i < first.size(); ++i)
            computed[i] = first[i] ^ second[i];

        return computed;
    }
}