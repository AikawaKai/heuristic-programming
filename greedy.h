#ifndef __GREEDY_H
#define __GREEDY_H


#include "data.h"
#include "solution.h"

// Esegue l'euristica greedy standard sull'istanza *pI e ottiene la soluzione *px
void greedy(data_t *pI, solution_t *px);
int best_additional_point(solution_t *px,data_t *pI);
int distance(solution_t *px, point_pos q, data_t *pI);

#endif /* __GREEDY_H */
