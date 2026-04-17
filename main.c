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

typedef struct {
    char ID[10];
    char name[20];
    int seats[5][6]; 
} PLANE;

typedef struct TICKET {
    int rank; 
    char ID[10];
    char name[20];
    char seat[5];
    char gate[5];
    long long CMND;
    char position[20];
    char destination[20];
    DATE date;
    HOUR hour;
    struct TICKET *next;
} ticket;

// --- CÁC HÀM LƯU FILE ---

// 1. Lưu danh sách vé vào file văn bản (customer.exe)
void saveTicketsToText(ticket *head, const char *filename) {
    FILE *f = fopen(filename, "w"); // "w" để ghi đè, "a" nếu muốn ghi nối tiếp
    if (f == NULL) {
        printf("Loi mo file text!\n");
        return;
    }
    
    fprintf(f, "%-10s | %-18s | %-8s | %-5s | %-15s | %-15s | %-12s\n", 
            "ID", "Ho Ten", "Hang", "Ghe", "Diem di", "Diem den", "Ngay/Gio");
    fprintf(f, "--------------------------------------------------------------------------------------------\n");

    ticket *temp = head;
    while (temp != NULL) {
        char *rankStr = (temp->rank == 1) ? "T.Gia" : "Thuong";
        fprintf(f, "%-10s | %-18s | %-8s | %-5s | %-15s | %-15s | %02d/%02d/%d %02d:%02d\n",
                temp->ID, temp->name, rankStr, temp->seat, 
                temp->position, temp->destination,
                temp->date.day, temp->date.month, temp->date.year,
                temp->hour.h, temp->hour.m);
        temp = temp->next;
    }
    fclose(f);
    printf("[+] Da luu du lieu vao file van ban: %s\n", filename);
}

// 2. Lưu danh sách vé vào file nhị phân (Customer.dat)
void saveTicketsToBinary(ticket *head, const char *filename) {
    FILE *f = fopen(filename, "wb"); // "wb" là write binary
    if (f == NULL) {
        printf("Loi mo file nhi phan!\n");
        return;
    }

    ticket *temp = head;
    while (temp != NULL) {
        // Ghi dữ liệu của node hiện tại (không ghi con trỏ *next)
        fwrite(temp, sizeof(ticket) - sizeof(struct TICKET *), 1, f);
        temp = temp->next;
    }
    fclose(f);
    printf("[+] Da luu du lieu vao file nhi phan: %s\n", filename);
}

// 3. Lưu thông tin máy bay vào file nhị phân (plane.dat)
void savePlaneToBinary(PLANE *p, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Loi mo file plane.dat!\n");
        return;
    }
    fwrite(p, sizeof(PLANE), 1, f);
    fclose(f);
    printf("[+] Da luu trang thai may bay vao: %s\n", filename);
}

// --- CÁC HÀM KHÁC (GIỮ NGUYÊN HOẶC CHỈNH SỬA NHỎ) ---

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initPlane(PLANE *p, const char *id, const char *name) {
    strcpy(p->ID, id);
    strcpy(p->name, name);
    for (int i = 0; i < 5; i++) for (int j = 0; j < 6; j++) p->seats[i][j] = 0;
}

void input(ticket **head, PLANE *myPlane) {
    int number;
    static int id_counter = 1;
    printf("Number of tickets: ");
    scanf("%d", &number);
    
    for (int i = 0; i < number; i++) {
        ticket *newNode = (ticket*)malloc(sizeof(ticket));
        sprintf(newNode->ID, "%04d", id_counter++);
        
        printf("\n--- Ticket %s ---\n", newNode->ID);
        printf("Rank (0.normal / 1.VIP): "); scanf("%d", &newNode->rank);
        flush();
        printf("Name: "); fgets(newNode->name, 20, stdin);
        newNode->name[strcspn(newNode->name, "\n")] = '\0';
        
        // (Phần chọn ghế và các thông tin khác bạn giữ nguyên như code trước)
        // Giả định nhập nhanh để test file:
        printf("Seat: "); scanf("%s", newNode->seat);
        flush();
        printf("Position: ");
        fgets(newNode->position,sizeof(newNode->position),stdin);
        newNode->position[strcspn(newNode->position,"\n")] = '\0';
        printf("Destination: "); 
        fgets(newNode->destination,sizeof(newNode->destination),stdin);
        newNode->destination[strcspn(newNode->destination,"\n")] = '\0';
        printf("Date (d m y): "); scanf("%d %d %d", &newNode->date.day, &newNode->date.month, &newNode->date.year);
        printf("Hour (h m): "); scanf("%d %d", &newNode->hour.h, &newNode->hour.m);

        newNode->next = *head;
        *head = newNode;
    }
}

int main() {
    ticket *head = NULL;
    PLANE myPlane;
    initPlane(&myPlane, "VN123", "Boeing 737");

    input(&head, &myPlane);

    // THỰC HIỆN LƯU FILE SAU KHI NHẬP
    saveTicketsToText(head, "customer.txt");
    saveTicketsToBinary(head, "Customer.dat");
    savePlaneToBinary(&myPlane, "plane.dat");

    printf("\nDone! Kiem tra cac file trong thu muc code.\n");
    return 0;
}