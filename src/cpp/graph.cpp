#include "../hpp/graph.hpp"
#include <iostream>
#include <stdexcept>

node *Graph::cria_grafo(char *name) {
	node *newG = (node *)malloc(sizeof(node));

	newG->name = name;
	newG->value = 0;
	newG->links = NULL;
	newG->next = NULL;
	newG->prev = NULL;

	return newG;
}

char *Graph::retorna_nome_grafo(node *graph) { return graph->name; }

void Graph::destroi_grafo(node *graph) {
	node *gAux;
	node *g = graph;

	while (g->next != NULL)
		g = g->next;

	while (g->prev != NULL) {
		gAux = g->prev;

		free(g);

		g = gAux;
	}

	free(graph);

	graph = NULL;
}

bool Graph::adjacente(node *graph, char *a, char *b) {
	node *searchA = graph;
	for (; searchA != NULL; searchA = searchA->next)
		if (searchA != NULL)
			if (searchA->name == a)
				break;

	node *searchB = graph;
	for (; searchB != NULL; searchB = searchB->next)
		if (searchB != NULL)
			if (searchB->name == b)
				break;

	link *links = (link *)searchA->links;

	if (links == NULL)
		return false;

	while (links != NULL && links->to != searchB)
		if (links != NULL)
			links = links->next;

	if (links != NULL)
		return true;

	links = (link *)searchB->links;

	if (links == NULL)
		return false;

	while (links != NULL && links->to != searchA)
		if (links != NULL)
			links = links->next;

	if (links != NULL)
		return true;

	return false;
}

link *Graph::vizinhos(node *graph, char *a) {
	node *search = graph;
	for (; search != NULL; search = search->next)
		if (search != NULL)
			if (search->name == a)
				break;

	link *links = (link *)search->links;

	if (links == NULL)
		return 0;

	return links;
}

void Graph::adiciona_vertice(node *graph, char *name) {

	for (node *search = graph; search != NULL; search = search->next)
		if (search != NULL)
			if (search->name == name)
				throw std::invalid_argument("Um no com este nome ja existe");

	node *g = graph;
	while (g->next != NULL)
		g = g->next;

	node *newV = (node *)malloc(sizeof(node));

	newV->name = name;
	newV->value = 0;
	newV->links = NULL;
	newV->next = NULL;
	newV->prev = g;

	g->next = newV;
}

void Graph::remove_vertice(node *graph, char *name) {

	node *search = graph;
	for (; search != NULL; search = search->next)
		if (search != NULL)
			if (search->name == name)
				break;

	for (node *g = graph; g->next != NULL; g = g->next) {
		if (g->links == NULL)
			continue;

		for (link *l = (link *)g->links; l->next != NULL;) {
			if (l->to != search)
				continue;

			l->prev->next = l->next;
			l->next->prev = l->prev;

			link *lAux = l->next;
			l = lAux;

			free(l);
		}
	}

	if (search->prev)
		search->prev->next = search->next;

	if (search->next)
		search->next->prev = search->prev;

	free(search);
}

void Graph::adiciona_aresta(node *graph, char *from, char *to) {
	node *searchFrom = graph;
	for (; searchFrom != NULL; searchFrom = searchFrom->next)
		if (searchFrom != NULL)
			if (searchFrom->name == from)
				break;

	node *searchTo = graph;
	for (; searchTo != NULL; searchTo = searchTo->next)
		if (searchTo != NULL)
			if (searchTo->name == to)
				break;

	link *newL = (link *)malloc(sizeof(link));
	newL->to = searchTo;
	newL->next = NULL;

	link *links = (link *)searchFrom->links;
	if (links != NULL) {
		while (links->next != NULL)
			links = links->next;

		newL->prev = links;
		links->next = newL;
	} else
		searchFrom->links = newL;
}

void Graph::remove_aresta(node *graph, char *from, char *to) {
	node *searchFrom = graph;
	for (; searchFrom != NULL; searchFrom = searchFrom->next)
		if (searchFrom != NULL)
			if (searchFrom->name == from)
				break;

	node *searchTo = graph;
	for (; searchTo != NULL; searchTo = searchTo->next)
		if (searchTo != NULL)
			if (searchTo->name == to)
				break;

	link *links = (link *)searchFrom->links;

	if (links == NULL)
		return;

	while (links->next != NULL && links->to != searchTo)
		links = links->next;

	if (links->prev)
		links->prev->next = links->next;

	if (links->next)
		links->next->prev = links->prev;

	free(links);
}

int Graph::retorna_valor_vertice(node *graph, char *name) {
	node *search = graph;
	for (; search != NULL; search = search->next)
		if (search != NULL)
			if (search->name == name)
				break;

	return search->value;
}

void Graph::muda_valor_vertice(node *graph, char *name, int value) {
	node *search = graph;
	for (; search != NULL; search = search->next)
		if (search != NULL)
			if (search->name == name)
				break;

	search->value = value;
}

int Graph::retorna_valor_aresta(node *graph, char *from, char *to) {
	node *searchFrom = graph;
	for (; searchFrom != NULL; searchFrom = searchFrom->next)
		if (searchFrom != NULL)
			if (searchFrom->name == from)
				break;

	node *searchTo = graph;
	for (; searchTo != NULL; searchTo = searchTo->next)
		if (searchTo != NULL)
			if (searchTo->name == to)
				break;

	link *links = (link *)searchFrom->links;

	if (links == NULL)
		throw std::invalid_argument("O link nao existe");

	while (links->next != NULL && links->to != searchTo)
		links = links->next;

	return links->value;
}

void Graph::muda_valor_aresta(node *graph, char *from, char *to, int value) {
	node *searchFrom = graph;
	for (; searchFrom != NULL; searchFrom = searchFrom->next)
		if (searchFrom != NULL)
			if (searchFrom->name == from)
				break;

	node *searchTo = graph;
	for (; searchTo != NULL; searchTo = searchTo->next)
		if (searchTo != NULL)
			if (searchTo->name == to)
				break;

	link *links = (link *)searchFrom->links;

	if (links == NULL)
		throw std::invalid_argument("O link nao existe");

	while (links->next != NULL && links->to != searchTo)
		links = links->next;

	links->value = value;
}
