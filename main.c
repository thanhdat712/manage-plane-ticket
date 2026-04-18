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
    char tu[20],den[20];  
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
    char tu[20],den[20];  
    char destination[20];
    char cccd[15];
    DATE date;
    HOUR hour;
}ticket;
// --- QUAN LY DANH SACH LIEN KET ---
//Dinh nghia Node cho danh sach chuyen bay
typedef struct NodePlane{ 
    plane data; 
    struct NodePlane* next; 
} NodePlane;
//Dinh nghia Node cho danh sach ve
typedef struct NodeTicket{ 
    ticket data; 
    struct NodeTicket* next; 
} NodeTicket;
//Khai bao con tro dau danh sach
NodePlane* headPlane=NULL;
NodeTicket* headTicket=NULL;
//Ham xoa bo dem(tranh loi troi lenh khi dung fgets sau scanf)
void clearBuffer(){
    int c;
    while ((c=getchar())!='\n' && c!=EOF);
}
// --- CAC HAM QUAN LY CHUYEN BAY ---
//Ham tim kiem chuyen bay theo ma ID
NodePlane* timPlane(char* id) {
    NodePlane* p=headPlane;
    while (p){ 
        if (strcmp(p->data.ID, id)==0) 
		return p; 
        p=p->next; 
    }
    return NULL;
}
//Ham them chuyen bay vao he thong
void themChuyenBay() {
    plane p;
    printf("\nNhap ID chuyen bay: "); 
	scanf("%s",p.ID);
    if(timPlane(p.ID)){ 
	printf("Ma da ton tai!\n"); 
	return; 
	}
    clearBuffer(); 
    printf("Ten may bay: "); 
    fgets(p.name,20,stdin); 
	p.name[strcspn(p.name,"\n")]=0;
    printf("Noi di: "); 
    fgets(p.tu,20,stdin); 
	p.tu[strcspn(p.tu,"\n")]=0;
    printf("Noi den: "); 
    fgets(p.den,20,stdin); 
	p.den[strcspn(p.den, "\n")]=0;
    printf("Ghe Thuong & VIP: "); 
	scanf("%d %d",&p.seatNormal,&p.seatVIP);
    p.seatHolded=0; 
	p.seatVIPHolded=0;
    printf("Ngay (dd mm yyyy): "); 
	scanf("%d %d %d",&p.date.day,&p.date.month,&p.date.year);
    printf("Gio (hh mm): "); 
	scanf("%d %d",&p.hour.h,&p.hour.m);
    //Cap phat bo nho cho Node moi va dua vao dau danh sach
    NodePlane* newNode=(NodePlane*)malloc(sizeof(NodePlane));
    newNode->data=p; 
    newNode->next=headPlane; 
    headPlane=newNode;
    printf("=>Them chuyen bay thanh cong!\n");
}
//Ham hien thi danh sach tat ca chuyen bay
void hienThiChuyenBay() {
    printf("\n%-7s | %-10s | %-12s | %-12s | %-8s | %-8s | %-15s\n", 
           "ID CB", "May bay", "Noi di", "Noi den", "Ghe T", "Ghe V", "Khoi hanh");
    printf("-----------------------------------------------------------------------------------------------------\n");
    NodePlane* p=headPlane;
    while(p) {
        printf("%-7s | %-10s | %-12s | %-12s | %d/%-6d | %d/%-6d | %02d:%02d %02d/%02d/%d\n", 
               p->data.ID,p->data.name,p->data.tu,p->data.den,
               p->data.seatHolded,p->data.seatNormal, 
               p->data.seatVIPHolded,p->data.seatVIP, 
               p->data.hour.h,p->data.hour.m, 
               p->data.date.day,p->data.date.month,p->data.date.year);
        p=p->next;
    }
}
// --- CAC HAM QUAN LY VE ---
// Ham dat ve
void datVe(){
    char idCB[10];
    int soLuong,rank;
    printf("\nNhap ma chuyen bay muon dat: "); 
    scanf("%s",idCB);
    NodePlane* pNode=timPlane(idCB);
    if(!pNode){ 
        printf("Khong tim thay chuyen bay!\n"); 
        return; 
    }
    printf("Nhap so luong ve muon dat: "); 
    scanf("%d",&soLuong);
    if(soLuong<=0) 
        return;
    printf("Hang ghe (1.VIP - 2.Thuong): "); 
    scanf("%d",&rank);
    // Kiem tra may bay con cho trong khong
    if(rank==1 && pNode->data.seatVIPHolded+soLuong>pNode->data.seatVIP){
        printf("Khong du cho VIP!\n"); 
        return;
    } else if (rank==2 && pNode->data.seatHolded+soLuong>pNode->data.seatNormal){
        printf("Khong du cho Thuong!\n"); 
        return;
    }
    // Vong lap nhap thong tin cho tung khach
    for(int i=0;i<soLuong;i++) {
        printf("\n--- Khach hang %d ---\n",i+1);
        ticket t;
        strcpy(t.namePlane,idCB);      
        strcpy(t.tu,pNode->data.tu);
        strcpy(t.den,pNode->data.den);
        t.rank=rank;
        t.date=pNode->data.date;      
        t.hour=pNode->data.hour;      
        printf("Ma ve: ");
        scanf("%s",t.IDTicket);
        printf("So CCCD: ");
        scanf("%s",t.cccd); 
        clearBuffer();
        printf("Ten hanh khach: "); 
        fgets(t.name,20,stdin); 
        t.name[strcspn(t.name,"\n")]=0;
        printf("So ghe: "); 
        scanf("%s",t.seat);
        // Tao Node moi va dua vao dau danh sach ve
        NodeTicket* newNode=(NodeTicket*)malloc(sizeof(NodeTicket));
        newNode->data=t; 
        newNode->next=headTicket; 
        headTicket=newNode;
        // Cap nhat so ghe dat trong chuyen bay
        if(rank==1) 
            pNode->data.seatVIPHolded++;
        else 
            pNode->data.seatHolded++;
    }
    printf("=>Dat ve thanh cong!\n");
}

