#include <stdio.h>

/* TODO tudo */
/* FIXME tudo */
/* XXX tudo */

int main(int argc, char const *argv[]) {
  int *N,*F,*C,**Fi,***Ci; /* N - Localidades ; F - Filiais ; C - Num Ligacoes ; Fi - Ligacoes em si ; Ci - Nao sei */
  size_t i,j; /*Counters*/

  scanf("%d %d %d\n",N,F,C);

  for (i = 0; i < F; i++) { /*Obtem Ligacoes*/
    scanf("%d",Fi[i]);
    getchar(); /*For de getchars*/
  }

  neo_G = Single_Source(G); /* Funcao de criacao de single-source; G e' a representacao do grafo */

  Bellman_Ford(neo_G,w,s); /* Aplica Bellman_Ford no grafo */

  for (l = 0; l < N; l++) { /*Aplica Deijkstra em cada vertice (Localidade)*/

    d = Deijkstra(G,w2,l); /*Provavelmente mal soletrado (soletrado tambem provavelmente mal soletrado)*/
    d[l] = d[l] + h[v] - h[u]; /* Supostamente faz update da distancia que e dada pelo Bellman_Ford*/

  }

  loc = get_local(); /* Encontra a localidade do P.d.Encontro e o custo total */
  printf("%d %d\n", loc[0],loc[1]);

  for (i = 0; i < F; i++) { /* Imprime o custo das Filiais ao P.d.Encontro */
    printf("%d ", d[i][loc]);
  }
  printf("\n");

  return 0; /*Retorna 0*/
}


int Bellman_Ford(G,w,s) {
  int *d,*pi; /* d - distancia de s(ource) a um ponto ; pi - fulano que e' o pai desse ponto */
  struct node* i; /* assume lista ligada, e vai conter as ligacoes do vertice */

  for (i = 0; i < N; i++) { /* Inicializa a distancia e o pai de todos os vertices*/
    d[i] = NULL;
    pi[i] = NULL;
  }

  d[s] = 0; /* A source e' metida a distancia 0 */

  for (j = 1; j < N - 1; j++) { /* Percorre todos os vertices */

    for (k = j -> next; k != NULL; k = k -> next;) { /* Percorre as adjacencias desse vertice */

      if (d[j] + w < d[k]) {d[k] = d[j] + w; pi[k] = j;} /* Relaxa se for caso para tal */

    }
  }

  for (i = 0; i < N; i++) { /* Se um dos vertices e' inacessivel retorna 0*/
    if (d[i] = NULL) return 0;
  }

  return 1; /* Retorna 1 caso contrario */
}

int Deijkstra(G,w2,u) {

  int *di,*pii,*Q; /* di - distancia de um ponto 'a source ; pii - pai desse ponto ; Q - fila onde estao os vertices nao explorados */

  for (i = 0; i < N; i++) { /* Inicializacao */
    di[i] = NULL;
    pii[i] = NULL;
  }

  di[s] = 0;


  while (Q != NULL) { /* Enquanto houver elementos na fila */
    u = Q[0];
    rem(Q[0]); /* funcao que remove o primeiro elemento da fila */

    for (j = 0; j < N; j++) {

      if (G[j] != in_queue[j]) /* Se a adjacencia nao esta na queue (ja terminou) passa 'a iteracao seguinte  */
        continue;              /* in_queue pode ser um array que contem o estado de presenca de um ponto na queue */


      else {
        dist = di[u] + w[u][j];
        if (dist < di[v]) {di[v] = dist;pii[v] = u; /* faz update da distancia se for caso para tal */
      }

    }
  }

  return di; /* retorna as distancias ou coisa assim*/
}
