#include "../hpp/graph.hpp"
#include <gtest/gtest.h>

#include <iostream>

TEST(Graph, cria_grafo) {

	node *grafo = Graph::cria_grafo((char *)"um");

	ASSERT_TRUE(grafo);

	Graph::destroi_grafo(grafo);
}

TEST(Graph, retorna_nome_grafo) {

	node *grafo = Graph::cria_grafo((char *)"um");

	ASSERT_STREQ((char *)"um", Graph::retorna_nome_grafo(grafo));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, destroi_grafo) {

	node *grafo = Graph::cria_grafo((char *)"um");

	grafo = Graph::destroi_grafo(grafo);

	ASSERT_EQ(NULL, grafo);
}

TEST(Graph, adjacente) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");
	Graph::adiciona_vertice(grafo, (char *)"tres");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");

	ASSERT_TRUE(Graph::adjacente(grafo, (char *)"um", (char *)"dois"));
	ASSERT_FALSE(Graph::adjacente(grafo, (char *)"um", (char *)"tres"));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, vizinhos) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");
	Graph::adiciona_vertice(grafo, (char *)"tres");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");
	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"tres");

	struct link *vizinhos = Graph::vizinhos(grafo, (char *)"um");

	ASSERT_STREQ((char *)"dois", vizinhos->to->name);
	ASSERT_STREQ((char *)"tres", vizinhos->next->to->name);

	Graph::destroi_grafo(grafo);
}

TEST(Graph, adiciona_vertice) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	ASSERT_STREQ((char *)"dois", grafo->next->name);

	ASSERT_ANY_THROW(Graph::adiciona_vertice(grafo, (char *)"dois"));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, remove_vertice) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	ASSERT_STREQ((char *)"dois", grafo->next->name);

	Graph::remove_vertice(grafo, (char *)"dois");

	ASSERT_EQ(NULL, grafo->next);

	Graph::destroi_grafo(grafo);
}

TEST(Graph, adiciona_aresta) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");

	struct link *vizinhos = Graph::vizinhos(grafo, (char *)"um");

	ASSERT_STREQ((char *)"dois", vizinhos->to->name);

	Graph::destroi_grafo(grafo);
}

TEST(Graph, remove_aresta) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");

	struct link *vizinhos = Graph::vizinhos(grafo, (char *)"um");

	ASSERT_STREQ((char *)"dois", vizinhos->to->name);

	Graph::remove_aresta(grafo, (char *)"um", (char *)"dois");

	vizinhos = Graph::vizinhos(grafo, (char *)"um");

	ASSERT_EQ(NULL, vizinhos->to);

	Graph::destroi_grafo(grafo);
}

TEST(Graph, retorna_valor_vertice) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::muda_valor_vertice(grafo, (char *)"um", 0);
	ASSERT_EQ(0, Graph::retorna_valor_vertice(grafo, (char *)"um"));

	Graph::muda_valor_vertice(grafo, (char *)"dois", 1);
	ASSERT_EQ(1, Graph::retorna_valor_vertice(grafo, (char *)"dois"));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, muda_valor_vertice) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::muda_valor_vertice(grafo, (char *)"um", 0);
	ASSERT_EQ(0, Graph::retorna_valor_vertice(grafo, (char *)"um"));

	Graph::muda_valor_vertice(grafo, (char *)"dois", 1);
	ASSERT_EQ(1, Graph::retorna_valor_vertice(grafo, (char *)"dois"));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, retorna_valor_aresta) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");

	Graph::muda_valor_aresta(grafo, (char *)"um", (char *)"dois", 0);
	ASSERT_EQ(0,
			  Graph::retorna_valor_aresta(grafo, (char *)"um", (char *)"dois"));

	Graph::destroi_grafo(grafo);
}

TEST(Graph, muda_valor_aresta) {

	node *grafo = Graph::cria_grafo((char *)"um");

	Graph::adiciona_vertice(grafo, (char *)"dois");

	Graph::adiciona_aresta(grafo, (char *)"um", (char *)"dois");

	Graph::muda_valor_aresta(grafo, (char *)"um", (char *)"dois", 0);
	ASSERT_EQ(0,
			  Graph::retorna_valor_aresta(grafo, (char *)"um", (char *)"dois"));

	Graph::muda_valor_aresta(grafo, (char *)"um", (char *)"dois", 1);
	ASSERT_EQ(1,
			  Graph::retorna_valor_aresta(grafo, (char *)"um", (char *)"dois"));

	Graph::destroi_grafo(grafo);
}