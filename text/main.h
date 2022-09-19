#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stack>
#include <algorithm> // min, max
using namespace sf;
using namespace std;

int size = 56;
Vector2f offset(28, 28);

int board[8][8] =
    {-1, -2, -3, -4, -5, -3, -2, -1,
     -6, -6, -6, -6, -6, -6, -6, -6,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0,
     6, 6, 6, 6, 6, 6, 6, 6,
     1, 2, 3, 4, 5, 3, 2, 1};

typedef struct QuanCo
{
    Sprite s;
    int index, cost;
};

class GameManager
{
public:
    QuanCo f[33];              // mang luu cac quan co
    Vector2f positiveMove[32]; // vi tri cac nuoc co the di chuyen
    int positiveCount;         // so nuoc co the di chuyen
    stack<Vector2f> posS;      // luu tru vi tri cac nuoc di
    stack<int> nS;             // luu tru index cua quan di

    void move(int n, Vector2f oldPos, Vector2f newPos); // ham danh co
    void Undo();                                        // ham quay lai
    void Create();
    void Play(); // choi: moi thao tac o day

    void PositiveXe(int n, int x, int y, int grid[9][9]); // tim cac nuoc co the di cua Quan Xe
    void PositiveTuong(int n, int x, int y, int grid[9][9]);
    void PositiveMa(int n, int x, int y, int grid[9][9]);
    void PositiveVua(int n, int x, int y, int grid[9][9]);
    void PositiveTot(int n, int x, int y, int grid[9][9]);

    void IncreasePositive(int i, int j); // tang so nuoc co the di
    void PositiveMoving(int n);          // tim cac nuoc co the di ung voi index n
    // AI
    int CostMove(); // gia tri diem cua toan bo ban co ung voi gia tri moi quan
    // int Minimax(int depth,bool luot);// Chien luoc Minimax
    int Alpha_Beta(int depth, bool luot, int alpha, int beta); // cat tia alpha beta
    Vector2f getNextMove(bool luot);                           // tra ve nuoc di tot nhat theo chien luoc phia tren
};