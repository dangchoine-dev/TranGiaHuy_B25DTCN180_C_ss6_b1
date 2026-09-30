#include <stdio.h>
#include <string.h>

int main() {
    const int MAX_PHIEU = 50;

    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;

    int chucNang;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chucNang);
        while (getchar() != '\n');

        if (chucNang == 1) {
            printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
            printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < soLuong; i++) {
                int tienPhat = ngayQuaHan[i] * 5000;

                printf("%d | %s | %d ngay | %d VND\n",
                       i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
            }

            printf("--------------------------------------------------\n");
            printf("Tong so phieu: %d\n", soLuong);
        }

        else if (chucNang == 2) {
            if (soLuong >= MAX_PHIEU) {
                printf("Loi: Danh sach phieu muon da day, khong the them!\n");
            } else {
                printf("Nhap ma phieu muon moi: ");
                scanf("%s", maPhieu[soLuong]);
                while (getchar() != '\n');

                ngayQuaHan[soLuong] = 0;
                soLuong++;

                printf("Them phieu muon thanh cong!\n");
            }
        }

        else if (chucNang == 3) {
            char maCanTim[20];
            int viTri = -1;
            int ngayMoi;

            printf("Nhap ma phieu muon can cap nhat: ");
            scanf("%s", maCanTim);
            while (getchar() != '\n');

            for (int i = 0; i < soLuong; i++) {
                if (strcmp(maPhieu[i], maCanTim) == 0) {
                    viTri = i;
                    break;
                }
            }

            if (viTri == -1) {
                printf("Khong tim thay phieu muon!\n");
            } else {
                printf("Tim thay phieu muon '%s' tai vi tri index %d.\n",
                       maPhieu[viTri], viTri);

                printf("Nhap so ngay qua han moi: ");
                scanf("%d", &ngayMoi);
                while (getchar() != '\n');

                if (ngayMoi < 0) {
                    printf("Loi: So ngay qua han khong duoc am!\n");
                } else {
                    ngayQuaHan[viTri] = ngayMoi;

                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                           maPhieu[viTri], ngayMoi);
                }
            }
        }

        else if (chucNang != 0) {
            printf("Loi: Chuc nang khong hop le!\n");
        }

    } while (chucNang != 0);

    printf("\nCam on ban da su dung chuong trinh!\n");

    return 0;
}
