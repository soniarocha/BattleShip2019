#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_SHIPS 5

 typedef struct{
  int[][] m;
  int size;
}BattleField;

typedef struct{
	int symbol; // 0->mar ou 1->navio ou -1->territorio inimigo
  int row;
	int column;
}Cell;

typedef struct{
  int status=1; //0->morto ou 1->vivo;
  int size;
  int x1,x2;
  int y1,y2;
  ShipType x;
}Ship;

typedef struct{
  int x;
  int y;
}Shot;

typedef struct{
	int carrier = 5;
	int battleship = 4;
	int cruiser = 3;
	int submarine  = 3;
	int destroyer = 2;
}ShipType;


Ship* makeship(){
  Ship.status=1;
  Ship.x1
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertShipManual(int m [l][c] ,Ship s, int nShip){
  int linhas, colunas;
  printf("Qual o número de linhas do tabuleiro?\n");
  scanf("%d",&linhas);
  printf("Qual o número de colunas do tabuleiro?\n");
  scanf("%d",&colunas);
  makeboard(linhas,colunas);
  printboard(linhas,colunas);

  makeship(); //introduzir navio manualmente (manual selection)
  if(s.x1==s.x2)
//printf("Qual o navio que colocar? ", );
//scanf("%s\n");
}

//rand() % 1 + 0
/////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertShipRandom(int[][] m,Ship s){//introduzir navio randomly(randomize setup)
  int linhas,colunas;
  printf("Qual o número de linhas do tabuleiro?\n");
  scanf("%d",&linhas);
  printf("Qual o número de colunas do tabuleiro?\n");
  scanf("%d",&colunas);
  makeboard(linhas,colunas);
  printboard(linhas,colunas);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void giveShot(int shot[2]){
  printf("Line: ");
  scanf("%d",&shot[0]);
  shot[0]--;
  printf("Column: ");
  scanf("%d",&shot[1]);
  shot[1]--;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

int hitship(int shot[2], int ships[][2]){
  int ship;
  for(ship=0 ; ship < 5 ; ship++){
    if( shot[0]==ships[ship][0] && shot[1]==ships[ship][1]){
      printf("You hit a ship with the shot (%d,%d)\n",shot[0]+1,shot[1]+1);
      return 1;
    }
  }
  return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void makeboard(int linhas,int colunas){
  for(int i=0; i<linhas ; i++ )
    for(int j=0 ; j<colunas ; j++ )
      cell[i][j]=0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void printboard(int linhas,int colunas){
  for(int i=1;i<=linhas;i++){
    printf("%d\n",i);
  }
  for(int i=1;i<=colunas;i++){
    printf("%d ",i );
  }
  printf("%d",i+1);
  for(column=0 ; column < 5 ; column++ ){
    if(cell.status=-1){
      printf("\t~");
    }
    else if(cell.status==0){
      printf("\t*");
    }
    else if(cell.status==1){
      printf("\tX");
    }

  }
  printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
  int linhas,colunas;
  char modojogo[10],playagain[4];
  printf ("\n\n\n\n");
  printf ("SSSSS   SSSS  SSSSSS SSSSSS SS     SSSSSS  SSSSS SS  SS SS SSSS\n");
	printf ("SS  SS SS  SS   SS     SS   SS     SS     SS     SS  SS SS SS  SS\n");
	printf ("SSSSS  SS  SS   SS     SS   SS     SSSS    SSSS  SSSSSS SS SSSS\n");
	printf ("SS  SS SSSSSS   SS     SS   SS     SS         SS SS  SS SS SS\n");
	printf ("SSSSS  SS  SS   SS     SS   SSSSSS SSSSSS SSSSS  SS  SS SS SS\n");
  printf ("\n\n\n\n");



  printf("Qual o número de linhas do tabuleiro?\n");
  scanf("%d",&linhas);

  printf("Qual o número de colunas do tabuleiro?\n");
  scanf("%d",&colunas);

  printf("Qual a forma do jogo? Random ou Manual?\n");
  scanf("%s",modojogo);

  //makeboard(linhas,colunas);
  //printboard(linhas,colunas);
  while( strcmp(modojogo,"Random")!=0&& strcmp(modojogo,"random")!=0 && strcmp(modojogo,"Manual")!=0 && strcmp(modojogo,"manual")!=0){
    printf("Modo de jogo inexistente.\nTente novamente.\nAs opcões existentes são Random e Manual.\n ");
    scanf("%s",modojogo);
  }
  if(strcmp(modojogo,"Random")==0 || strcmp(modojogo,"random")==0){
    InsertShipRandom();
  }
  else if(strcmp(modojogo,"Manual")==0 || strcmp(modojogo,"manual")==0){
    InsertShipManual();
  }
  jogo();
  printf("You want to play again? Yes or no?");
  scanf("%s",playagain);
  if(strcmp(playagain,"Yes")==0 || strcmp(playagain,"yes")==0){
    jogo();
  }
  return 0;
}

void jogo(){
  int mortes=0;
  do{
    giveShot(shot);
    if(hitship(shot,ships)){
      //retirar "vida" ao navio acertado

  }
  while(mortes!=5)
  printf("               CONGRATULATIONS!\nYou sink all the ships and the win is yours\n\n\n\n\n\n\n");
}


}
