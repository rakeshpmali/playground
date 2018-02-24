#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNode
{
    int iData;
    struct sNode *pstNext;
};

struct sNode *g_pstHead = NULL; //*g_pstTail = NULL;

void add();
void delete();
void insert();
void replace();
void print();
void sort();

void main()
{
    int iSelect = 0;

start:
    printf("\n********** SINGLY LINKED LIST **********\n\n");
    printf("Operations:\n");
    printf("1. Add Node\n");
    printf("2. Delete Node\n");
    printf("3. Insert Node\n");
    printf("4. Replace Node\n");
    printf("5. Print All Nodes\n");
    printf("6. Sort the List\n");
    printf("7. Clear Screen\n");
    printf("0. Exit\n");
    printf("#Your Selection: ");
    scanf("%d", &iSelect);

    switch(iSelect)
    {
        case 0:
        {
            printf("\n=> Command: Exit \n");
            printf("\nBye Bye ! See you again ...\n\n");
            exit(EXIT_SUCCESS);
        }
        break;
        case 1: 
        {
            printf("\n=> Command: Add Node \n");
            add();
        }
        break;

        case 2:
        {
            printf("\n=> Command: Delete Node \n");
            delete();
        }
        break;
        
        case 3:
        {
            printf("\n=> Command: Insert Node \n");
            insert();
        }
        break;

        case 4:
        {
            printf("\n=> Command: Replace Node \n");
            replace(); 
        }
        break;
        
        case 5:
        {
            printf("\n=> Command: Print All Nodes \n");
            print();
        }
        break;
        
        case 6:
        {
            printf("\n=> Command: Sort the List \n");
            sort();
        }
        break;
        
        case 7:
        {
            printf("\n=> Command: Clear Screen \n");
            system("clear");
        }
        break;

        default:
            printf("\n!! Invalid Operation !!\n");
        break;
    }
    goto start;
    
}

void add()
{
    struct sNode *pstTemp = NULL;
    int iNewData = 0, iSelect = 0;

    printf("\nPlease Enter New Node Data:");
    scanf("%d",&iNewData);

    if (!g_pstHead)
    {
        g_pstHead = (struct sNode *) calloc(sizeof(struct sNode), sizeof(char));
        g_pstHead->iData = iNewData;
        g_pstHead->pstNext = NULL;
    } else {
        printf("\n* Where do you want to add the new node ? *:");
        printf("\n1. At Start of List");
        printf("\n2. At End of List");
        printf("\n#Your Selection: ");
        scanf("%d", &iSelect);

        if ((iSelect != 1) && (iSelect !=2)) 
        {
            printf("\n !! Invalid Position !!\n"); 
            return; 
        }

        if(2 == iSelect) {
            pstTemp = g_pstHead;

            while(pstTemp->pstNext)
            {
                pstTemp = pstTemp->pstNext;
            }

            pstTemp->pstNext = (struct sNode *) calloc(sizeof(struct sNode), sizeof(char));
            pstTemp = pstTemp->pstNext;
            pstTemp->iData = iNewData;
            pstTemp->pstNext = NULL;
        } else
        {
            pstTemp = (struct sNode *) calloc(sizeof(struct sNode), sizeof(char));
            pstTemp->iData = iNewData;
            pstTemp->pstNext = g_pstHead;
            g_pstHead = pstTemp;
        }
    }
    printf("\nAdded New Node with Data Value = %d\n", iNewData);
    print();
}

void delete()
{
    struct sNode *pstTemp1 = NULL, *pstTemp2 = NULL;
    int iDelVal = 0;
    
    if(!g_pstHead)
    {
        printf("\n\n!! List is Empty !!\n\n");
        return; 
    }  

    printf("\nEnter the Node Data Value to be Deleted: ");
    scanf("%d",&iDelVal);
    
    if(g_pstHead->iData == iDelVal) {
        free(g_pstHead);
        g_pstHead = g_pstHead->pstNext;
        printf("\nDeleted Node with Data Value = %d\n", iDelVal);
        print();
        return;
    }

    pstTemp1 = g_pstHead;
    pstTemp2 = pstTemp1->pstNext;

    while(pstTemp2)
    {
        if(pstTemp2->iData == iDelVal) {
            pstTemp1->pstNext = pstTemp2->pstNext;
            free(pstTemp2); 
            printf("\nDeleted Node with Data Value = %d\n", iDelVal);
            print();
            return;
        }
        pstTemp2=pstTemp2->pstNext;
        pstTemp1=pstTemp1->pstNext;
    }

    printf("\nNode with Data Value = %d Not Found !\n", iDelVal);
}

