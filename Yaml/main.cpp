#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>

using namespace std;

class YamlParser {
private:
    unordered_map<string, variant<string, int, vector<string>>> data;

    string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        size_t last = str.find_last_not_of(" \t\n\r");
        return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
    }

public:
    YamlParser(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string line;
        string currentKey;
        vector<string> listValues;
        bool isList = false;

        while (getline(file, line)) {
            line = trim(line);

            if (line.empty() || line[0] == '#') continue;

            if (isList && line[0] == '-') {
                listValues.push_back(trim(line.substr(1)));
            } 

            else {
                if (isList) {
                    data[currentKey] = listValues;
                    listValues.clear();
                    isList = false;
                }

                size_t separator = line.find(":");
                if (separator != string::npos) {
                    currentKey = trim(line.substr(0, separator));
                    string value = trim(line.substr(separator + 1));

                    if (value.empty()) {
                        isList = true;
                    } else if (isdigit(value[0])) {
                        data[currentKey] = stoi(value);
                    } else {
                        data[currentKey] = value;
                    }
                }
            }
        }

        if (isList) {
            data[currentKey] = listValues;
        }

        file.close();
    }

    string getString(const string& key) {
        if (data.count(key) && holds_alternative<string>(data[key])) {
            return get<string>(data[key]);
        }
        return "";
    }

    int getInt(const string& key) {
        if (data.count(key) && holds_alternative<int>(data[key])) {
            return get<int>(data[key]);
        }
        return 0;
    }

    vector<string> getStringList(const string& key) {
        if (data.count(key) && holds_alternative<vector<string>>(data[key])) {
            return get<vector<string>>(data[key]);
        }
        return {};
    }
};

int main() {
    YamlParser parser("example.yaml");

    string name = parser.getString("name");
    int age = parser.getInt("age");
    vector<string> items = parser.getStringList("items");

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Items: " << endl;
    for (const auto& item : items) {
        cout << "- " << item << endl;
    }

    return 0;
}
