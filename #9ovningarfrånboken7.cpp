#include <iostream>
#include <cstring>
using namespace std;

bool copyString(const char* source, char* destination, size_t destSize) {

    if (strlen(source) + 1 > destSize) {
        return false;
    }
    strncpy(destination, source, destSize);
    destination[destSize - 1] = '\0';

    return true;
}

int main() {
    const char* source = "Hello friend!";
    char destination[20];

    if (copyString(source, destination, sizeof(destination))) {
        cout << "Copy failed: " << destination << endl;
    } else {
        cout << "Copy failed, destination to small!" << endl;
    }
    return 0;
}
