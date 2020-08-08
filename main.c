/**
 * 
 * Count the island in a matrix in C
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define XDIM  10
#define YDIM  10

struct coord{
  int x;
  int y;
};

struct node
{
  unsigned int data;
  bool processed;
};

static void bfs(unsigned int xCoord, unsigned int yCoord, struct node  matrix[xCoord][yCoord]);
static void printMatrix(size_t xs, size_t ys, struct node matrix[xs][ys]);
static void printMatrix(size_t xs, size_t ys, struct node matrix[xs][ys]);
static void printMatrixMap(size_t xs, size_t ys, struct node matrix[xs][ys]);




static void printMatrix(size_t xs, size_t ys, struct node matrix[xs][ys])
{
  if (matrix == NULL) return;

  printf("Current matrix:\n" );
  for (int i = 0; i < xs; i++)
  {
    for (int j = 0; j < ys; j++)
    { 
      printf("%d,", matrix[i][j].data);
    }
    printf("\n" );
  }
  printf("\n" );
}

static void printMatrixMap(size_t xs, size_t ys, struct node matrix[xs][ys])
{
  if (matrix == NULL) return;

  printf("\nMatrix map:\n" );
  for (int i = 0; i < xs; i++)
  {
    for (int j = 0; j < ys; j++)
    { 
      printf("[%d][%d],", i,j);
    }
    printf("\n" );
  }
  printf("\n" );
}

static void initMatrix(size_t xs, size_t ys, struct node matrix[xs][ys])
{
  if (matrix == NULL) return;

  printf("\ninitMatrix.\n" );

  for (int i = 0; i < xs; i++)
  {
    for (int j = 0; j < ys; j++)
    { 
      matrix[i][j].data = 0;
      printf("%d,", matrix[i][j].data);
    }
    printf("\n" );
  }
}

static void bfs(unsigned int ax, unsigned int ay, struct node matrix[ax][ay])
{
  struct coord mov[8];
  int counter = 0;

  /* init all possible movement around a coordinate */
  mov[0].x = -1;
  mov[0].y = -1;

  mov[1].x = 0;
  mov[1].y = -1;

  mov[2].x = +1;
  mov[2].y = -1;

  mov[3].x = +1;
  mov[3].y = 0;

  mov[4].x = +1;
  mov[4].y = +1;

  mov[5].x = 0;
  mov[5].y = +1;

  mov[6].x = -1;
  mov[6].y = +1;

  mov[7].x = 0;
  mov[7].y = +1;

  for(int i=0; i<8; i++)
  {
      int x,y;
      x = ax + mov[i].x;
      y = ay + mov[i].y;
      printf("1. processed y/n: %d\n",matrix[x][y].processed);
      printf("2. x/y [%d][%d]\n",x,y);


      // check if already processed + inbound.
      if( (matrix[x][y].processed == false) && (x < XDIM) && (y < YDIM) && (x >= 0) && (y >= 0) )
      {
        if(matrix[x][y].data == 1 ) 
        {
          matrix[x][y].processed = true;
          printf("Recursive call \n");
          bfs(x,y, matrix);
        }
        printf("3. x/y [%d][%d] processed \n",x,y);
        counter++;
      }
      else
      {
        printf("4. x/y [%d][%d] not processed \n",x,y);
      }
  }

  printf("processed: %d \n",counter);
  return;
}

int main ()
{
  unsigned int islands = 0;
  struct node  matrix [XDIM][YDIM];
  /* sizeof returns # of bytes so divided dy sizeof (int) */
  unsigned int sizeOfmatrix = sizeof(matrix)/4;
  
  initMatrix(XDIM, YDIM, matrix);
  printMatrix(XDIM, YDIM, matrix);


  matrix[5][5].data = 1;
  matrix[0][0].data = 1;
  matrix[0][1].data = 1;
  matrix[0][2].data = 1;
  // matrix[0][3].data = 1;
  // matrix[0][4].data = 1;
  matrix[1][0].data = 1;
  // matrix[7][3].data = 1;
  // matrix[5][4].data = 1;
  // matrix[2][9].data = 1;
  // matrix[3][8].data = 1;

  printMatrix(XDIM, YDIM, matrix);

  for (int i=0; i<XDIM; i++)
  {
    for(int j=0; j<YDIM; j++)
    {
      // check if already processed, inbound and is set.
      if( (matrix[i][j].processed == false) && (i < XDIM) && (j<YDIM) && matrix[i][j].data == 1)
      {
        printf("\nSearching around [%d][%d]\n", i,j);
        // breadth first search
        bfs(i,j, matrix);
        printf("adding one island at [%d][%d] \n", i, j);
        islands++;

      }
      else
      {
        //matrix[i][j] = 3;
      } 
    }
  }

  printMatrixMap(XDIM, YDIM, matrix);
  printMatrix(XDIM, YDIM, matrix);

  printf("\nNumber of islands: %d\n----------------\n", islands);

}
