#include "mazegui.h"
#include "ui_mazegui.h"
#include "recursivemazesolvealgorithm.h"
#include "mazegenerator.h"
#include <unistd.h>

/**
 * @brief MazeGui::MazeGui constructor sets up the gui such es the sockets and slots
 * @param parent
 */
MazeGui::MazeGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MazeGui)
{
    m_maze = nullptr;
    m_algorithm = nullptr;
    setPensAndBrushes();

    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    //button start algorithm
    connect(ui->simulationStartButton,SIGNAL(pressed()),
            this,SLOT(startAlgorithm()));

    //button generate random maze
    connect(ui->generateMazeButton, SIGNAL(pressed()),
            this,SLOT(generateMaze()));
}

/**
 * @brief MazeGui::setMaze Sets the maze
 */
void MazeGui::setMaze(Maze *maze)
{
  m_maze = maze;
}


/**
 * @brief MazeGui::generateField Generates a Maze whith the delivered width and height
 * @param width
 * @param height
 */
void MazeGui::drawEmptyMaze()
{
    QBrush brushWall(Qt::black);
    QPen penWall(Qt::black);
    penWall.setWidth(6);
    scene->clear();
    m_mazeFields.clear();
    for(int i = 0; i< m_maze->getWidth(); i++)
    {
        for(int i2 = 0; i2< m_maze->getHeight(); i2++)
        {
            m_mazeFields.push_back(scene->addRect(i*20,i2*20,15,15,penWall,brushWall));
        }
    }
    ui->mazeGraphicsView->setScene(scene);
}

/**
 * @brief MazeGui::setMaze Gets an two dimensional Array which has the size of the field and contains a colorcode for every field. The colores where set and printed
 * @param field maze field
 * @param width the width of the maze
 * @param height the height of the maze
 */
void MazeGui::drawMaze()
{
    for(int i=0; i< m_maze->getWidth(); i++)
    {
        for(int i2=0; i2< m_maze->getHeight(); i2++)
        {
          switch(m_maze->getMazeField(i,i2)){
          case Maze::Wall:
              m_mazeFields[i*m_maze->getWidth()+i2]->setBrush(m_brushes[Maze::Wall]);
              m_mazeFields[i*m_maze->getWidth()+i2]->setPen(m_pens[Maze::Wall]);
              break;
          case Maze::Way:
              m_mazeFields[i*m_maze->getWidth()+i2]->setBrush(m_brushes[Maze::Way]);
              m_mazeFields[i*m_maze->getWidth()+i2]->setPen(m_pens[Maze::Wall]);
              break;
          case Maze::Start:
              m_mazeFields[i*m_maze->getWidth()+i2]->setBrush(m_brushes[Maze::Start]);
              m_mazeFields[i*m_maze->getWidth()+i2]->setPen(m_pens[Maze::Start]);
              break;
          case Maze::End:
              m_mazeFields[i*m_maze->getWidth()+i2]->setBrush(m_brushes[Maze::End]);
              m_mazeFields[i*m_maze->getWidth()+i2]->setPen(m_pens[Maze::End]);
              break;
          case Maze::Result:
              m_mazeFields[i*m_maze->getWidth()+i2]->setBrush(m_brushes[Maze::Result]);
              m_mazeFields[i*m_maze->getWidth()+i2]->setPen(m_pens[Maze::Result]);
              break;
          }
        }
    }
    ui->mazeGraphicsView->scene()->update();
}

/**
 * @brief MazeGui::startAlgorithm starts the algorithm choosen in the combo box, measures the time,
 *                  sets the display for steps and the elapsed time
 */
void MazeGui::startAlgorithm()
{
    int currentIndex = ui->algorithmCombobox->currentIndex();
    switch (currentIndex)
    {
    case WallFollower:
        break;
    case TremauxsAlgorithm:
        break;
     case Recursive:
        m_algorithm = new RecursiveMazeSolveAlgorithm(m_maze);
        break;
       case ShortestPath:
        break;
    default:
        break;
    }
    connect(m_algorithm,SIGNAL(redraw()),this,SLOT(updateMazeSlot()));
    connect(m_algorithm, SIGNAL(signalLCDDisplays()),this, SLOT(updateLCDDisplaysSlot()));

    m_algorithm->start();
}

/**
 * @brief MazeGui::generateMaze Generates a random maze
 * @param maze array which contains all maze values
 * @param width width of the maze
 * @param height height of the maze
 * @return error code (0 if successful)
 */
void MazeGui::generateMaze()
{
    const int width = ui->widthSpinBox->value();
    const int height = ui->heightSpinBox->value();
    if(width >0 || height > 0)
    {
    delete m_maze;
    m_maze = MazeGenerator::generateMaze(width, height);
    drawEmptyMaze();
    drawMaze();
    }
    }

void MazeGui::updateMazeSlot()
{
    drawMaze();
}

void MazeGui::updateLCDDisplaysSlot()
{
    ui->timeLeftLCDDisplay->display(m_algorithm->getElapsedTime());
    ui->stepLCDDisplay->display(m_algorithm->getSteps());
}

/**
 * @brief MazeGui::setPensAndBrushes sets the pens and brushes for the maze field
 */
void MazeGui::setPensAndBrushes()
{
    //set brushes
    m_brushes.push_back(QBrush(Qt::black));
    m_brushes.push_back(QBrush(Qt::green));
    m_brushes.push_back(QBrush(Qt::white));
    m_brushes.push_back(QBrush(Qt::red));
    m_brushes.push_back(QBrush(Qt::blue));


    //set pens
    QPen pen(Qt::black);
    pen.setWidth(2);
    m_pens.push_back(pen);
    pen.setColor(Qt::green);
    m_pens.push_back(pen);
    pen.setColor(Qt::white);
    m_pens.push_back(pen);
    pen.setColor(Qt::red);
    m_pens.push_back(pen);
    pen.setColor(Qt::blue);
    m_pens.push_back(pen);

}

/**
 * @brief MazeGui::~MazeGui delets all heap elements
 */
MazeGui::~MazeGui()
{
    delete m_algorithm;
    delete m_maze;
    delete ui;
}
