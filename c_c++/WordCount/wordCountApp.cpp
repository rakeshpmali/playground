/*############################################################################################################################

## Title: wordCountApp
## Description: 
## 1. reads a text file
## 2. for every line in the file searches for the existence of input words
## 3. Keeps track of the number of each word occurrence in each line and total in the file
## Owner: Rakesh Mali
## Compile: g++ wordCountApp.cpp -lpthread -o wordCountApp  
## Usage: ./wordCountApp <input File> <word_1> <word_2> ..... <word_n>

#############################################################################################################################*/

//Header File Inclusion
#include"wordCountApp.h"

//Global functions decleration
void* wordThread(void *ptr);    //Thread Routine Function
int getNumOfLines(FILE *f);     //Get number of lines in a file

int main(int argc, char *argv[])
{
	//Input validation - check argument list
	if (argc < 3) {
		cout << argv[0] << ": Invalid Usage or Argument Count!" << endl;
		cout << "Usage: wordCountApp <filename> <word 1> <word 2> .... <word n>" << endl;
		return -1;
	}
	
	//open the input file
	FILE *fPtr =fopen(argv[1],"rb");
	//Report any error while opening file
	if(fPtr == NULL) {
		cout << argv[1] << ": File Not Found or Error Opening File !" << endl;
		return -1;
	}

	//Number of lines in file
	int nLines=0;
	nLines = getNumOfLines(fPtr);
	//Report if the file is empty	
	if (nLines == 0 ) {
		cout << "File is Empty!" << endl;
		return -1;
	}
	//Initial display code
	system("clear");	
	cout << "########################################" << endl;
	cout << "Program: Word Count App" <<endl;
	cout << "Input File: " << argv[1] << endl;
	cout << "Total Lines in File: " << nLines << endl;
	cout << "Input Words: ";
	for(int iterator = 2; iterator < argc; iterator++) {
		cout << argv[iterator] << " ";
	}
	cout << endl;
	
	//array of objet pointers	
	wordCountApp *pObj[argc-2];
	//array of thread IDs
	pthread_t threadId[argc-2];

	//instantiate object for each input word & create corresponding thread
	//pass the object pointer to its corresponding thread
	for (int i=0; i<argc-2; i++)
	{
		pObj[i] = new wordCountApp(nLines,fPtr,argv[i+2]);
		pthread_create(&threadId[i],NULL,wordThread,(void *)pObj[i]);
	}

	//wait for the threads to exit
	for (int j=0; j<argc-2; j++)
	{	
  		pthread_join(threadId[j],NULL);
	}

	cout << "########################################" << endl;
	//close the file	
	fclose(fPtr);	

	return 0;
}

//function to get total number of lines in the file
int getNumOfLines(FILE *f)
{
        int ch = 0, nLines = 0;
        //travserse through entire file, check for end of line & increment line count, set file pointer to start again
        while ((ch=fgetc(f))!=EOF) nLines+=(ch=='\n')?1:0; fseek(f,0,SEEK_SET);
        return nLines;
}

//thread function - calls function to set & display the word stats
void* wordThread(void *ptr) {
        wordCountApp *pObj = (wordCountApp*) ptr;

        //call function to search & set word stats
        pObj->setWordStats();

        //display word stats
        pObj->displayWordStats();
	
        //send the stats data to server
        if(pObj->sendStatsToServer() == 0) {
		cout << "********** DATA SENT TO SERVER *********" << endl << endl;
	} else {
		cout << "********** DATA SENDING FAILED *********" << endl << endl;
	}

        //exit thread
        pthread_exit(0);
}
