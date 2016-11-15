#ifndef __SOLUTION_H
#define __SOLUTION_H


#include "data.h"

#define NO_POINT -1

typedef struct solution_s
{
  int f;     // valore della soluzione

  int card_x;
  int card_N;

  bool *in_x; // per ogni punto i indica se esso appartiene o no alla soluzione x

  // Liste dei punti nella soluzione x e nel complemento N \setminus x
  int head_x;    // sentinella della lista dei punti in x
  int head_notx; // sentinella della lista dei punti del complemento N \setminus x
  int *next;     // elemento seguente   per ciascun punto
  int *prev;     // elemento precedente per ciascun punto

} solution_t;


// Crea una soluzione vuota per un problema di dimensione n
void create_solution (int n, solution_t *px);

// Dealloca una soluzione *px
void destroy_solution (solution_t *px);

// Tipi e strutture per accedere ai punti

typedef int point_pos;

// Legge l'indice del punto indicato dal cursore p nella soluzione *px
int get_point (point_pos p, solution_t *px);

// Determina il cursore a un dato punto i
point_pos get_point_pos (int i, solution_t *px);

// Legge il valore della funzione obiettivo per la soluzione *px
int get_obj (solution_t *px);

// Indica se si e' arrivati in fondo alla lista (la posizione p e' una sentinella)
bool end_point_list (point_pos p, solution_t *px);

// Indica se la soluzione *px e' vuota
bool empty_solution (solution_t *px);

// Restituiscono i cursori al primo e all'ultimo punto della soluzione *px
point_pos first_point_in (solution_t *px);
point_pos last_point_in (solution_t *px);

// Restituiscono i cursori al primo e all'ultimo punto fuori della soluzione *px
point_pos first_point_out (solution_t *px);
point_pos last_point_out (solution_t *px);

// Restituiscono i cursori al punto che segue e a quello che precede il punto individuato dal cursore p
point_pos next_point (point_pos p, solution_t *px);
point_pos prev_point (point_pos p, solution_t *px);

// Aggiunge il punto i alla soluzione *px
void move_point_in (point_pos i, solution_t *px, data_t *pI);

// Cancella il punto i dalla soluzione *px
void move_point_out (point_pos i, solution_t *px, data_t *pI);

// Calcola il costo di una soluzione *px in base ai punti che la compongono e ai dati dell'istanza *pI
void compute_obj (solution_t *px, data_t *pI);

// Copia la soluzione x_orig nella soluzione x_dest
void copy_solution (solution_t *x_orig, solution_t *x_dest);

// Verifica la coerenza interna della soluzione *px in base ai dati dell'istanza *pI,
// partendo dal vettore di incidenza
bool check_solution (solution_t *px, data_t *pI);

// Copia in un vettore di interi gli elementi che appartengono alla soluzione
//void dump_soluzione(lista_nodi_t *lista_nodi, soluzione_t * soluzione_dest);

// Recupera in lista_nodi la soluzione salvata in soluzione
//void retrieve_soluzione(matrice_distanze_t *matrice_distanze, soluzione_t *soluzione, lista_nodi_t *lista_nodi);

// Stampa la soluzione x
void print_solution (solution_t *x);

#endif /* __SOLUTION_H */
