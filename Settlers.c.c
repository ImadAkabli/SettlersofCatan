#include <stdio.h>
// My procedure throughout this problem after many trials that ended up failing
// I concluded that neither BFS nor DFS won't do me any good
// because it is quite impossible to keep track of the length when parsing the graph
// because that traversal is random
// There when I noticed that this is going to be solved using Bruteforce
// For the first time, I hard coded it using nested loops which made it not practical
// When I submitted my code for a friend of mine, he suggesed that it is more practical
// If I used recursive function
// So this was the by product of trying to fix this for 2 days using BFS/DFS
// which ended up doing no good for me
// Therefore, I turned the graph into and adjacency matrix and used to solve the problem

int city[26][26];
int max_length;
int n, m;

// This function will be used to parse through every node that is adjacent
// to the source node given in the main function
// Me being inspired from the first ever piece of code we have written in class
// When we designed that guessing game and we used the attributes of the data 
// To kind of keep track implicity of the progress of the code
// That is when you will notice in the function where I first delete the edge between
// Two nodes which marks them as unvisited which helps me avoid not falling into
// An infinite loop trap since the function checks only for nodes connected to each other
// Last, whenever the recursive call is over and when out of the loop
// I compare the length with the already set max_length.
void bruteforce_travsersal(int source_node, int length) {

	for (int i = 0; i < n; i++)
	{
		if (city[source_node][i] == 1) {
			city[source_node][i] = city[i][source_node] = 0;
			bruteforce_travsersal(i, length + 1);
			city[source_node][i] = city[i][source_node] = 1;
		}
	}
	
		if (length > max_length)
		{
			max_length = length;
		}
}

int main()
{

  // Here the reason behind using this while loop is related to competitive programming
  // Practices because since in the input statement we don't have the number of lines
  // gives so we can be able to parse through the input using a simple loop
  // instead we know that the scanf function return the number of inputs successfully
  // scanned therefore, we use it to make sure we scanned 2 inputs at a time
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (m == 0 && n == 0)
		{
			break;
		}

    // This is to set every connection in the adjacency matrix to 0
    // which means to connections existing
    for(int i = 0; i < 26; i++){
      for(int j = 0; j < 26; j++){
        city[i][j] = 0;
      }
    }

    // This part of the code is to set connections between different nodes
    // 1 for connected 0 for no connection
		int node, edge;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &node, &edge);
			city[node][edge] = city[edge][node] = 1;
		}
		max_length = 0;

    // This is the part where I feed the traversal function a source to start from
    // Consequently, considering every single node as a source and testing every case
		for (int source = 0; source < n; source++)
		{
			bruteforce_travsersal(source, 0);
		}

		printf("%d\n", max_length);
	}
}
