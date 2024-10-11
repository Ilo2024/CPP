#include <iostream>
#include <cstring>

using namespace std;

int findSubstring(char t1[], char t2[]) {

    char* pos = strstr(t2, t1);

    if (pos == NULL) {
        return -1;
    }
    return pos - t2;
}

int main() {
    char t1[100], t2[100];

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
