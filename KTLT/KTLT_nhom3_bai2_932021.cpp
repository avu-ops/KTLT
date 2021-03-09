
#include <stdio.h>

typedef enum {
    L_0 = 0,
    L_5,
    L_10,
    L_15,
    L_20,
    L_25,
    L_30,
    L_35,
    L_MAX,
}TaxLevel;

float TaxArray[L_MAX] = { 0,0.05,0.1,0.15,0.20,0.25,0.30,0.35 };
int MoneyArray[L_MAX] = { 0,4000000,6000000,9000000,14000000,24000000,44000000,84000000 };

int CalculateTax(int inMoney, TaxLevel level) 
{
    int M = MoneyArray[level + 1] - MoneyArray[level];
    if (level == (L_MAX - 1))
    {
        return (inMoney) * (float)TaxArray[level];
    }

    if (inMoney <= M)
    {
        return (inMoney) * (float)TaxArray[level];
    }
    else
    {
        return CalculateTax(inMoney - M, TaxLevel(level + 1)) + (M)*TaxArray[level];
    }

}

int main()
{
    int money;
    printf("Nhap thu nhap: ");
    scanf_s("%d", &money);
    printf("Thue phai dong la: %d", CalculateTax(money, L_0));
    return 0;
}
