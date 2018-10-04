#include <string>
using namespace std;

string stringCompresssion(const string& input) {
    string output;
    int sameCounter = 1;
    
    vector<string> dynamicString;
    int dynamicStringLen = 0;
    
    char lastChar = 0; // null character
    for(int i = 0; i < input.size(); i++) {
        if (input[i] == lastChar) {
            sameCounter++;
        } else {
            dynamicString.push_back(input[i]);
            string numLen = to_string(sameCounter);
            dynamicString.push_back(numLen);
            dynamicStringLen += (1 + numLen.size());
            lastChar = input[i];
        }
    }
    
    output.reserve(dynamicStringLen);
    for(auto &s : dynamicString) {
        output += s;
    }
    
    if (output.size() > input.size()) {
        return input;
    }
    return output;
}
