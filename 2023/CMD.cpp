#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> Dir, vector<vector<string>> Cmd) {
    string current_folder = "C:/root";
    map <string, int> m;
    for (int i = 0; i < Dir.size(); i++) {
        if (Dir[i].find(".") == string::npos) {
            m[Dir[i]] = 1;
        }
    }

    for (int i = 0; i < Cmd.size(); i++) {
        string command = Cmd[i][0];
        string value = Cmd[i][1];
        string temp;
        if (Cmd[i][0] == "CD") {
            if (value.find("C:") != string::npos) {
                temp = value;
            }
            else {
                temp = current_folder + "/" + value;
            } 
            if (m[temp]) {
                current_folder = temp;
            }
        }
    }
    return current_folder;
}