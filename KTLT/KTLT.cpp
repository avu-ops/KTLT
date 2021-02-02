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
#include <iomanip>
#include <ctype.h>

#define N_MENH_GIA 6
unsigned menh_gia[N_MENH_GIA] = {10, 20, 50, 100, 200, 500 };

void main()
{
    std::cout << "Nhap so tien can rut (don vi 1000 Dong): ";

    unsigned so_tien;
    std::cin >> so_tien;

    unsigned so_tien_scaled = so_tien / menh_gia[0];
    unsigned menh_gia_scaled[N_MENH_GIA];
    for (int i = 0; i < N_MENH_GIA; ++i)
    {
        menh_gia_scaled[i] = menh_gia[i] / menh_gia[0];
    }
 
    unsigned *sodongtien = new unsigned[so_tien_scaled + 1];
    unsigned *menhgia_cong = new unsigned[so_tien_scaled + 1];

    sodongtien[0] = 0;
    menhgia_cong[0] = 0;

    for(int so_tiensc = 1; so_tiensc <= so_tien_scaled; ++so_tiensc)
    {
        sodongtien[so_tiensc] = unsigned(-1);
        menhgia_cong[so_tiensc] = 0;
        unsigned sodongtien_truoc;
        for(int j = 0; j < N_MENH_GIA; ++j)
        {
            if(so_tiensc >= menh_gia_scaled[j])
            {
                sodongtien_truoc = sodongtien[so_tiensc - menh_gia_scaled[j]];
                if(sodongtien_truoc + 1 < sodongtien[so_tiensc])
                {
                    sodongtien[so_tiensc] = sodongtien_truoc + 1;
                    menhgia_cong[so_tiensc] = j;
                }
            }
        }
    }
    
    unsigned theo_menhgia[N_MENH_GIA] = {};
    unsigned tmp = so_tien_scaled;
    for(int i = 0; i < sodongtien[so_tien_scaled]; ++i)
    {
        int menhgia_idx = menhgia_cong[tmp];
        theo_menhgia[menhgia_idx]++;
        tmp -= menh_gia_scaled[menhgia_idx];
    };
    std::cout << "Can: \n";
    for (int i = N_MENH_GIA-1; i >= 0; --i)
    {
        std::cout << "\t" << std::setw(3) << menh_gia[i] << " x " << std::left << std::setw(3) << theo_menhgia[i] << std::endl;
    }
    std::cout << "Tong cong: " << sodongtien[so_tien_scaled] << " dong";

    delete[] sodongtien;
    delete[] menhgia_cong;
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
