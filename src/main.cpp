#include "hpp/graph.hpp"
#include <iostream>

int main() {

	node *grafo = Graph::cria_grafo((char *)"um");

	std::cout << Graph::retorna_nome_grafo(grafo) << std::endl;

	Graph::adiciona_vertice(grafo, (char *)"dois");
	Graph::adiciona_vertice(grafo, (char *)"tres");

	try {
		Graph::adiciona_vertice(grafo, (char *)"um");
	} catch (const std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}

	Graph::adiciona_vertice(grafo, (char *)"quatu");

	Graph::muda_valor_vertice(grafo, (char *)"quatu", 22);
	std::cout << Graph::retorna_valor_vertice(grafo, (char *)"quatu")
			  << std::endl;

	Graph::remove_vertice(grafo, (char *)"quatu");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");
	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"tres");

	Graph::muda_valor_aresta(grafo, (char *)"um", (char *)"tres", 12);
	std::cout << Graph::retorna_valor_aresta(grafo, (char *)"um",
											 (char *)"tres")
			  << std::endl;

	std::cout << Graph::adjacente(grafo, (char *)"um", (char *)"tres")
			  << std::endl;

	Graph::remove_aresta(grafo, (char *)"um", (char *)"tres");

	std::cout << Graph::adjacente(grafo, (char *)"um", (char *)"tres")
			  << std::endl;

	std::cout << "vizinhos: ";

	for (struct link *vizinhos = Graph::vizinhos(grafo, (char *)"um");
		 vizinhos != NULL; vizinhos = vizinhos->next)
		if (vizinhos)
			std::cout << vizinhos->to->name << std::endl;

	grafo = Graph::destroi_grafo(grafo);

	return 0;
}