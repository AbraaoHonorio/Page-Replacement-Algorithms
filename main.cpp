#include "PageReplacement.h"


int main(void)
{
	PageReplacement *pageReplacement = new PageReplacement();

	pageReplacement->readFile("input/input.txt"); 
	pageReplacement->fifo();
	pageReplacement->otm();
	pageReplacement->lru();


	std::cout<<std::endl;
	delete pageReplacement;


	return 0;

}
