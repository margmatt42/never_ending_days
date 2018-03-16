#include <stdio.h>
//#include "ft_eight_queens_puzzle.c"

/*typedef enum
{
        FALSE,
        TRUE
}       t_bool;
*/
int ft_eight_queens_puzzle(void);
int ft_is_checkmate(int *queens_pos);

int main(void)
{
  int queens_pos[] = {0, 12, 23, 29, 34, 46, 49, 59};
  printf("%d\n", (int)ft_is_checkmate(queens_pos));
  //printf("%d\n", ft_eight_queens_puzzle());
  return (0);
}
