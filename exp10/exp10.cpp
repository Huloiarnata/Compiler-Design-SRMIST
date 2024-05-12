#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string newLabel() {
    static int labelCounter = 0;
    stringstream ss;
    ss << "L" << labelCounter++;
    return ss.str();
}

string generateIf(string E, string S1, string S_NEXT, bool hasElse = false) {
    string TRUE = newLabel(), FALSE = S_NEXT;
    string code = E + " TRUE: " + TRUE + "\nFALSE: " + FALSE + "\n" + S1 + "\n";
    if (hasElse) {
        string ELSE = newLabel();
        code += "goto " + ELSE + "\n" + TRUE + ": \n";
        TRUE = ELSE;
    }
    code += TRUE + ": \n";
    return code;
}

string generateWhile(string E, string S1) {
    string BEGIN = newLabel(), TRUE = newLabel(), NEXT = newLabel();
    return BEGIN + ": \n" + E + " TRUE: " + TRUE + "\nFALSE: " + NEXT + "\n" +
           S1 + "\ngoto " + BEGIN + "\n" + NEXT + ": \n";
}

int main() {
    string E = "if (condition)", S1 = "cout << \"Condition is true\";", S2 = "cout << \"Condition is false\";", S_NEXT = "end;";
    cout << "Intermediate code for if-else:\n" << generateIf(E, S1, S2, true) << endl;
    cout << "Intermediate code for if:\n" << generateIf(E, S1, S_NEXT) << endl;
    cout << "Intermediate code for while:\n" << generateWhile(E, S1) << endl;
    return 0;
}
