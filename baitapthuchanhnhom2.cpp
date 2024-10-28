//bainhom2 ctdl phan cuoi
/* Xoa sinh vien */
void Xoa(List L)
{
    int count = 0;
    char maSV[10];
    Position P, TmpCell;
    P = First_List(L);
    if (!IsEmpty_List(L))
    {
        printf("Nhap ma sinh vien can xoa: ");
        gets(maSV);
        P = First_List(L);
        while (P != NULL)
        {
            if (strcmp(P->Element.maSV, maSV) == 0)
            {
                count++;
                Delete_List(P, &L);
                printf("\nXoa sinh vien thanh cong.\n");
                break;
            }
            P = P->Next;
        }
        if (count == 0)
        {
            printf("\nKhong tim thay sinh vien co ma sinh vien la %s.\n", maSV);
        }
    }
    else
        printf("List is empty!");

    Save_List(L);
}
/* Menu */
void Menu(List L)
{
    system("cls");
    int choice;
    do
    {
        printf("\n\nMenu:");
        printf("\n1. Them sinh vien");
        printf("\n2. Sua thong tin sinh vien");
        printf("\n3. Xoa sinh vien");
        printf("\n4. In danh sach sinh vien");
        printf("\n5. Sap xep danh sach tang dan theo diem");
        printf("\n6. Sap xep danh sach giam dan theo diem");
        printf("\n7. Tim kiem sinh vien theo MSSV");
        printf("\n8. Xuat danh sach sinh vien co diem >= X");
        printf("\n9. Thoat");
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        system("cls");
        fflush(stdin);
        switch (choice)
        {
        case 1:
            system("cls");
            Them(L);
            break;
        case 2:
            system("cls");
            Sua(L);
            break;
        case 3:
            system("cls");
            Xoa(L);
            break;
        case 4:
            system("cls");
            Write_List(L);
            break;
        case 5:
            system("cls");
            printf("\nDanh sach sau khi sap xep tang dan theo diem hoc phan: \n");
            SapXepTangDan(L);
            Write_List(L);
            break;
        case 6:
            system("cls");
            printf("\nDanh sach sau khi sap xep giam dan theo diem hoc phan: \n");
            SapXepGiamDan(L);
            Write_List(L);
            break;
        case 7:
            system("cls");
            printf("\nTim kiem sinh vien theo MSSV: \n");
            TimKiemTheoMSSV(L);
            break;
        case 8:
            system("cls");
            XuatDiemLonHonX(L);
            break;
        case 9:
            system("cls");
            printf("\nThoat chuong trinh.\n");
            return;
        default:
            system("cls");
            printf("\nLua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 9);
}
/* Sap xep danh sach tang dan theo diem hoc phan */
void SapXepTangDan(List L)
{
    if (IsEmpty_List(L))
    {
        printf("Danh sach rong!\n");
        return;
    }
    Position i, j, min;
    ElementType temp;
    for (i = First_List(L); i->Next != NULL; i = i->Next)
    {
        min = i;
        for (j = i->Next; j != NULL; j = j->Next)
        {
            if (j->Element.diemHocPhan < min->Element.diemHocPhan)
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = i->Element;
            i->Element = min->Element;
            min->Element = temp;
        }
    }
    Save_List(L);
}
/* Sap xep danh sach giam dan theo diem hoc phan */
void SapXepGiamDan(List L)
{
    if (IsEmpty_List(L))
    {
        printf("Danh sach rong!\n");
        return;
    }
    Position i, j, max;
    ElementType temp;
    for (i = First_List(L); i->Next != NULL; i = i->Next)
    {
        max = i;
        for (j = i->Next; j != NULL; j = j->Next)
        {
            if (j->Element.diemHocPhan > max->Element.diemHocPhan)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = i->Element;
            i->Element = max->Element;
            max->Element = temp;
        }
    }
    Save_List(L);
}
/* Tim kiem sinh vien theo MSSV */
void TimKiemTheoMSSV(List L)
{
    char maSV[10];
    int count = 0;
    Position P;
    P = First_List(L);
    if (IsEmpty_List(L))
    {
        printf("Danh sach rong!\n");
        return;
    }
    do
    {
        printf("Nhap ma sinh vien can tim: ");
        gets(maSV);
        if (Kt_MSSV(L, maSV) == 0)
        {
            printf("Ma sinh vien khong ton tai. Vui long nhap lai.\n");
        }
    } while (Kt_MSSV(L, maSV) == 0);
    while (P != NULL)
    {
        if (strcmp(P->Element.maSV, maSV) == 0)
        {
            count++;
            printf("\nMa sinh vien: %s", P->Element.maSV);
            printf("\nHo ten: %s", P->Element.hoTen);
            printf("\nNgay sinh: %s", P->Element.ngaySinh);
            printf("\nGioi tinh: %s", P->Element.gioiTinh);
            printf("\nDiem hoc phan: %.2f", P->Element.diemHocPhan);
            break;
        }
        P = P->Next;
    }
    if (count == 0)
    {
        printf("\nKhong tim thay sinh vien co ma sinh vien la %s.\n", maSV);
    }
}
/* Xuat danh sach sinh vien co diem >= X */
void XuatDiemLonHonX(List L)
{
    Position P;
    int x, count = 0;
    if (!IsEmpty_List(L))
    {
        do
        {
            printf("Nhap diem >= x (0-10) ð? t?m: ");
            scanf("%d", &x);
            if (x < 0 || x > 10)
            {
                printf("Diem hoc phan khong hop le. Vui long nhap lai.\n");
            }
        } while (x < 0 || x > 10);
        printf("Danh sach sinh vien co diem >= %d: \n", x);
        P = First_List(L);
        while (P != NULL)
        {
            if (P->Element.diemHocPhan >= x)
            {
                count++;
                printf("\nMa sinh vien: %s", P->Element.maSV);
                printf("\nHo ten: %s", P->Element.hoTen);
                printf("\nNgay sinh: %s", P->Element.ngaySinh);
                printf("\nGioi tinh: %s", P->Element.gioiTinh);
                printf("\nDiem hoc phan: %.2f", P->Element.diemHocPhan);
            }
            P = P->Next;
        }
        if (count == 0)
        {
            printf("\nKhong co sinh vien nao co diem >= %d.\n", x);
        }
    }
    else
        printf("List is empty!");
    printf("\n");
}


