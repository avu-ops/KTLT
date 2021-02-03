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
unsigned menhGia[N_MENH_GIA] = {10, 20, 50, 100, 200, 500 };

void main()
{
    std::cout << "Nhap so tien can rut (don vi 1000 Dong, boi so cua 10): ";

    unsigned soTien;
    std::cin >> soTien;

    unsigned soToTienTongCong = 0;
    unsigned theoMenhGia[N_MENH_GIA] = { 0 };
    
    unsigned soToTien = 0;
    for (int i = N_MENH_GIA - 1; i >= 0; --i)
    {
        theoMenhGia[i] = soTien / menhGia[i];
        soTien = soTien % menhGia[i];
        soToTienTongCong += theoMenhGia[i];
    }

    std::cout << "Can: \n";
    for (int i = N_MENH_GIA-1; i >= 0; --i)
    {
        std::cout << "\t" << std::setw(3) << menhGia[i] << " x " << std::left << std::setw(3) << theoMenhGia[i] << std::endl;
    }
    std::cout << "Tong cong: " << soToTienTongCong << " to";

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