void insert()
{
    int iNewData = 0, iPrevData = 0;
    struct sNode *pstTemp1 = NULL, *pstTemp2 = NULL;

    if(!g_pstHead)
    {
        printf("\n\n!! List is Empty !!\n\n");
        return; 
    }  

    printf("\nEnter the New Node Data Value:"); 
    scanf("%d", &iNewData);
    printf("\nEnter the Node Data Value After which You Would Like to Insert the New Node:"); 
    scanf("%d", &iPrevData);
    
    pstTemp1 = g_pstHead;

    while(pstTemp1)
    {
        if (pstTemp1->iData == iPrevData) {
            pstTemp2 = pstTemp1->pstNext;
            pstTemp1->pstNext = (struct sNode *) calloc(sizeof(struct sNode), sizeof(char));
            pstTemp1->pstNext->iData = iNewData;
            pstTemp1->pstNext->pstNext = pstTemp2;
            printf("\nNew Node with Data Value = %d Inserted After Node with Data Value = %d\n", iNewData, iPrevData);
            print();
            return;
        }
        pstTemp1 = pstTemp1->pstNext;
    }
    
    printf("\nNode with Data Value = %d Not Found !\n", iPrevData);
}

void replace()
{
    int iNewData = 0, iPrevData = 0;
    struct sNode *pstTemp1 = NULL;

    if(!g_pstHead)
    {
        printf("\n\n!! List is Empty !!\n\n");
        return; 
    }  

    printf("\nEnter the Node Data Value to be Replaced:"); 
    scanf("%d", &iPrevData);
    printf("\nEnter the New Data Value:"); 
    scanf("%d", &iNewData);
    
    pstTemp1 = g_pstHead;

    while(pstTemp1)
    {
        if (pstTemp1->iData == iPrevData) {
            pstTemp1->iData = iNewData;
            printf("\nNode Data Value = %d Replaced with New Data Value = %d\n", iPrevData, iNewData);
            print();
            return;
        }
        pstTemp1 = pstTemp1->pstNext;
    }
    
    printf("\nNode with Data Value = %d Not Found !\n", iPrevData);
}

void print()
{
    struct sNode *pstTemp = g_pstHead;
    
    if(!g_pstHead)
    {
        printf("\n\n!! List is Empty !!\n\n");
        return; 
    }  

    printf("\nNodes: ");
    while(pstTemp)
    {
        printf("%d -> ", pstTemp->iData);
        pstTemp=pstTemp->pstNext;
    }
    printf("NULL\n");
}

void sort()
{
    int iSelect = 0, iTempData = 0, iSwapFlag = 0 ;
    struct sNode *pstTemp1 = NULL, *pstTemp2 = NULL;
    printf("\n\n* Please Select the Sort Order *");
    printf("\n1. Ascending");
    printf("\n2. Descending");
    printf("\n#Your Selection: ");
    scanf("%d", &iSelect);

    if(!g_pstHead)
    {
        printf("\n\n!! List is Empty !!\n\n");
        return; 
    }  

    if ((iSelect != 1) && (iSelect !=2)) 
    {
        printf("\n !! Invalid Sort Order !!\n"); 
        return; 
    }

    do
    {
        iSwapFlag = 0;
        pstTemp1 = g_pstHead;
 
        while (pstTemp1->pstNext != pstTemp2)
        {
            if (((iSelect == 1) && (pstTemp1->iData > pstTemp1->pstNext->iData)) || ((iSelect == 2) && (pstTemp1->iData < pstTemp1->pstNext->iData)))
            {
                iTempData = pstTemp1->iData;
                pstTemp1->iData = pstTemp1->pstNext->iData;
                pstTemp1->pstNext->iData = iTempData;
                iSwapFlag = 1;
            }
            pstTemp1 = pstTemp1->pstNext;
        }
        pstTemp2 = pstTemp1;
    }
    while (iSwapFlag);
    printf("\nList Sorting Done... \n"); 

    print();
}













