//Header File Inclusion
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
using namespace std;

//word data structure to be sent/recvd on socket
#pragma pack(1) //packing ON
struct Data {
    int nLines;         
    int totalCount;     
    char word[32];       
    int lineArray[32];
};
#pragma pack(0) // packing OFF

//class - describes statistics of each input word
class wordCountApp
{
    //Private data members
    int numOfLines;         //total number of lines in file;
    char *wordToFind;       //word to find
    FILE *filePtr;          //pointer to file for processing
    int totalWordCount;     //total word count
    int *lineArr;           //array holding count of word at each line. (array index = line)

    public:
    //default constructor
    wordCountApp ()
    {
        filePtr = NULL;
        numOfLines = 0;
        totalWordCount = 0;
        wordToFind = NULL;
        lineArr = NULL;
    }

    //parameterized constructor - initialize data members
    wordCountApp(int nLines, FILE *fPtr, char *word)
    {
        filePtr = fPtr;
        numOfLines = nLines;

        wordToFind = new char(sizeof(word));
        strcpy(wordToFind,word);

        lineArr = new int[nLines];
    }

    //set totalWordCount & lineArr member values
    void setTotalCountAndLineArray(int count, int *array) {
        totalWordCount = count;
        for(int i = 0; i<numOfLines; i++) {
            lineArr[i] = array[i];
        }
    }

    //parse the file, search for the word, set stats line wise & total count
    void setWordStats()
    {
        char ch, *word = new char[sizeof(wordToFind)];
        int index = 0;		//used as array index for word
        int wordCount = 0;	//hold word count in current line
        int line = 0;		//line index denoting number of lines

        //parse file character by character till end of file is reached	
        while( (ch = getc(filePtr)) !=EOF ) {
            //if it is a aplhabet, add it to word character array
            if (isalpha(ch)) {
                word[index++] = ch;
                continue;
            }
            //if not an alphabet, construct word string by NULL termination
            word[index] ='\0';

            //compare this word with the word to be found, if found increment the word count
            if(strncmp(wordToFind,word,strlen(wordToFind)) == 0) {
                ++wordCount;
            }

            //if end of line is encountered, add word count to the current line count
            //increment the line number, reset word count
            if (ch == '\n') {
                lineArr[line++] = wordCount;
                wordCount = 0;
            }

            strcpy(word," ");
            index = 0;
        }

        //store total word count
        for(int iterator=0; iterator < numOfLines; iterator++) {
            totalWordCount+=lineArr[iterator];
        }

        //rewind file pointer
        rewind(filePtr);
    }

    //display the word stats 
    void displayWordStats()
    {
        cout << "========================================" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Stats for Word: " << wordToFind << endl;
        cout << "----------------------------------------" << endl;
        cout << "Total Word Count in File = " << totalWordCount << endl;

        for(int iterator=0; iterator < numOfLines; iterator++) {
            cout << "Word Count in Line" << iterator+1 << " = " << lineArr[iterator] << endl;
        }

        cout << "========================================" << endl << endl;
    }

    //send object data to server
    int sendStatsToServer() {
        int sockId;
        struct sockaddr_in server;

        //create data to be sent on socket
        struct Data sendData;
        sendData.nLines = numOfLines;
        strcpy(sendData.word,wordToFind);
        sendData.totalCount = totalWordCount;
        for(int i=0 ; i<numOfLines; i++) {
            sendData.lineArray[i] = lineArr[i];
        }		

        //create socket, report error if any 
        sockId = socket(AF_INET, SOCK_STREAM, 0);
        if (sockId == -1) {
            cout << "Socket Creation Failed!" << endl;
            return -1;
        }

        //set server fields
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(55555);

        int ret;
        //socket connection, report error if any 
        ret = connect(sockId, (struct sockaddr*) &server, sizeof(struct sockaddr));
        if (ret == -1) {
            cout << "Connection Failed!" << endl;
            close(sockId);	
            return -1;
        }
        //send data via socket, report error if any 
        ret = send(sockId,&sendData,sizeof(struct Data),0);
        if (ret == -1) {
            cout << "Data Sending Failed!" << endl;
            close(sockId);	
            return -1;
        }

        //close socket
        close(sockId);	
        return 0;
    }

    //Destructor
    ~wordCountApp(){
        delete wordToFind;
        delete lineArr;
    }
};

