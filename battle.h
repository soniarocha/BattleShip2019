#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Board{
    char Board[SIZE][SIZE];
}Board;

typedef struct Ship{
    int x,y;
    char symbol_s;
} Ship;

typedef struct ShipType{
  Ship carrier[5];
  Ship tboat[5];
	Ship battleship[4];
	Ship cruiser[3];
	Ship submarine[3];
	Ship destroyer[2];
}ShipType;

typedef struct Piece{
    char symbol;
    Ship ship;
}Piece;

ShipType global;
int size_ca = sizeof(global.carrier) / sizeof(global.carrier[0]);
int size_tb = sizeof(global.tboat) / sizeof(global.tboat[0]);
int size_ba = sizeof(global.battleship) / sizeof(global.battleship[0]);
int size_cr = sizeof(global.cruiser) / sizeof(global.cruiser[0]);
int size_su = sizeof(global.submarine) / sizeof(global.submarine[0]);
int size_de = sizeof(global.destroyer) / sizeof(global.destroyer[0]);

void ships();
int valid(Piece board[][SIZE],int length,int x1,int y1,int x2,int y2);
void PrintBoard(Piece board[][SIZE]);
void insertShip(Piece board[][SIZE],char type,int x1,int y1,int x2,int y2);
void questionario(Piece board[][SIZE]);
void MakeManualBoard(Piece board_1[][SIZE],Piece board_2[][SIZE],int turn);
void chooseMode(int escolha,Piece board_1[][SIZE],Piece board_2[][SIZE],int turn);
