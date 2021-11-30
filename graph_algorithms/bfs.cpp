
#include <iostream>

int graph_matrix(int ** &graph, int &vertex_count){


	//We can in fact randomly initiate a graph.
	//In this code, we will use the example graph from our lecture
	//
	//

	vertex_count = 4;

	graph = new int *[vertex_count];

	for(int i = 0; i < vertex_count; i ++)
		graph[i] = new int[vertex_count];

	for(int i = 0; i < vertex_count; i ++)
		for(int j = 0; j < vertex_count; j ++)
			graph[i][j] = 0;



	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[2][1] = 1;
	graph[2][3] = 1;
	graph[3][1] = 1;


}


void
bfs_matrix(int **graph, int vertex_count, int root)
{

}

int main (int args, char **argv)
{
	int **graph;
	int vertex_count;

	int root = 2;

	graph_matrix(graph, vertex_count);

	bfs_matrix(graph, vertex_count, root);

	return 0;
}
