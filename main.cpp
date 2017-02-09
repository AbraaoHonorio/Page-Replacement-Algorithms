#include "PageReplacement.h"


int main(void)
{
	PageReplacement *pageReplacement = new PageReplacement();

	pageReplacement->readFile("input/input.txt"); //C://Users//allys//Desktop//Universidade//Conductor//SO2//input//input.in
	pageReplacement->fifo();
	pageReplacement->otm();
	pageReplacement->lru();


	std::cout<<std::endl;
	delete pageReplacement;


	return 0;

}
