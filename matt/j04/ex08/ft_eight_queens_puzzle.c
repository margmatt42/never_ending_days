#include <stdio.h>

#define NB_QUEENS 8
#define CHESS_BOARD_SIZE 8

typedef enum
{
        FALSE,
        TRUE
}       t_bool;

int ft_is_checkmate(int *queens_pos)
{
  int i;
  int j;
  int diagonal_left;
  int diagonal_right;

  i = NB_QUEENS - 1;
  while(i > 0)
  {
    j = i - 1;
    while (j >= 0)
    {
      //Same line ?
      /*if (queens_pos[i] - queens_pos[j] < CHESS_BOARD_SIZE)
        return TRUE;*/
      //Same column ?
      if ((queens_pos[i] - queens_pos[j]) % CHESS_BOARD_SIZE == 0)
      {
        printf("Meme colonne ! (%d %d)\n", i , j);
        return 1;
      }
      //Same diagonal ?
      /* Il y a une erreur ici. diagonal_left peut valoir 0 si une reine est
      présente sur la diagonale droite... Ce qui oblige à faire des tests
      supplémentaires, et ralentit donc encore plus l'exécution...
      */
      diagonal_left = (queens_pos[i] - queens_pos[j]) % 9;
      diagonal_right = (queens_pos[i] - queens_pos[j]) % 7;
      if (diagonal_left == 0 || diagonal_right == 0)
      {
        printf("Meme diagonale !(%d:%d %d:%d)\n", i , queens_pos[i], j, queens_pos[j]);
        return 1;
      }
      j--;
    }
    i--;
  }
  return 0;
}

void print_queens_pos(int *queens_pos)
{
  int i;

  i = 0;
  while (i < 8)
  {
    printf("%d ", queens_pos[i]);
    i++;
  }
  printf("\n");

}

int ft_eight_queens_count(int *queens_pos, int queen)
{
  int res;
  int j;

  //print_queens_pos(queens_pos);
  res = 0;
  j = 0;
  while (j < CHESS_BOARD_SIZE)
  {
    if (queen < CHESS_BOARD_SIZE)
      res += ft_eight_queens_count(queens_pos, queen + 1);
    if (!ft_is_checkmate(queens_pos))
    {

      res++;
    }
    queens_pos[queen]++;
    ++j;
  }
  queens_pos[queen] -= CHESS_BOARD_SIZE;
  return (res);
}

int ft_eight_queens_puzzle(void)
{
  int queens_pos[NB_QUEENS];
  int i;

  i = 0;
  while (i < NB_QUEENS)
  {
    queens_pos[i] = i * 8;
    i++;
  }
  return (ft_eight_queens_count(queens_pos, 0));
  //return (5);
}
