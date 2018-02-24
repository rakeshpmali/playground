/*############################################################################################################################

## Title: serverApp
## Description: get word count data from client & display it on consol
## Owner: Rakesh Mali
## Compile: g++ serverApp.cpp -o serverApp 
## Usage: ./serverApp 

#############################################################################################################################*/

//Header File Inclusion
#include"wordCountApp.h"

int main() {
    int sockId, acceptId, clientSize;
    struct sockaddr_in server, client;
    struct Data recvData; //received word stats data

    //create socket, report error if any
    sockId = socket(AF_INET,SOCK_STREAM,0); 
    system("clear");
    if (sockId == -1) {
        cout << "Socket Creation Failed!" << endl;
        return -1;
    }

    //set server fields
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(55555);

    int ret;
    //bind socket, report error if any
    ret = bind(sockId, (struct sockaddr*) &server, sizeof(server));
    if (ret == -1) {
        cout << "Socket Bind Failed!" << endl;
        close(sockId);
        return -1;
    }

    //listen to incoming connection, repor error if any
    ret = listen(sockId,5);
    if (ret == -1) {
        cout << "Socket Listen Failed!" << endl;
        close(sockId);
        return -1;
    }

    clientSize = sizeof(client);
    cout << endl << endl << "*************** SERVER STARTED ***************" << endl << endl;

    //concurrent server, that accepts multiple  simultaneous connections
    while(1) {
        //accept connection, report error if any
        acceptId = accept(sockId, (struct sockaddr*) &client, (socklen_t*) &clientSize);
        if (acceptId == -1) {
            cout << "Socket Accept Failed!" << endl;
            close(sockId);
            return -1;
        }

        //each incoming connection is handled in seperate child process
        if (!fork()) {
            //read data from socket, report error if any 
            ret = recv(acceptId, &recvData, sizeof(struct Data),0);
            if (ret == -1) {
                cout << "Data Receiving Failed!" << endl;
                close(sockId);
                return -1;
            }

            cout << endl << endl << "*************** DATA RECEIVED FROM CLIENT ***************" << endl << endl;
            //create word object with received data
            wordCountApp *wcPtr = new wordCountApp(recvData.nLines,0,recvData.word);

            //set other members - totalWordCount & lineArr
            wcPtr->setTotalCountAndLineArray(recvData.totalCount,recvData.lineArray);	

            //display word stats
            wcPtr->displayWordStats();	

            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}
