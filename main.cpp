#include <iostream>
#include <array>

const int BOARD_SIZE = 3;
const std::string ROW_SEPARATOR = "\n---+---+---\n";
struct coords {
    int x;
    int y;
} playCoords;
int play = -1;
char player = 'X';
bool gameOver = false;
std::string cells[BOARD_SIZE][BOARD_SIZE] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}};

bool IsDiagPlay(coords playCoords) {
    bool ret = false;

    // LTR diag
    if(playCoords.x == playCoords.y) {
        return true;
    }

    // RTL diag
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = BOARD_SIZE; j >= 0; j--) {
            if(playCoords.x == i && playCoords.y == j) {
                return true;
            }
        }
    }
}

void Greet()
{
    system("clear");
    std::cout << "\n--- YEAH TIC TAC TOE GAME ---\n\n";
    std::cout << "Use num pad to play. Here are the controls:\n\n";
    std::cout << " 7 | 8 | 9 " << ROW_SEPARATOR;
    std::cout << " 4 | 5 | 6 " << ROW_SEPARATOR;
    std::cout << " 1 | 2 | 3 \n\n";
    std::cout << "Have fun!\n\n";
}

void Render()
{
    std::string row = "";
    std::string render = "";

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            row += " " + cells[i][j] + " |";
        }
        row.pop_back();
        render += row + ROW_SEPARATOR;
        row = "";
    }

    render = render.substr(0, render.size() - ROW_SEPARATOR.size());
    std::cout << render << "\n\n";
}

int Play()
{
    std::cout << "Player " << player << " is playing...\n";
    std::cin >> play;
    //TODO: check 1<=int<=9
    //if ()
}

void Update()
{
    // Translate play into (x,y) coords
    switch(play) {
       case 7: {
           playCoords.x = 0;
           playCoords.y = 0;
           break;
       }
       case 8: {
           playCoords.x = 0;
           playCoords.y = 1;
           break;
       }
       case 9: {
           playCoords.x = 0;
           playCoords.y = 2;
           break;
       }
       case 4: {
           playCoords.x = 1;
           playCoords.y = 0;
           break;
       }
       case 5: {
           playCoords.x = 1;
           playCoords.y = 1;
           break;
       }
       case 6: {
           playCoords.x = 1;
           playCoords.y = 2;
           break;
       }
       case 1: {
           playCoords.x = 2;
           playCoords.y = 0;
           break;
       }
       case 2: {
           playCoords.x = 2;
           playCoords.y = 1;
           break;
       }
       case 3: {
           playCoords.x = 2;
           playCoords.y = 2;
           break;
       }
    }

    // Update 
    cells[playCoords.x][playCoords.y] = player;
    player = (player == 'X') ? 'O' : 'X';
}

bool GameOver() 
{
    // Row
    std::string row = "";
    for (int i = 0; i < BOARD_SIZE && !gameOver; i++)
    {
        row += cells[playCoords.x][i];
    }
    if(row == "XXX" || row == "OOO") return true;

    // Col
    std::string col = "";
    for (int i = 0; i < BOARD_SIZE && !gameOver; i++)
    {
        col += cells[i][playCoords.y];
    }
    if(col == "XXX" || col == "OOO") return true;

    // LTR diag
    std::string ltrDiag = "";
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            ltrDiag += cells[i][j];
        }
    }
    if(ltrDiag == "XXX" || ltrDiag == "OOO") return true;

    // RTL diag
    std::string rtlDiag = "";
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = BOARD_SIZE; j >= 0; j--) {
            rtlDiag += cells[i][j];
        }
    }
    if(rtlDiag == "XXX" || rtlDiag == "OOO") return true;

    return false;
}

int main()
{
    gameOver = false;
    while(!gameOver){
        Greet();
        Render();
        Play();
        Update();
        gameOver = GameOver();
    }

    return 0;
}