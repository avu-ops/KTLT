// KTLT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
#include <iostream>
#include <chrono>
#include <ctime>

void main()
{
    std::cout << "Nhap nam sinh: ";
    int yearOfBirth;
    std::cin >> yearOfBirth;

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm parts;
    localtime_s(&parts, &now_c);

    int curYear = parts.tm_year + 1900;

    std::cout << "Tuoi cua ban la: " << curYear - yearOfBirth << std::endl;
}
*/

/*
#include <iostream>
#include <ctype.h>

void main()
{
    std::cout << "Nhap ky tu: ";
    char kytu;
    std::cin >> kytu;
    kytu = toupper(kytu);
    std::cout << "Ky tu in hoa: " << kytu;
}
*/


#include <iostream>
#include <ctype.h>

#define N_MENH_GIA 6
int menh_gia[N_MENH_GIA] = {10, 20, 50, 100, 200, 500 };

struct tien_rut{
    unsigned n_dongtien;
    unsigned n_dong_theo_menhgia[N_MENH_GIA];
};

tien_rut nmin(int so_tien, unsigned theomenhgia[])
{
    tien_rut ret;
    memset(&ret, 0, sizeof(ret));

    for (int i = 0; i < N_MENH_GIA; ++i)
    {
        if (so_tien == menh_gia[i])
        {
            ret.n_dong_theo_menhgia[i] += 1;
            ret.n_dongtien += 1;

            return ret;
        }
    }

    tien_rut next_min[N_MENH_GIA];
    memset(&next_min, 0, sizeof(next_min));
    unsigned n_dongtien_min = (unsigned)-1;
    unsigned min_idx = 0;

    for (int i = 0; i < N_MENH_GIA; ++i)
    {
        if (so_tien - menh_gia[i] >= 0)
        {
            next_min[i] = nmin(so_tien - menh_gia[i], ret.n_dong_theo_menhgia);
        }
        else
        {
            next_min[i].n_dongtien = unsigned(-1);
        }

        if (next_min[i].n_dongtien < n_dongtien_min)
        {
            ret.n_dongtien = next_min[i].n_dongtien;
            memcpy(&ret.n_dong_theo_menhgia[0], &next_min[i].n_dong_theo_menhgia[0], sizeof(ret.n_dong_theo_menhgia));
            min_idx = i;
        }
    }
    
    ret.n_dong_theo_menhgia[min_idx] += 1;
    ret.n_dongtien += 1;

    return ret;
}
void main()
{
    std::cout << "Nhap so tien can rut: ";

    int so_tien;
    std::cin >> so_tien;

    // memset(&sotien_theo_menhgia[0], 0, sizeof(sotien_theo_menhgia));
    
    unsigned theomenhgia[N_MENH_GIA] = { 0 };
    tien_rut tienrut = nmin(so_tien, theomenhgia);

    std::cout << "Can: \n";
    for (int i = N_MENH_GIA-1; i >= 0; --i)
    {
        std::cout << menh_gia[i] << " x " << tienrut.n_dong_theo_menhgia[i] << std::endl;
    }
    std::cout << "Tong cong: " << tienrut.n_dongtien << " dong";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
