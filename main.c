#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// --- CẤU TRÚC DỮ LIỆU ---
typedef struct {
    int day, month, year;
} DATE;

typedef struct {
    int h, m;
} HOUR;
// cau truc cho may bay
typedef struct {
    char ID[10];
    char name[20];
    int seatNormal;
    int seatVIP; 
    int seatHolded;
    int seatVIPHolded;
    DATE date;
    HOUR hour;
} plane;
// cau truc cho ve
typedef struct{
    char namePlane[10];
    int rank; 
    char IDTicket[10];
    char name[20];
    char seat[5];
    long long ID;
    char position[20];
    char destination[20];
    DATE date;
    HOUR hour;
}ticket;

int main(){
    printf("\n=========================================MANAGE PLANE TICKET=========================================\n");
    int select; // chon lua cac option
    do{
        printf("1. Update plane information.\n");
        printf("2. Update ticket.\n"); 
        printf("0. End program.\n");
        printf("Choose (0-2): ");
        scanf("%d",&select);
        switch(select){
            case 1: updatePlaneInformation(); break;
            case 2: updateTicket(); break;
            case 0: printf("Program is ended!"); break;
        }
    }while(select != 0);
    return 0;
}