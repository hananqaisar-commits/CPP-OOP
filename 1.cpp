#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;

// Initialize the board
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    currentPlayer = 'X';
    gameOver = false;
}

// Check if a player wins
bool checkWin(char player) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||
            (board[0][i]==player && board[1][i]==player && board[2][i]==player))
            return true;
    if ((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
        (board[0][2]==player && board[1][1]==player && board[2][0]==player))
        return true;
    return false;
}

// Check if board is full
bool boardFull() {
    for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ') return false;
    return true;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 700), "Tic Tac Toe");
    initBoard();

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {
        cout << "Font load failed!" << endl;
        return 1;
    }

    // Grid lines
    sf::RectangleShape lines[4];
    for(int i=0;i<2;i++){
        lines[i].setSize(sf::Vector2f(600,5)); // horizontal
        lines[i].setPosition(0,200*(i+1));
        lines[i].setFillColor(sf::Color::Black);
    }
    for(int i=2;i<4;i++){
        lines[i].setSize(sf::Vector2f(5,600)); // vertical
        lines[i].setPosition(200*(i-1),0);
        lines[i].setFillColor(sf::Color::Black);
    }

    // Reset button
    sf::RectangleShape resetBtn(sf::Vector2f(200,50));
    resetBtn.setPosition(200,620);
    resetBtn.setFillColor(sf::Color(200,200,200));

    sf::Text resetText("RESET", font, 30);
    resetText.setPosition(230,625);
    resetText.setFillColor(sf::Color::Black);

    sf::Text resultText("", font, 40);
    resultText.setPosition(50,650);
    resultText.setFillColor(sf::Color::Red);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if(!gameOver && event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x / 200;
                int y = event.mouseButton.y / 200;
                if(x<3 && y<3 && board[y][x]==' ') {
                    board[y][x] = currentPlayer;
                    if(checkWin(currentPlayer)) {
                        resultText.setString(string("Player ") + currentPlayer + " Wins!");
                        gameOver = true;
                    } else if(boardFull()) {
                        resultText.setString("Draw!");
                        gameOver = true;
                    }
                    currentPlayer = (currentPlayer=='X')?'O':'X';
                }
            }

            // Reset button
            if(event.type==sf::Event::MouseButtonPressed){
                int mx = event.mouseButton.x;
                int my = event.mouseButton.y;
                if(mx>=200 && mx<=400 && my>=620 && my<=670){
                    initBoard();
                    resultText.setString("");
                }
            }
        }

        window.clear(sf::Color::White);

        // Draw grid
        for(int i=0;i<4;i++) window.draw(lines[i]);

        // Draw X/O
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]!=' '){
                    sf::Text text(string(1,board[i][j]), font, 150);
                    text.setPosition(j*200+40, i*200-10);
                    text.setFillColor(board[i][j]=='X'?sf::Color::Blue:sf::Color::Red);
                    window.draw(text);
                }
            }
        }

        // Draw reset button
        window.draw(resetBtn);
        window.draw(resetText);
        window.draw(resultText);

        window.display();
    }

    return 0;
}
