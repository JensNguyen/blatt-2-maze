//
// Created by rudi on 04.05.2017.
//

#include <iostream>
#include "shortest_path/breadth_first_search/BreathFirstSearch.h"
#include "shortest_path/breadth_first_search/BreathFirstSearchLib.h"

void printString(const int ROWS, const int COLUMNS, const string &solution);

int main(){
    const int ROWS = 15;
    const int COLUMNS = 15;

    char maze[] = {
            '#','S','#','#','#','#','#','#','#','#','#','#','#','#','#',
            '#','.','.','.','.','.','.','.','#','.','.','.','.','.','#',
            '#','.','#','#','#','#','#','.','#','#','#','#','#','.','#',
            '#','.','#','#','#','#','#','.','#','#','#','#','#','.','#',
            '#','.','.','.','.','.','.','.','.','.','.','.','.','.','#',
            '#','.','#','#','.','#','#','#','#','#','.','#','#','.','#',
            '#','.','#','#','.','#','#','#','#','#','.','#','#','.','#',
            '#','.','#','#','.','.','.','.','.','.','.','#','#','.','#',
            '#','.','#','#','.','#','#','#','#','#','.','#','#','#','#',
            '#','.','#','#','.','#','#','#','#','#','.','#','#','.','#',
            '#','.','.','.','.','.','.','.','.','.','.','.','.','.','#',
            '#','.','#','#','#','#','#','.','#','#','#','#','#','.','#',
            '#','.','#','#','#','#','#','#','#','#','#','#','#','#','#',
            '#','.','.','.','.','.','.','.','.','.','.','.','.','.','#',
            '#','#','#','#','#','#','#','#','#','#','#','#','#','G','#'
    };

    cout<<"Vorgabe"<<endl;
    BreathFirstSearchLib::paintMatrix(COLUMNS, ROWS, maze);

    BreathFirstSearch bfs = BreathFirstSearch(COLUMNS, ROWS, maze);
    int steps = bfs.solve();

    cout<<"Loesung"<<endl;
    printf("%d steps required \r\n", steps);
    BreathFirstSearchLib::paintMatrix(COLUMNS, ROWS, bfs.getSolution());

    return 0;
}

void printString(const int ROWS, const int COLUMNS, const string &solution) {
    int row = 0;
    int column = 0;
    int counter = 0;
    for(row; row < ROWS; row++){
        column = 0;
        for(column; column < COLUMNS; column++){
            cout<<solution[counter];
            counter++;
        }
        cout<<endl;
    }
}