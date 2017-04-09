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
	/*
	* A Funcao cria um grafo do tipo 'node' alocado dinamicamente e
	* o retorna para o usuario
	* Ela recebe um char para dar nome ao node do grafo para identificar este
	* node e impedir a criacao de dois nodes iguais e possibilitar a pesquisa
	* no grafo mais facil
	*/
	static struct node *cria_grafo(char *);

	// retorna o nome do grafo G
	// retorna_nome_grafo(G);
	/*
	* A retorna o nome do primeiro node do grafo (char *), sendo este o nome
	* do grafo. como o grafo e composto de uma lista de 'node's entao seu
	* nome acaba sendo o nome do primeiro node
	*/
	static char *retorna_nome_grafo(node *);

	// destrói grafo g
	// destroi_grafo(G);
	/*
	* a funcao desaloca o grafo completamente e
	* retorna um ponteiro NULL do tipo 'node
	*/
	static struct node *destroi_grafo(node *);

	// // verifica se x e y sao adjacentes em G
	// adjacente(G, x, y);
	/*
	* a funcao pesquisa nos dois nodes passados e retorna uma boolean conforme
	* um dos dois node possui ligacoes com o outro
	*/
	static bool adjacente(node *, char *, char *);

	// // retorna lista de todos os vértices que podem ser visitados
	// // a partir de x (existe uma aresta que vai de x para este
	// // vértice)
	// vizinhos(G, x);
	/*
	* a funcao retorna uma lista do tipo 'link' que sao todas as ligacoes do
	* node requisitado
	*/
	static struct link *vizinhos(node *, char *);

	// // adiciona vértice x no grafo G
	// adiciona_vertice(G, x);
	/*
	* a funcao adiciona um vertice no grafo
	*/
	static void adiciona_vertice(node *, char *);

	// // remove vértice x do grafo G
	// remove_vertice(G, x);
	/*
	* a funcao remove um vertice do grafo. caso hajam ligacoes, estas sao
	* removidas tambem
	*/
	static void remove_vertice(node *, char *);

	// // no grafo G adiciona uma aresta de x para y
	// adiciona_aresta(G, x, y);
	/*
	* a funcao adiciona uma ligacao entre dois vertices
	*/
	static void adiciona_aresta(node *, char *, char *);

	// // remove a aresta que vai de x para y
	// remove_aresta(G, x, y);
	/*
	* a funcao remove a ligacao entre dois vertices
	*/
	static void remove_aresta(node *, char *, char *);

	// // retorna o valor associado com o vértice x
	// retorna_valor_vertice(G, x);
	/*
	* a funcao retorna o valor armazenado em um vertice, neste caso um int
	*/
	static int retorna_valor_vertice(node *, char *);

	// // coloca valor v no vértice x em G
	// muda_valor_vertice(G, x, v);
	/*
	* a funcao altera o valor armazenado no vertice
	*/
	static void muda_valor_vertice(node *, char *, int);

	// // retorna valor da aresta x,y em G
	// retorna_valor_aresta(G, x, y);
	/*
	* a funcao retorna o valor armazenado em uma ligacao
	*/
	static int retorna_valor_aresta(node *, char *, char *);

	// // coloca o valor v na aresta x,y em G
	// muda_valor_aresta(G, x, y, v);
	/*
	* a funcao altera o valor armazenado em uma ligacao
	*/
	static void muda_valor_aresta(node *, char *, char *, int);
};