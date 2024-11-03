#include <iostream>
#include <vector>
#include <string>


using namespace std;


//проверка, принадлежит ли значение массиву
bool includes(vector<int>& arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) return true;
    }
    return false;
}


class DFA {
private:
    vector<int> states;
    vector<int> alphabet;
    int start;
    vector<int> terminate;
    vector<vector<int>> transitions;

public:
    DFA(vector<int> states, vector<int> alphabet, int start, vector<int> terminate, vector<vector<int>> transitions) :
        states(states),
        alphabet(alphabet),
        start(start),
        terminate(terminate),
        transitions(transitions)
    {}

    //допускает ли автомат строку
    bool match(string str) {
        int curState = start, nextState, c;
        for (int i = 0; i < str.size(); i++) {
            c = str[i] - '0';
            nextState = transitions[curState][c];
            curState = nextState;
        }
        return (includes(terminate, curState)) ? true : false;
    }

    //вывод на экран
    void checkTest(string str) {
        if (this->match(str)) cout << str << ": TRUE" << endl;
        else cout << str << ": FALSE" << endl;
    }
};

