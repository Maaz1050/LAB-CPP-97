#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream fout;
    string line;

    fout.open("sample.txt");
    
    // Check if the file failed to open
    if (!fout.is_open()) {
        cerr << "Error: Could not create or open the file for writing!" << endl;
        return 1;
    }

    cout << "Enter text (Type -1 on a new line to stop and see output):" << endl;

    // A safer way to loop standard input
    while (getline(cin, line)) {
        if (line == "-1")
            break;
        fout << line << endl;
    }
    fout.close();

    // Reading phase
    ifstream fin;
    fin.open("sample.txt");
    
    // Check if the file failed to open for reading
    if (!fin.is_open()) {
        cerr << "Error: Could not open the file for reading!" << endl;
        return 1;
    }

    cout << "\n--- File Contents ---" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    return 0;
}
