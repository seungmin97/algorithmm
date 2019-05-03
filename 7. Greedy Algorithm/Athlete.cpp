//
// Created by 이승민 on 2019-05-03.
//

//https://algospot.com/judge/problem/read/MATCHORDER

////틀림
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Score {

private:
    vector <int> Russia;
    vector <int> Korea;
    int size;
public:
    int result = 0;
    Score(vector <int> Russia, vector <int> Korea, int size) {
        sort(Russia.begin(), Russia.end());
        sort(Korea.begin(), Korea.end());

        this->Russia = Russia;
        this->Korea = Korea;
        this->size = size;
    }
    void check_how_many_win();
};

void Score::check_how_many_win() {
    int index = 0;
    for (int i = 0; i < size; i++) {
        int r = Russia[i];
        for (int j = index; j < size; j++) {
            int k = Korea[j];
            if (r <= k) {
                index = j + 1;
                result += 1;
                break;
            }
        }
    }
}

int main() {

    int num;
    cin >> num;

    vector<Score> s;

    vector <int> Russia;
    vector <int> Korea;
    int size = 0;

    for (int i = 0; i < num; i++) {

        cin >> size;
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            Russia.push_back(temp);
        }
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            Korea.push_back(temp);
        }
        s.push_back(Score(Russia, Korea, size));
        s[i].check_how_many_win();
    }

    for (int i = 0; i < num; i++) {
        cout << s[i].result << endl;
    }

    return 0;
}