#include <iostream>
#include <string>
using namespace std;

string replaceExpressions(string input) {
    string result = "";
    size_t pos = 0;
    while (pos < input.size()) {
        size_t space_pos = input.find(' ', pos);
        if (space_pos == string::npos) {
            space_pos = input.size();
        }
        string token = input.substr(pos, space_pos - pos);
        if (token.find('+') != string::npos || token.find('-') != string::npos) {
            size_t op_pos = token.find_first_of("+-");
            int n1 = stoi(token.substr(0, op_pos));
            int n2 = stoi(token.substr(op_pos + 1));
            char op = token[op_pos];
            int resultNum;
            if (op == '+') {
                resultNum = n1 + n2;
            }
            else {
                resultNum = n1 - n2;
            }
            result += to_string(resultNum) + " ";
        }
        else {
            result += token + " ";
        }
        pos = space_pos + 1;
    }

    return result;
}

int main() {
    string text = "alpha 5+26 beta 72-35 gamma 32+45 etc";
    string editText = replaceExpressions(text);
    cout << editText << endl;
    return 0;
}



