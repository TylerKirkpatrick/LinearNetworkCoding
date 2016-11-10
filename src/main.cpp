//#include "Node.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>

using namespace std;

struct Node {
	int idNum;
	vector<Node *> connections;	
	int numDup;
	

	Node()
	{
		//name = "default";
		//connections.push_back();
		static int id = 0; 
		idNum = id++;
		numDup = 0;
	}

	/*
	Node(string pName)
	{
		name = pName;
	}
	*/

	Node(int pIdNum)
	{
		idNum = pIdNum;
	}

	void addNode(Node * &head)
	{
		for(int i=0; i<this->connections.size(); i++)
		{
			if(this->connections[i]->idNum == head->idNum)
			{
				numDup++;
				//cout<<"duplicate for"<<this->idNum<<" : "<<numDup<<endl;
				return;
			}
		}
	    connections.push_back(head);
	    //now we need to copy this node, and add it to the head's connections vector
	    //Node * temp = new Node(this->idNum);
    	head->connections.push_back(this);
    	//delete temp;	//'delete [] temp' causes a compilation error
	}

	void listConnections()
	{
		cout<<"For: "<<idNum<<": "<<endl;
		for(int i=0; i<connections.size(); i++)
		{
			cout<<connections[i]->idNum<<endl;
		}
		cout<<"--------------------"<<endl;
	}

	void showNetwork()
	{
		for(int i=0; i<this->connections.size(); i++)
		{
			cout<<this->idNum<<"--->"<<connections[i]->idNum<<endl;
		}
	}


};


void generateNetwork(int nSize)
{
	Node ** nodeArray = new Node*[nSize];

	//generate nodes
	for(int i=0; i<nSize; i++)
	{
		nodeArray[i] = new Node();
		
	}

	//add connections
	for(int i=0; i < nSize; i++)
	{	
		//gen random number of additional connections (now it is either 1,2, or 3)
		int randNum = random() % 3 +1;

		if(i > 0)
		{
			//create a connection
			nodeArray[i]->addNode(nodeArray[i-1]);
			//cout<<nodeArray[i]->connections.size()<<endl;

			//for randomNumber
			for(int b=1; b<=randNum; b++)
			{
				try {nodeArray[i]->addNode(nodeArray[randNum]);} catch(const exception& e) {cout<<"idk..."<<endl;}
				//cout<<nodeArray[i]->connections.size()<<endl;

			}

		}

		//nodeArray[i]->listConnections();
		
	}

//list all connections
	/*
	for(int j=0; j<nSize; j++)
		nodeArray[j]->showNetwork();
*/

	delete[] nodeArray;

}



int main() 
{
	//cout<<"hello\n\n";


	//Node ** nodeArray = nullptr;
	
	

	clock_t begin = clock();

	generateNetwork(50);

  	clock_t end = clock();

  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  	cout<<endl<<elapsed_secs<<endl;

/*
	//to make a network of size=20
	nodeArray = new Node*[20];

	//init everything
	for(int i=0; i<20; i++)
	{
		nodeArray[i] = new Node();
		//cout<<nodeArray[i]->idNum<<endl;
		
	}

	//generate 20 nodes
	for(int i=0; i < 20; i++)
	{	
		if(i > 0)
		{
			//create a connection
			nodeArray[i]->addNode(nodeArray[i-1]);
			cout<<nodeArray[i]->connections.size()<<endl;

		}


		//cout<<nodeArray[b]->idNum<<endl;
		
	}
*/

	//test some new nodes
	/*
	Node * n1 = new Node("juan");
	Node * n2 = new Node("two");
	Node * n3 = new Node("tree");

	n1->addNode(n2);
	n1->addNode(n3);
	n2->addNode(n3);

	nodeArray[0] = n1;

	cout<<nodeArray[0]->name<<endl;
*/

	

	//cout<<n2->connections.size()<<endl;
	//cout<<n1->name<<endl;

	//for (int i = 0; i < 20; ++i) {   // for each row
  	//	cout<<*nodeArray[i]


	//delete [] nodeArray;



	return 0;
}






