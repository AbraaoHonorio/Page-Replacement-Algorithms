#include "PageReplacement.h"
#include <fstream> // Input/output stream class to operate on files.
#include <algorithm>    // std::find
PageReplacement::PageReplacement()
{
	this->pageFaults_m = 0;
	this->sizeRam_m = 0;
}


PageReplacement::~PageReplacement()
{
	myQueue.clear();
	myPages.clear();
}


void PageReplacement::fifo(void)
{
	std::vector<int> arrayMemory;


	if (!myPages.empty())
	{
		/*inserting the value to queue*/
		for (int i = 0; i<sizeRam_m; i++)
		{
			if (std::find(myQueue.begin(), myQueue.end(), myPages[i]) != myQueue.end())
				;
            else
            {
                myQueue.push_back(myPages[i]);
                arrayMemory.push_back(myPages[i]);
                pageFaults_m++;

            }

		}

		int j = 0;  //variable to follow the memory
		/* Looking for element in memory */
		for (unsigned int i = sizeRam_m; i < myPages.size(); i++)
		{
			if (std::find(arrayMemory.begin(), arrayMemory.end(), myPages[i]) != arrayMemory.end())
				;
			else
			{
				myQueue.erase(myQueue.begin()); //Erase first element
				arrayMemory[j] = myPages[i]; // replacing in accordance with index(variable j)
				myQueue.push_back(myPages[i]);
				j++;
				if (j == (sizeRam_m)) // Checking if you have already reached the limit
					j = 0;

				pageFaults_m++;
			}

			/*					DEBUG                             */

			/*std::cout << "\n *** myQueue *** " << std::endl; //DEBUG
			for each (int element in myQueue)
			{
			std::cout << element << " " << std::endl; //DEBUG
			}

			std::cout << "\n *** arrayMemory *** " << std::endl; //DEBUG
			for each (int element in arrayMemory)
			{
			std::cout << element << " " << std::endl; //DEBUG
			}*/
		}

	}
	else
	{
		std::cout << " The Queue have empty or sizeRam is null " << std::endl;
	}


	std::cout << " \n FIFO " << pageFaults_m << " " << std::endl; //output
}

int findIndex(std::vector<int> myQueue, std::vector<int> myPages, int nPages)
{
	int index = 0;


	// erase the first nPages elements
	myPages.erase(myPages.begin(), myPages.begin() + nPages);

	// initialize an vector Priority with 1000
	std::vector<int> arrayPriority(myQueue.size(),1000);

	if (!myPages.empty())
	{
		for (unsigned int i = 0; i < myQueue.size(); i++)
		{
			for (unsigned int j = 0; j < myPages.size(); j++)
			{
				if (myQueue[i] == myPages[j])
				{
					arrayPriority[i] = j;
					break;
				}

			}
		}
		/*					DEBUG                             */
		/*std::cout << "\n ***  arrayPriority *** " << std::endl; //DEBUG
		for each (int element in arrayPriority)
		{
		std::cout << index << " *** " << element << " " << std::endl; //DEBUG
		}*/


		/* return o index with highest priority*/
		int winner = arrayPriority[0];
		for (unsigned int i = 0; i < arrayPriority.size(); i++)
		{
			if (winner < arrayPriority[i])
			{
				winner = arrayPriority[i];
				index = i;
			}
		}
	}


	return (index);
}


void PageReplacement::otm(void)
{
	/* initializing */
	pageFaults_m = 0;
	myQueue.clear();


	/*inserting the value to queue*/
	for (int i = 0; i<sizeRam_m; i++)
	{
		if (std::find(myQueue.begin(), myQueue.end(), myPages[i]) != myQueue.end())
				;
        else
        {
            pageFaults_m++;
		    myQueue.push_back(myPages[i]);
        }
	}


	if (!myPages.empty() && !myQueue.empty())
	{
		for (unsigned int i = sizeRam_m; i < myPages.size(); i++)
		{

			if (std::find(myQueue.begin(), myQueue.end(), myPages[i]) != myQueue.end())
				;
			else
			{
				int index = findIndex(myQueue, myPages, i);
				myQueue[index] = myPages[i]; //	replacing in accordance with index
				pageFaults_m++;
			}
		}
	}
	else
	{
		std::cout << " The Queue have empty or sizeRam is null " << std::endl;
	}

	std::cout << " OTM  " << pageFaults_m << " " << std::endl; //output
}



void PageReplacement::lru(void)
{
	/* initializing */
	pageFaults_m = 0;
	myQueue.clear();


	/*inserting the value to queue*/
	for (int i = (sizeRam_m-1); i>=0; i--)
	{
	    if (std::find(myQueue.begin(), myQueue.end(), myPages[i]) != myQueue.end())
				;
        else
        {
            pageFaults_m++;
            myQueue.push_back(myPages[i]);
        }
	}

	// deleting Erase the first sizeRam_m elements
	myPages.erase(myPages.begin(), myPages.begin() + sizeRam_m);

	if (!myPages.empty() && !myQueue.empty()) //verify exist elemen t
	{
		for (unsigned int i = 0; i <myPages.size(); i++)
		{
				auto it = std::find(myQueue.begin(), myQueue.end(), myPages[i]);
				if (it != myQueue.end())
				{
					auto index = std::distance(myQueue.begin(), it); // calculating the index of the element
					myQueue.erase(myQueue.begin() + index); // deleting the element
					myQueue.insert(myQueue.begin(), myPages[i]); //Inserting the element at the top( highest priority )

				}
				else
				{
					myQueue.insert(myQueue.begin(), myPages[i]); //Inserting the element at the top( highest  priority )
					myQueue.erase(myQueue.end()-1); //delete to lower priority
					pageFaults_m++;
				}
		}
	}
	else
	{
		std::cout << " The Queue have empty or sizeRam is null " << std::endl;
	}

	std::cout << " LRU  " << pageFaults_m << " " << std::endl; //output
}

void PageReplacement::readFile(std::string filename)
{

	std::ifstream myfile(filename);
	int element = 0;


	if (myfile.is_open())
	{
		myfile >> element; // get first value
		sizeRam_m = element;

		while (myfile >> element) // read the referenced strings
		{
			myPages.push_back(element);
		}
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}

	myfile.close();


}
