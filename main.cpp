#include <iostream>
#include <array>

const int BOARD_SIZE = 3;
const std::string ROW_SEPARATOR = "\n---+---+---\n";

void DisplayHelloMessage()
{
    system("clear");
    std::cout << "\n--- YEAH TIC TAC TOE GAME ---\n\n";
    std::cout << "Use num pad to play. Here are the controls:\n\n";
    std::cout << " 7 | 8 | 9 " << ROW_SEPARATOR;
    std::cout << " 4 | 5 | 6 " << ROW_SEPARATOR;
    std::cout << " 1 | 2 | 3 \n\n";
    std::cout << "Have fun!\n\n";
}

void Render(std::string cells[BOARD_SIZE][BOARD_SIZE])
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

int Play(char player)
{
    int cellChoice;

    std::cout << "Player " << player << " is playing...\n";

    std::cin >> cellChoice;
    //TODO: check 1<=int<=9
    //if ()
    return cellChoice;
}

int main()
{
    std::string cells[BOARD_SIZE][BOARD_SIZE] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}};
    int cellChoice;
    char player = 'X';

    // while(true){
    DisplayHelloMessage();
    Render(cells);
    Play(player);
    // //Update();
    // }

    return 0;
}