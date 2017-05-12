#ifndef MAZEGUI_H
#define MAZEGUI_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <vector>
#include <qmainwindow.h>
#include "recursivemazesolvealgorithm.h"
#include "maze.h"

namespace Ui {
class MazeGui;
}

class MazeGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit MazeGui(QWidget *parent = 0);
    ~MazeGui();
    void setMaze(Maze *maze);
    void drawEmptyMaze();
    void drawMaze();

public slots:
    void startAlgorithm();
    void generateMaze();
    void updateMazeSlot();
    void updateLCDDisplaysSlot();

private:
    Ui::MazeGui *ui;
    QGraphicsScene *scene; //Scene contains the maze rect field
    Maze *m_maze;
    MazeSolveAlgorithm *m_algorithm; //pointer to the choosen maze solve algorithm
    std::vector<QGraphicsRectItem*> m_mazeFields; //vector contains all rects of the maze field
    std::vector<QBrush> m_brushes;
    std::vector<QPen> m_pens;

    void setPensAndBrushes();
    //Enum contains all possible algorithm
    enum {WallFollower=0, TremauxsAlgorithm, Recursive, ShortestPath};
};

#endif // MAZEGUI_H
