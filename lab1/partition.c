#include "partition.h"

// Riordina un vettore V_val di n int in modo che i primi k siano non superiori agli ultimi n-k,
// mantenendo allineati agli elementi di V_val quelli del vettore V_ind di interi
// Pora faccio l'implementazione banale che porta in cima l'elemento minimo per k volte
void partition (int n, int *V_val, int *V_ind, int k)
{
  int i, j, temp;
  point_pos p;

  for (i = 1; i <= k; i++)
    for (j = i+1; j <= n; j++)
      if (V_val[j] < V_val[i])
      {
        temp = V_val[j];
        p = V_ind[j];
        V_val[j] = V_val[i];
        V_ind[j] = V_ind[i];
        V_val[i] = temp;
        V_val[j] = p;
      }
}
