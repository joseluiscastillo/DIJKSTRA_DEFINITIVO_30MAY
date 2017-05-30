//ALGORITMO DE DIJKSTRA
#include <stdio.h>
#include <limits.h>
// DEFINIMOS EL NUMERO DE VERTICES DEL GRAFO
#define V 9
//PARA HALLAR EL VERTICE CON EL VALOR MINIMO DE DISTANCIA DESDE
//EL AJUSTE DE VERTICES TODAVIA NO INCLUIDOS EN EL ARBOL DEL CAMINO MAS CORTO USAMOS
int minimaDistancia(int distancia[], bool caminocorto[])
{
   // INICIALIZAMOS EN EL VALOR MINIMO
   int min = INT_MAX, indicemin;
   for (int v = 0; v < V; v++)
     if (caminocorto[v] == false && distancia[v] <= min)
         min = distancia[v], indicemin = v;
   return indicemin;
}
// UNA FUNCIÓN DE UTILIDAD PARA IMPRIMIR LA DISTANCIA DEL ARREGLO CONSTRUIDO
int printSolution(int distancia[], int n)
{
   printf("DISTANCIA DESDE EL VERTICE ESCOGIDO A CADA UNO DE LOS OTROS VERTICES\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, distancia[i]);
}
//ESTA ES LA FUNCIÓN QUE IMPLEMENTA EL ALGORITMO DE DIJKSTRA BUSCANDO EL CAMINO MAS CORTO
//PARA EL GRAFO PRESENTADO USANDO LA REPRESENTACIÓN DE LA MATRIZ DE ADYACENCIA
void dijkstra(int graph[V][V], int origen)
{
     int distancia[V]; // LA SALIDA DEL ARREGLO distancia[i] SERÁ LA DISTANCIA MAS CORTA DESDE LA FUENTE HASTA i
     bool caminocorto[V]; // caminocorto[i] SERÁ VERDADERO SI EL VERTICE i ES INCLUIDO EN EL ARBOL DEL CAMINO MAS CORTO
                     // O LA DISTANCIA MAS CORTA DESDE LA FUENTE HASTA i ES FINALIZADA
     // INICIAMOS TODAS LAS DICTANCIAS COMO INFINITAS Y caminocorto[] ES FALSO
     for (int i = 0; i < V; i++)
        distancia[i] = INT_MAX, caminocorto[i] = false;
      // DISTANCIA DESDE EL VERTICE FUENTE HASTA ÉL MISMO SIEMPRE ES 0
        distancia[origen] = 0;

      //HALLAMOS O ENCONTRAMOS EL CAMINO MAS CORTO DE TODOS LOS VERTICES
     for (int count = 0; count < V-1; count++)
     {
       //ESCOGEMOS LA DISTANCIA MINIMA DEL VERTOR DESDE EL AJUSTE DE LOS VERTICES NO PROCESADOS TODAVÍA
       //u SIEMPRE ES IGUAL A LA FUENTE EN LA PRIMERA ITERACIÓN
       int u = minimaDistancia(distancia, caminocorto);
       // MARCAMOS EL VERTICE ESCOGIDO COMO PROCESADO
       caminocorto[u] = true;
       //ACTUALIZO EL VALOR DE LA DISTANCIA DE LOS VERTICES ADYACENTES
       //DEL VERTICE ESCOGIDO
       for (int v = 0; v < V; v++)
         //ACTUALIZO distancia[v] SOLO SI NO ESTÁ EN caminocorto, HAY UN BORDE DESDE
         // u HASTA v, Y EL PESO TOTAL DEL CAMINO DESDE origen HASTA v A TRAVES DE u ES
         // TAN PEQUEÑO COMO EL ACTUAL VALOR DE distancia[v]
         if (!caminocorto[v] && graph[u][v] && distancia[u]!= INT_MAX
            && distancia[u]+graph[u][v] < distancia[v])
            distancia[v] = distancia[u] + graph[u][v];
     }
        // IMPRIMO LA CONSTRUCCIÓN DEL ARREGLO CONSTRUIDO
     printSolution(distancia, V);
}
        // PROGRAMA PRINCIPAL PARA PROBAR LA FUNCIÓN DESCRITA ARRIBA //
int main()
{
   // AHORA CREO EL GRAFO CON LAS DISTANCIAS DESDE LOS VERTICES A CADA UNO DE LOS OTROS
   int graph[V][V] = {{0, 8, 3, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 3, 0, 0, 0, 0},
                      {3, 6, 0, 1, 0, 3, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 9, 0, 0},
                      {0, 0, 0, 0, 0, 10, 0, 7, 0},
                      {0, 0, 3, 0, 0, 0, 4, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 2},
                      {0, 0, 0, 0, 0, 0, 1, 0, 2},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
