#include "../hpp/graph.hpp"
#include <iostream>

int main() {

	node *grafo = Graph::createGraph((char *)"um");

	std::cout << Graph::getName(grafo) << std::endl;

	Graph::addVertice(grafo, (char *)"dois");
	Graph::addVertice(grafo, (char *)"tres");

	try {
		Graph::addVertice(grafo, (char *)"um");
	} catch (const std::exception &e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}

	Graph::addVertice(grafo, (char *)"quatu");

	Graph::setNodeValue(grafo, (char *)"quatu", 22);
	std::cout << Graph::getNodeValue(grafo, (char *)"quatu") << std::endl;

	Graph::delVertice(grafo, (char *)"quatu");

	Graph::addLink(grafo, (char *)"um", (char *)"dois");
	Graph::addLink(grafo, (char *)"um", (char *)"tres");

	Graph::setLinkValue(grafo, (char *)"um", (char *)"tres", 12);
	std::cout << Graph::getLinkValue(grafo, (char *)"um", (char *)"tres")
			  << std::endl;

	std::cout << Graph::isAdjacent(grafo, "um", "tres") << std::endl;

	// Graph::delLink(grafo, (char *)"um", (char *)"tres");

	std::cout << Graph::isAdjacent(grafo, "um", "tres") << std::endl;

	std::cout << "vizinhos: " << Graph::getNear(grafo, "um") << std::endl;

	Graph::freeGraph(grafo);

	return 0;
}