#include <iostream>
#include <string>

using namespace std;

void conv(int *num1, int *num2, int n1, int n2, string str1, string str2)
{
    int a[100] = {0}, b[100] = {0}, A = n1, B = n2, j = 0;

    if (str1[0] == '-')
    {
        j = 1;
    }
    else
        j = 0;
    for (int i = 0; j < n1; i++)
    {
        a[i] = a[i] * 10 + str1[j] - 0x30;
        j++;
    }
    if (str2[0] == '-')
    {
        j = 1;
    }
    else
        j = 0;
    for (int i = 0; j < n2; i++)
    {
        b[i] = b[i] * 10 + str2[j] - 0x30;
        j++;
    }
    if (str1[0] == '-')
    {
        n1--;
        A=n1;
        a[0] *= -1;
    }
    if (str2[0] == '-')
    {
        n2--;
        B=n2;
        b[0] *= -1;
    }
    for (int i = 0; A-1 >= 0; i++)
    {
        num1[i] = a[A];
        A--;
    }
    for (int i = 0; B-1 >= 0; i++)
    {
        num2[i] = b[B ];
        B--;
    }
    
}

void amount(int *num1, int *num2, int *result, int n1, int n2, int &n3)
{

    if (n1 >= n2)
    {
        for (int i = 0; i < n1; i++)
        {

            if (n2 > i)
            {
                result[i] += num1[i] + num2[i];
            }
            else
            {
                result[i] += num1[i];
            }

            if (result[i] > 9)
            {
                result[i + 1] += result[i] / 10;
                result[i] = result[i] % 10;
                if (i + 1 == n1)
                    n3++;
            }
            n3++;
        }
    }
    else
    {
        for (int i = 0; i < n2; i++)
        {

            if (n1 > i)
            {
                result[i] += num1[i] + num2[i];
            }
            else
            {
                result[i] += num2[i];
            }

            if (result[i] > 9)
            {
                result[i + 1] += result[i] / 10;
                result[i] = result[i] % 10;
                if (i + 1 == n2)
                    n3++;
            }
            n3++;
        }
    }
}

void subt(int *num1, int *num2, int *result, int n1, int n2, int &n3)
{
    int i = 0;

    if (n1 >= n2)
    {
        n3 = n1;
        for (i = 0; i < n1; i++)
        {
            if (n2 > i)
                result[i] += num1[i] - num2[i];
            else
                result[i] += num1[i];
            if (result[i] <= -1)
            {

                result[i] += 10;
                result[i + 1] -= 1;
            }
        }
        i = 1;
        while (result[n1 - i] == 0)
        {

            if (i == n1)
                break;
            n3--;
            i++;
        }
    }
    else
    {
        n3 = n2;
        for (i = 0; i < n2; i++)
        {
            if (n1 > i)
                result[i] += num2[i] - num1[i];
            else
                result[i] += num2[i];
            if (result[i] <= -1)
            {

                result[i] += 10;
                result[i + 1] -= 1;
            }
        }
        i = 1;
        while (result[n2 - i] == 0)
        {

            if (i == n2)
                break;
            n3--;
            i++;
        }
        result[n3 - 1] *= -1;
    }
}

void work(int *num1, int *num2, int *result, int n1, int n2, int &n3)
{
    n3 = n1 + n2 - 1;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            result[i + j] += num1[j] * num2[i];
        }
    }
    for (int i = 0; i < n3; i++)
    {
        if (result[i] > 9)
        {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
    }
    while (result[n3] == 0)
        n3--;
}

int main()
{
    string str1, str2;
    int num1[100] = {0}, num2[100] = {0}, result[100] = {0}, n1, n2, n3 = 0;
    std::cin >> str1;
    std::cin >> str2;
    n1 = str1.length();
    n2 = str2.length();
    conv(num1, num2, n1, n2, str1, str2);
    //work(num1, num2, result, n1, n2, n3);
    for (int i = 0; 0 <= n2; n2--)
    {
        cout << num1[n2];
    }
}