//#include "Node.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//generate network of nodes, connected by edges

void generateGraph(int width, int height, int maxWeight);
void showGraph(int width, int height);

int globalArray[5][5];

using namespace std;

int main() 
{
	generateGraph(5,5,20);
	showGraph(5,5);
	//delete globalArray;

}







void generateGraph(int width, int height, int maxWeight) 
{
//globalArray = new int[width][height];

for (int i = 0; i < width; i++)
{
	for (int j = 0; j < height; j++)
	{
		if( i == j)
		{
			globalArray[i][j] = 0;
		}
		else if(j>i)
		{
			int var = rand() % maxWeight + 1;
			globalArray[i][j] = var;
			globalArray[j][i] = globalArray[i][j];
			
		}


		}
}
}
//done generating

void showGraph(int width, int height)
{
for (int i = 0; i < height; i++)
{
	for (int j = 0; j < width; j++)
	{
		
		cout<<globalArray[i][j]<<", ";

	}
	cout<<endl<<endl;
}
	
}
