#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

struct plan {
    int data;
    vector <int> service;
};

struct client {
    int data;
    vector <int> service;
};

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    vector<int> answer;

    vector <plan> Plan;
    vector <client> Client;
    vector<string> plan_split;
    vector<string> clients_split;

    for (int i = 0; i < plans.size(); i++) {
        plan_split = split(plans[i], ' ');
        Plan[i].data = stoi(plan_split[0]);
        for (int j = 1; j < plan_split.size(); j++) {
            Plan[i].service[j-1] = (stoi(plan_split[j]));
        }
    }

    for (int i = 0; i < clients.size(); i++) {
        clients_split = split(clients[i], ' ');
        Client[i].data = stoi(clients_split[0]);
        cout << Client[i].data;
        for (int j = 1; j < clients_split.size(); j++) {
            Client[i].service.push_back(stoi(clients_split[j]));
        }
    }

    bool check = true;
    cout << Client.size();
    for (int i = 0; i < Client.size(); i++) {
        int index = 0;
        int Provide[300001];
        int Client_data = Client[i].data;
        for (int j = 0; j < Plan.size(); j++) {
            if (Client_data > Plan[j].data) {
                for (int k = 0; k < Plan[j].service.size(); k++) {
                    if (Plan[j].service[k] == 0) {
                        break;
                    }
                    Provide[Plan[j].service[k]] = 1;
                }
            }
            if (Client_data < Plan[j].data) {
                for (int k = 0; k < Plan[j].service.size(); k++) {
                    if (Plan[j].service[k] == 0) {
                        break;
                    }
                    Provide[Plan[j].service[k]] = 1;
                }
                for (int k = 0; k < 21; k++) {
                    if (Client[j].service[k] == 0) {
                        break;
                    }
                    if (Provide[Client[j].service[k]] != 1) {
                        check = false;
                    }
                }
            }
            if (check) {
                index = j;
            }
        }
        answer.push_back(index);
    }

    return answer;
}