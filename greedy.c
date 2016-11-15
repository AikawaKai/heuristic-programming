#include "greedy.h"

int distance(solution_t *px, point_pos q, data_t *pI)
{
  int dist = 0;
  point_pos p;
  int pos_q = get_point(q,px);
  for (p = first_point_in(px); !end_point_list(p,px); p = next_point(p,px))
  {
    dist+= pI->d[pos_q][get_point(p, px)];
  }
  return dist;
}

int best_additional_point(solution_t *px, data_t *pI)
{
  int best_dist = -1;
  int best_point = 0;
  int d = 0;
  for (point_pos q = first_point_out(px); !end_point_list(q,px); q = next_point(q,px))
  {
    d = distance(px, q, pI);
    if (d>best_dist)
    {
      best_point = q;
      best_dist = d;
    }
  }
  return get_point(best_point, px);
}

void greedy (data_t *pI, solution_t *px)
{
  int i;
  while (px->card_x < pI->k)
  {
    i = best_additional_point(px,pI);
    move_point_in(i,px,pI);
  }
}
