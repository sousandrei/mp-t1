#include <string>

struct link {
	struct node *to;
	int value;
	struct link *next, *prev;
};
struct node {
	char *name;
	int value;
	struct link *links;
	struct node *next, *prev;
};

class Graph {
  public:
	// retorna estrutura de dados grafo que tem um nome
	// cria_grafo(nome);
	static struct node *cria_grafo(char *);

	// retorna o nome do grafo G
	// retorna_nome_grafo(G);
	static char *retorna_nome_grafo(node *);

	// destrói grafo g
	// destroi_grafo(G);
	static struct node *destroi_grafo(node *);

	// // verifica se x e y sao adjacentes em G
	// adjacente(G, x, y);
	static bool adjacente(node *, char *, char *);

	// // retorna lista de todos os vértices que podem ser visitados
	// // a partir de x (existe uma aresta que vai de x para este
	// // vértice)
	// vizinhos(G, x);
	static struct link *vizinhos(node *, char *);

	// // adiciona vértice x no grafo G
	// adiciona_vertice(G, x);
	static void adiciona_vertice(node *, char *);

	// // remove vértice x do grafo G
	// remove_vertice(G, x);
	static void remove_vertice(node *, char *);

	// // no grafo G adiciona uma aresta de x para y
	// adiciona_aresta(G, x, y);
	static void adiciona_aresta(node *, char *, char *);

	// // remove a aresta que vai de x para y
	// remove_aresta(G, x, y);
	static void remove_aresta(node *, char *, char *);

	// // retorna o valor associado com o vértice x
	// retorna_valor_vertice(G, x);
	static int retorna_valor_vertice(node *, char *);

	// // coloca valor v no vértice x em G
	// muda_valor_vertice(G, x, v);
	static void muda_valor_vertice(node *, char *, int);

	// // retorna valor da aresta x,y em G
	// retorna_valor_aresta(G, x, y);
	static int retorna_valor_aresta(node *, char *, char *);

	// // coloca o valor v na aresta x,y em G
	// muda_valor_aresta(G, x, y, v);
	static void muda_valor_aresta(node *, char *, char *, int);
};