//
// Created by mohamedessam on 12/5/19.
//
#include "Recognizer.h"
#define dot  '.'
#define zero '0'
#define initState 0

void printVector(vector<char>input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

vector<char> Recognizer::readInput(int numberOfChar) {
    vector <char > inputVector;
    char character;
    while (numberOfChar > 0){
        cout<<"input: ";
        cin>>character;
        if (!(isdigit(character)||character ==dot)){
            cout<<"Wrong Input, it must be only digit or dots"<<endl;
            exit(1);
        }
        inputVector.push_back(character);
        numberOfChar --;
    }
    string str(inputVector.begin(), inputVector.end());
    cout<<"your input: "<<str<<endl;
    return  inputVector;
}

int Recognizer::move(int state, char character) {
    int newState;
    switch (state){
        case 0: if (character==zero)newState = 2;if (((int)character-48) > 0)newState = 1;if (character==dot)newState = 5;break;
        case 1:if (((int)character-48) > 0||character==zero)newState = 1;else newState = 3;break;
        case 2:if (((int)character-48) > 0||character==zero)newState = 5;else newState = 3;break;
        case 3:if (((int)character-48) > 0||character==zero)newState = 4;else newState = 5;break;
        case 4:if (((int)character-48) > 0||character==zero)newState = 4;else newState = 5;break;
        case 5:newState = 5;break;
    }
    return newState;
}

int Recognizer::updateState(int oldState, char character) {
    int newState;
    string strOldState , strNewState;
    if (oldState==5)strOldState="error state";else strOldState=to_string(oldState);
    newState = move(oldState, character);
    if (newState==5)strNewState="error state";else strNewState=to_string(newState);
    cout<<"state("<<strOldState<<")"<<" ---> "<<"state("<<strNewState<< ")  ";
    return newState;
}

void Recognizer::run(){
    int noOfChar, newState = initState;
    cout<<"Enter Size of Input : ";
    cin>>noOfChar;
    vector<char> inputVector = readInput(noOfChar);
    for (int i = 0; i < inputVector.size(); i++) {
        newState = updateState(newState,inputVector.at(i));
    }
}