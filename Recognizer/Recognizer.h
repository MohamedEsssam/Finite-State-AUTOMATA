//
// Created by mohamedessam on 12/5/19.
//

#ifndef RECOGNIZER_RECOGNIZER_H
#define RECOGNIZER_RECOGNIZER_H
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
class Recognizer {
public:
    vector <char> readInput(int);
    int move(int, char );
    int updateState(int, char);
    void run();
};
#endif //RECOGNIZER_RECOGNIZER_H

