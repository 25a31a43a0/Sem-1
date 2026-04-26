#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int x, y, fruitX, fruitY, score;
int gameOver;
int width = 20, height = 20;
int tailX[100], tailY[100];
int nTail;
int dir;


void setup() {
    gameOver = 0;
    dir = 0;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}


void draw() {
    system("cls");

    for(int i = 0; i < width + 2; i++) printf("#");
    printf("\n");

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0) printf("#");

            if(i == y && j == x)
                printf("O");
            else if(i == fruitY && j == fruitX)
                printf("F");
            else {
                int print = 0;
                for(int k = 0; k < nTail; k++) {
                    if(tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if(!print) printf(" ");
            }

            if(j == width - 1) printf("#");
        }
        printf("\n");
    }

    for(int i = 0; i < width + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}


void input() {
    if(kbhit()) {
        switch(getch()) {
            case 'a': dir = 1; break;
            case 'd': dir = 2; break;
            case 'w': dir = 3; break;
            case 's': dir = 4; break;
            case 'x': gameOver = 1; break;
        }
    }
}


void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if(dir == 1) x--;
    else if(dir == 2) x++;
    else if(dir == 3) y--;
    else if(dir == 4) y++;


    if(x >= width || x < 0 || y >= height || y < 0)
        gameOver = 1;


    if(x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
    setup();
    while(!gameOver) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    printf("Game Over! Final Score = %d", score);
    return 0;
}
