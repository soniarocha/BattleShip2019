/*VERSAO DESATUALIZADA*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N_SHIPS 5
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

void ships(){
for(int i=0;i<size_ca;i++){
  global.carrier[i].symbol_s += 'c';
  global.tboat[i].symbol_s += 't';
  }
for(int i=0;i<size_ba;i++){
  global.battleship[i].symbol_s += 'b';
  }
for(int i=0;i<size_cr;i++){
  global.cruiser[i].symbol_s += 'u';
  global.submarine[i].symbol_s += 's';
  }
for(int i=0;i<size_de;i++){
  global.destroyer[i].symbol_s += 'd';
  }
}
//rand() % 1 + 0
/*void MakeRandomBoard(Board b,ShipType* st,Symbol s){
  int h=1,v=0; //horizontal, vertical;
  int direction = rand() % 1 + 0;
  /*for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      b[]
    }
  }*/
int valid(Piece board[][10],int length,int x1,int y1,int x2,int y2){
  //valid se for 0- false, 1-verdadeiro;
  printf("%d ------ \n", size_ca);
  if(y2 > SIZE || y2 < 0 || x2 > SIZE || x2 < 0 || y1 > SIZE || y1 < 0 || x1 > SIZE || x1 < 0){
    printf("whatf\n");
    return 0;
  }

  if(abs(y2-y1)+1 != length && abs(x2-x1)+1 != length) return 0;

  if(x1 != x2 && y1 != y2 ){ //diagonal
    return 0;
  }

  for(int i=0;i<length;i++){
    if(x1 == x2){ //horizontal
      if (board[x1][y1+i].symbol != '-'){
        printf("entrei? %c \n",board[x1][y1+i].symbol);
				return 0;
        //printf("entrei?\n");
      }
    }
    else if(y1==y2){ //vertical
      if (board[x1+i][y1].symbol != '-'){
        return 0;
        //printf("entrei?MEMEME\n");
      }
    }
  }
  //printf("%d----------\n",valid);
  return 1;
}

void PrintBoard(Piece board[][10]){
  char inside[11] = {' ', '0' , '1', '2','3', '4', '5', '6', '7', '8', '9'};
  int k=1;

  for(int i=0;i<11;i++){
    printf("%c ",inside[i]);
  }
  printf("\n");
  for(int i=0;i<10;i++){
    printf("%c ",inside[k]);
    for(int j=0;j<10;j++){
          printf("%c ",board[i][j].symbol);
    }
    k++;
    printf("\n");
  }
}

void insertShip(Piece board[][10],char type,int x1,int y1,int x2,int y2){
  int tmp;

  if(x1 > x2){
    tmp = x2;
    x2  = x1;
    x1  = tmp;
  }

  if(y1 > y2){
    tmp = y2;
    y2  = y1;
    y1  = tmp;
  }
  switch (type) {
    case 'c':{
      for (int i = x1 ; i <=x2 ; i++){
          for (int j = y1 ; j <= y2 ; j++){
            board[i][j].symbol= 'c';
            board[i][j].ship.x= i;
            board[i][j].ship.y= j;
          }
        }
        break;}
    //case 't':{printf("EU sou AUWHH fixe\n");break;}
    case 'b':{
        for (int i = x1 ; i <=x2 ; i++){
            for (int j = y1 ; j <= y2 ; j++){
              board[i][j].symbol= 'b';
              board[i][j].ship.x= i;
              board[i][j].ship.y= j;
            }
          }
          break;}

    case 'u':{
      for (int i = x1 ; i <=x2 ; i++){
          for (int j = y1 ; j <= y2 ; j++){
            board[i][j].symbol= 'u';
            board[i][j].ship.x= i;
            board[i][j].ship.y= j;
          }
        }
        break;}

    case 's':{
      for (int i = x1 ; i <=x2 ; i++){
          for (int j = y1 ; j <= y2 ; j++){
            board[i][j].symbol= 's';
            board[i][j].ship.x= i;
            board[i][j].ship.y= j;
          }
        }
        break;}

    case 'd':{
      for (int i = x1 ; i <=x2 ; i++){
          for (int j = y1 ; j <= y2 ; j++){
            board[i][j].symbol= 'd';
            board[i][j].ship.x= i;
            board[i][j].ship.y= j;
          }
        }

        break;}
  }
    PrintBoard(board);
}

void questionario(Piece board[][10]){
  int x1,x2,y1,y2,validar=-1;
  int direction=-1; // se for 0 - vertical, se for 1 -horizontal
  printf("Vamos as coordenadas do navio carrier (size 5)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_ca,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.carrier[0].symbol_s,x1,y1,x2,y2);

  /*printf("Vamos as coordenadas do navio tboat (size 5)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_ca,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.carrier[0].symbol_s,x1,y1,x2,y2);
  */
  printf("Vamos as coordenadas do navio battleship (size 4)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_ba,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.battleship[0].symbol_s,x1,y1,x2,y2);

  printf("Vamos as coordenadas do navio cruiser (size 3)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_cr,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.cruiser[0].symbol_s,x1,y1,x2,y2);

  printf("Vamos as coordenadas do navio submarine (size 3)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_su,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.submarine[0].symbol_s,x1,y1,x2,y2);

  printf("Vamos as coordenadas do navio destroyer (size 2)\n");
  printf("x inicial: ");scanf("%d",&x1);
  printf("y inicial: ");scanf("%d",&y1);
  printf("x final: ");scanf("%d",&x2);
  printf("y final: ");scanf("%d",&y2);
  validar = valid(board,size_de,x1,y1,x2,y2);
  if(validar == 0){
    printf("Coordenadas inválidas! Tente novamente!\n");
    questionario(board);
  }
  insertShip(board,global.destroyer[0].symbol_s,x1,y1,x2,y2);

}

void MakeManualBoard(Piece board_1[][10],Piece board_2[][10],int turn){
  if(turn==1){
    printf("Algumas questões para o jogador 1 : \n");
    questionario(board_1);}
  //turn=2;
  //printf("Algumas questões para o jogador 2: \n");
  //questionario(board_2);
}

void chooseMode(int escolha,Piece board_1[][10],Piece board_2[][10],int turn){
  scanf("%d",&escolha);
  if(escolha == 0){
    PrintBoard(board_1);
    MakeManualBoard(board_1,board_2,turn);
  }
  else if(escolha == 1){
    //MakeRandomBoard(board);
  }
  else{
    printf("Escolha inválida!\n");
    //chooseMode(escolha);
  }
}

int main(){
  Piece board_1[10][10];
  Piece board_2[10][10];
  int turn=1;
  ShipType s;
  ships();
  for (int i = 0 ; i <= 10 ; i++){
      for (int j = 0 ; j <= 10 ; j++){
        board_1[i][j].symbol= '-';
        board_1[i][j].ship.x= i;
        board_1[i][j].ship.y= j;
      }
  }

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      board_2[i][j]=board_1[i][j];
    }
  }

  int escolha=-1;
  printf("Vamos começar por escolher o modo de jogo!\nEscolher manualmente a posição dos navios (0) ou random (1) ?\n");
  chooseMode(escolha,board_1,board_2,turn);

  //PrintBoard(board_1);
  //printf("\n");
  //PrintBoard(board_2);
  //MakeRandomBoard(board);
}