//Ham hien thi danh sach tat ca ve
void hienThiVe(){
    printf("\n%-8s | %-13s | %-15s | %-5s | %-7s | %-15s\n", 
           "Ma Ve", "So CCCD", "Hanh khach", "Ghe", "ID CB", "Thoi gian");
    printf("--------------------------------------------------------------------------------------------\n");
    NodeTicket* t=headTicket;
    while(t){
        printf("%-8s | %-13s | %-15s | %-5s | %-7s | %02d:%02d %02d/%02d/%d\n", 
               t->data.IDTicket,t->data.cccd,t->data.name,t->data.seat,t->data.namePlane,
               t->data.hour.h,t->data.hour.m, 
               t->data.date.day,t->data.date.month,t->data.date.year);
        t=t->next;
    }
}
//Ham huy ve theo ma ve
void huyVe(){
    char idV[10];
    printf("\nNhap ma ve muon huy: "); 
	scanf("%s",idV);
    NodeTicket *curr=headTicket,*prev=NULL;
    while(curr){
        if(strcmp(curr->data.IDTicket,idV)==0){
            // Khi huy ve phai tra lai cho cho chuyen bay tuong ung
            NodePlane* p=timPlane(curr->data.namePlane);
            if(p){ 
                if(curr->data.rank==1) 
				p->data.seatVIPHolded--; 
                else p->data.seatHolded--; 
            }
            //Xoa Node khoi danh sach lien ket
            if(prev==NULL) 
			headTicket=curr->next; 
            else prev->next=curr->next;
            free(curr);
            printf("=>Da huy ve!\n");
            return;
        }
        prev=curr;
		curr=curr->next;
    }
    printf("Khong tim thay ve!\n");
}
// --- CHUONG TRINH CHINH (MENU) ---
int main() {
    int sel;
    do{
        printf("\n======= HE THONG QUAN LY BAY =======");
        printf("\n1. Them chuyen bay");
        printf("\n2. Danh sach chuyen bay");
        printf("\n3. Dat ve ");
        printf("\n4. Huy ve");
        printf("\n5. Danh sach ve da dat");
        printf("\n0. Thoat chuong trinh");
        printf("\nChon chuc nang: ");
        //Kiem tra dau vao hop le co menu
        if(scanf("%d", &sel)!=1){ 
            clearBuffer(); 
            printf("Vui long chi nhap so!\n");
            continue; 
        }
        switch(sel){
            case 1: themChuyenBay(); 
			break;
            case 2: hienThiChuyenBay(); 
			break;
            case 3: datVe(); 
			break;
            case 4: huyVe(); 
			break;
            case 5: hienThiVe(); 
			break;
            case 0: printf("Dang thoat... Tam biet!\n"); 
			break;
            default: printf("Lua chon khong co trong danh sach!\n");
        }
    } while(sel!=0);
    return 0;
}
