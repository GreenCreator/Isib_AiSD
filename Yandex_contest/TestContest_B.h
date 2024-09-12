#include <vector>
#include "iostream"

enum Status {
    Day, Hour, Minute, Id, Status
};

void SetIdRocket(std::vector<int> &idRockets, int id) {
    for (int i = 0; i < idRockets.size(); ++i) {
        if (idRockets[i] == id) {
            return;
        }
    }
    idRockets.push_back(id);
}

int Partition(std::vector<std::vector<int>> &rocketData, int left, int right) {
    int pivot = rocketData[right][Day] * 24 * 60 + rocketData[right][Hour] * 60 + rocketData[right][Minute];
    int i = left - 1;

    for (int j = left; j <= right; j++) {
        int minuntes = rocketData[j][Day] * 24 * 60 + rocketData[j][Hour] * 60 + rocketData[j][Minute];
        if (minuntes < pivot) {
            i++;
            std::swap(rocketData[i], rocketData[j]);
        }
    }
    std::swap(rocketData[i + 1], rocketData[right]);
    return i + 1;
}

void QuickSort(std::vector<std::vector<int>> &rocketData, int left, int right) {
    if (right <= left) {
        return;
    }

    int p = Partition(rocketData, left, right);
    QuickSort(rocketData, left, p - 1);
    QuickSort(rocketData, p + 1, right);
}

int GetMinutesBetweenTime(int day, int hour, int minutes, int day_2, int hour_2, int minutes_2) {
    int time = day * 24 * 60 + hour * 60 + minutes;
    int time_2 = day_2 * 24 * 60 + hour_2 * 60 + minutes_2;

    return time_2 - time;
}

void FindWay(std::vector<std::vector<int>> &rocketData) {
    QuickSort(rocketData, 0, rocketData.size() - 1);

    int id = 0;
    int time = 0;

    for (int i = 0; i < rocketData.size(); ++i) {
        if (rocketData[i][Status] == (int) 'A') {
            id = i;
        } else {
            time += GetMinutesBetweenTime(rocketData[id][Day], rocketData[id][Hour], rocketData[id][Minute],
                                          rocketData[i][Day], rocketData[i][Hour], rocketData[i][Minute]);
            id = i;
        }
    }


    std::cout << time << " ";
}

std::vector<std::vector<int>> Input(int N, std::vector<int> &idRockets) {

    std::vector<std::vector<int>> data;

    std::string input;
    for (int i = 0; i < N; ++i) {
        std::vector<int> dataWay;
        for (int j = 0; j < Status + 1; ++j) {

            if (j != Status) {
                int data;
                std::getline(std::cin, input, ' ');
                data = std::stoi(input);
                dataWay.push_back(data);
                if (j == Id) {
                    SetIdRocket(idRockets, data);
                }
            } else {
                char data;
                std::getline(std::cin, input);
                data = input[0];
                dataWay.push_back((int) data);
            }
        }
        data.push_back(dataWay);
    }

    return data;
}

void Init() {
    int N = 0;

    std::string input;

    std::vector<int> idRockets;

    std::getline(std::cin, input);
    N = std::stoi(input);

    std::vector<std::vector<int>> data = Input(N, idRockets);

    std::vector<std::vector<int>> rocketData;

    for (int k = 0; k < idRockets.size(); ++k) {
        for (int i = 0; i < data.size(); ++i) {
            if (data[i][Id] == idRockets[k]) {
                std::vector<int> dataWay;
                for (int j = 0; j < data[i].size(); ++j) {
                    dataWay.push_back(data[i][j]);
                }
                rocketData.push_back(dataWay);
            }
        }
        FindWay(rocketData);
        rocketData.clear();
    }
}
