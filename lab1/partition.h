#ifndef __PARTITION_H
#define __PARTITION_H


#include <stdio.h>
#include <stdlib.h>
#include "solution.h"


// Riordina un vettore V_val di n int in modo che i primi k siano non superiori agli ultimi n-k,
// mantenendo allineati agli elementi di V_val quelli del vettore V_ind di interi
void partition (int n, int *V_val, int *V_ind, int k);

#endif /* __PARTITION_H */
