#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    string result;
    cout << "Enter the line: " << endl;
    getline(cin, line);

    // replace to lower chars
    for (int i = 0; i < line.length(); i++) {
        line[i] = tolower(line[i]);
    }

    // database of chars we know
    char *knownChars = new char();
    int databaseSize = 0;

    // Magic
    for (int i = 0; i < line.length(); i++) {
        char currentChar = line[i];
        bool found = false;

        // search in database
        for (int j = 0; j < databaseSize; j++) {
            if (currentChar == knownChars[j]) {
                // We know there are many, go on
                found = true;
                result += ')';
                break;
            }
        }

        if (found) continue;

        // start search others boys
        for (int j = i + 1; j < line.size(); j++) {
            if (currentChar == line[j]) {
                found = true;
                knownChars[databaseSize] = currentChar;
                databaseSize++;
                result += ')';
                break;
            }
        }

        if (!found) {
            result += '(';
        }
    }

    // print text
    cout << "Entered string: " << line << endl;
    cout << "Output string: " << result << endl;
    cout << "Press Enter to contunue.";
    cin.get();
}
