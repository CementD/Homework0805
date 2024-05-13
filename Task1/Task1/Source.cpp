#include <iostream>
using namespace std;

string insertBrackets(string text, string toFind) {
	string editText = text;
	size_t pos = editText.find(toFind);
	while (pos != toFind.npos) {
		editText.insert(pos, "(");
		editText.insert(pos + toFind.length() + 1, ")");
		pos = editText.find(toFind, pos + 2);
	}
	return editText;
}

int main() {
	string text = "abaracadabra";
	string toFind = "ab";
	string editText = insertBrackets(text, toFind);
	cout << editText << endl;
	
	return 0;
}