//#pragma once

#ifndef PAGEREPLACEMENT_H
#define PAGEREPLACEMENT_H

#include <vector>
#include <string>
#include <iostream>

class PageReplacement
{
public:

	PageReplacement();
	virtual ~PageReplacement();

	//function to read the referenced strings
	void readFile(std::string filename);

	/* Funtions: implementation of page replacement algorithms */
	void fifo(void); // algorithm Fifo
	void otm(void); //  algorithm OTM
	void lru(void); //   algorithm LRU


private:
	int pageFaults_m; // Missing page number
	int sizeRam_m; // size memory
	std::vector<int> myQueue; // the Queue
	std::vector<int> myPages; // reference string
};

#endif /* PAGEREPLACEMENT_H */

