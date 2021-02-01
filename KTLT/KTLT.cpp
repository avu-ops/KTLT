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
#include <stdio.h>
int getArrayPointer(int array_1[])
{
    printf("%x", array_1);
    return 0;
}

void main()
{
    int array_0[] = { 1,2,3,4,5 };
    printf("array_0: %x\r", array_0);
    getArrayPointer(array_0);
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
