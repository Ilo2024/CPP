#include <iostream>
#include <string>

using namespace std;

int findSubstring(const string& t1, const string& t2) {

    size_t position = t2.find(t1);

    if (position == string::npos) {
        return -1;
    }
    return position;
}

int main() {
    string t1, t2;
    
    cout << "Enter substring t1 without a space: ";
    cin >> t1;
    cout << "Enter the main string t2 without a space: ";
    cin >> t2;

    int result = findSubstring(t1, t2);

    if (result != -1) {
        cout << "The substring starts at the index: " << result << endl;
    } else {
        cout << "Substring could not be found" << endl;
    }
    return 0;
}
