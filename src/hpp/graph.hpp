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
	static node *createGraph(char *);

	// retorna o nome do grafo G
	// retorna_nome_grafo(G);
	static char *getName(node *);

	// destrói grafo g
	// destroi_grafo(G);
	static void freeGraph(node *);

	// // verifica se x e y sao adjacentes em G
	// adjacente(G, x, y);
	static bool isAdjacent(node *, char *, char *);

	// // retorna lista de todos os vértices que podem ser visitados
	// // a partir de x (existe uma aresta que vai de x para este
	// // vértice)
	// vizinhos(G, x);
	static std::string getNear(node *, char *);

	// // adiciona vértice x no grafo G
	// adiciona_vertice(G, x);
	static void addVertice(node *, char *);

	// // remove vértice x do grafo G
	// remove_vertice(G, x);
	static void delVertice(node *, char *);

	// // no grafo G adiciona uma aresta de x para y
	// adiciona_aresta(G, x, y);
	static void addLink(node *, char *, char *);

	// // remove a aresta que vai de x para y
	// remove_aresta(G, x, y);
	static void delLink(node *, char *, char *);

	// // retorna o valor associado com o vértice x
	// retorna_valor_vertice(G, x);
	static int getNodeValue(node *, char *);

	// // coloca valor v no vértice x em G
	// muda_valor_vertice(G, x, v);
	static void setNodeValue(node *, char *, int);

	// // retorna valor da aresta x,y em G
	// retorna_valor_aresta(G, x, y);
	static int getLinkValue(node *, char *, char *);

	// // coloca o valor v na aresta x,y em G
	// muda_valor_aresta(G, x, y, v);
	static void setLinkValue(node *, char *, char *, int);
};