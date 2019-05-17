#include <iostream>
#include <string>

using namespace std;

void conv(int *num1, int *num2, int &n1, int &n2, string str1, string str2)
{
    int a[n1 + n2] = {0}, b[n1 + n2] = {0}, A = 0, B = 0, j = 0;

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
        A += 1;
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
        B += 1;
    }

    cout << endl;
    if (str1[0] == '-')
    {
        // a[0] *= -1;
        n1--;
    }
    for (int i = 0; A - 1 >= 0; i++)
    {
        num1[i] = a[A - 1];
        A--;
    }

    if (str2[0] == '-')
    {
        // b[0] *= -1;
        n2--;
    }

    for (int i = 0; B - 1 >= 0; i++)
    {
        num2[i] = b[B - 1];
        B--;
    }
    cout << endl;
    system("clear");
}

void amount(int *num1, int *num2, int *result, int n1, int n2, int &n3, string str1, string str2)
{
    int a = 0;
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
        {
            if (num1[i] > num2[i])
            {
                a = 1;
                break;
            }
            if (num1[i] < num2[i])
            {
                a = 2;
                break;
            }
            i++;
        }
        if (a == 0)
            a = 1;
    }
    if (n1 > n2)
        a = 3;
    if (n1 < n2)
        a = 4;

    if ((n1 >= n2 && a == 1) || a == 3)
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
        if (str1[0] == '-' && str2[0] == '-')
            result[n3 - 1] *= -1;
        if (str1[0] == '-' && str2[0] == '-')
            result[n3 - 1] *= -1;
        if (str1[0] == '-' && a == 1)
            result[n3 - 1] *= -1;
    }
    else if ((n1 <= n2 && a == 2) || a == 4)
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
        if (str1[0] == '-' && str2[0] == '-')
            result[n3 - 1] *= -1;
        if (a == 2)
            result[n3 - 1] *= -1;
        if (str2[0] == '-' && a == 2)
            result[n3 - 1] *= -1;
    }
}

void subt(int *num1, int *num2, int *result, int n1, int n2, int &n3, string str1, string str2)
{
    int i = 0, a = 0;

    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
        {
            if (num1[i] > num2[i])
            {
                a = 1;
                break;
            }
            if (num1[i] < num2[i])
            {
                a = 2;
                break;
            }
            i++;
        }
        if (a == 0)
            a = 1;
    }
    if (n1 > n2)
        a = 3;
    if (n1 < n2)
        a = 4;

    if ((n1 >= n2 && a == 1) || a == 3)
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
        if (str1[0] == '-')
            result[n3 - 1] *= -1;
    }
    else if ((n2 >= n1 && a == 2) || a == 4)
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
        if (str1[0] == '-')
            result[n3 - 1] *= -1;
    }
}

void work(int *num1, int *num2, int *result, int n1, int n2, int &n3, string str1, string str2)
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
    if (n3 < 0)
        n3 = 0;
    if (str1[0] == '-' && str2[0] != '-')
        result[n3] *= -1;
    if (str2[0] == '-' && str1[0] != '-')
        result[n3] *= -1;
    n3++;
}

void division(int *num1, int *num2, int *result, int n1, int n2, int &n3, string str1, string str2)
{
    int q = n1 - 1, e = q, w = n2 - 1;
    int a = 0, b = 0, j = 0, v = 0, indx = 0, m = 0, d = 0, r = 0, z = 0;

    while (1)
    {
        
        if (n1 < n2)
        {
            result[0] = 0;
            n3 = 1;
            break;
        }
        if (n2 - 1 == 0 && num2[0] == 1)
        {
            for (int i = 0; 0 < n1 - i - 1; i++)
            {
                result[i] = num1[n1 - i - 1];
            }
            n3 = n1;
            break;
        }
        for (int i = 0; 0 <= (n2 - 1) - i; i++)
        {
            if (num1[q - i] > num2[w - i])
            {
                a = 1;
                break;
            }
            if (num1[q - i] < num2[w - i])
            {
                a = 2;
                break;
            }
        }

        if (a != 2 && a != 1)
            a = 1;
        j = 0;

        if (a == 1 || b == 1)
        {

            while (1)
            {
                j = 0;
                for (int i = q - w - v; i <= q; i++)
                {
                    num1[i] -= num2[j];
                    if (j < n2)
                        j++;
                    if (num1[i] <= -1)
                    {
                        if (num1[q] == 0 && v != 1)
                        {
                            break;
                        }
                        num1[i] += 10;
                        num1[i + 1] -= 1;
                    }
                }
                m = 0;
                result[indx]++;

                for (int i = 0; 0 <= (n2 - 1) - i + v; i++)
                {
                    if (num1[q - i] > num2[w - i + v])
                    {
                        a = 1;
                        break;
                    }
                    if (num1[q - i] < num2[w - i + v])
                    {
                        m = 2;
                        break;
                    }
                }

                if (m == 2)
                {
                    e = q;
                    int i = 0;
                    while (q + w > e)
                    {
                        if (q < w)
                            break;
                        if (num1[q - i] == 0)
                            i++;
                        else
                        {
                            break;
                        }

                        e++;
                    }
                    if (i > 0 && num1[q - i] < num2[w])
                        i++;
                    if (v == 1)
                        i--;
                    while (i > 1)
                    {
                        indx++;
                        result[indx] = 0;
                        i--;
                    }

                    indx++;
                    d = v;
                    b = 0;
                    v = 0;

                    break;
                }
            }
        }
        else if (a == 2)
        {
            v++;
            b = 1;
        }
        m = 0;
        z = d;
        if (z == 2)
        {
            r = 1;
        }

        if (q >= w)
        {
            e = q;
            if (q != 0)
            {
                while (num1[q] <= 0 && q + w + d >= e)
                {
                    q--;
                    if (q == 0)
                    {
                        m = 2;
                        if (num1[w] >= num2[w])
                        {

                            m = 0;
                        }
                        break;
                    }
                }
                e++;
                if (num1[w] < num2[w] && d == 1)
                    d = 0;
                if (n1 == n2)
                    d = 1;
            }
            else
            {
                m = 2;
                if (num1[w] > num2[w])
                {

                    m = 0;
                }
                break;
            }
        }

        if (q <= w)
        {

            if (q == w)
            {

                for (int i = 0; 0 <= (n2 - 1) - i + v; i++)
                {
                    if (num1[q - i] > num2[w - i + v])
                    {
                        a = 1;
                        break;
                    }
                    if (num1[q - i] < num2[w - i + v])
                    {
                        a = 2;
                        break;
                    }
                }

                if (a == 2)
                {
                    if (q == 0 && num1[q] == 0)
                        break;
                    while (w - 1 >= 0)
                    {
                        indx++;
                        result[indx] = 0;
                        w--;
                    }
                }
            }
            else
            {

                if (q == 0 && num1[q] == 0)
                    break;
                while (w - 1 >= 0)
                {
                    indx++;
                    result[indx] = 0;
                    w--;
                }
                a = 2;
            }
            if (w < 0)
                w = 0;
            if (a == 2 && w == 0)
            {

                m = 2;
                q = 0;
            }
        }
        if (q == 0 && m == 2)
            break;

        while (num1[q] == 0)
        {

            indx++;
            result[indx] = 0;
            q--;
            if (q < w)
            {
                indx++;
                result[indx] = 0;

                m = 2;
                break;
            }
        }

        if (q < 0)
            q = 0;
        if (q == 0 && m == 2)
            break;
    }
    for (int i = 0; 0 <= (n2 - 1) - i; i++)
    {
        if (num1[q - i] > num2[w - i])
        {
            a = 1;
            break;
        }
        if (num1[q - i] < num2[w - i])
        {
            a = 2;
            break;
        }
    }

    if (a != 2 && a != 1)
        a = 1;
    if (n3 != n1)
        if (a == 1)
            n3 = n1 - n2 + 1;
        else if (a == 2)
            n3 = n1 - n2;
    if (str1[0] == '-' && str2[0] != '-')
        result[0] *= -1;
    if (str2[0] == '-' && str1[0] != '-')
        result[0] *= -1;
}


void print(int *result, int n3, string str1, string str2, char ch)
{
    cout << str1 << ch << str2 << "=";
    for (; n3 - 1 >= 0; n3--)
    {
        cout << result[n3 - 1];
    }
}
void Div_print(int *result, int n3, string str1, string str2, char ch)
{
    cout << str1 << ch << str2 << "=";
    for (int i = 0; n3 > i; i++)
    {
        cout << result[i];
    }
}

int otwet()
{
    string str1, str2;
    char ch;
    int n1, n2, n3 = 0;
    cin >> str1;
    cin >> ch;
    cin >> str2;
    n1 = str1.length();
    n2 = str2.length();
    int num1[n1 + n2] = {0}, num2[n1 + n2] = {0}, result[n1 + n2] = {0};
    conv(num1, num2, n1, n2, str1, str2);
    switch (ch)
    {
    case '+':
        if ((str1[0] == '-' && str2[0] == '-') || (str1[0] != '-' && str2[0] != '-'))
        {
            amount(num1, num2, result, n1, n2, n3, str1, str2);
            print(result, n3, str1, str2, ch);
        }
        else
        {
            subt(num1, num2, result, n1, n2, n3, str1, str2);
            print(result, n3, str1, str2, ch);
        }
        break;

    case '-':
        if ((str1[0] == '-' && str2[0] == '-') || (str1[0] != '-' && str2[0] != '-'))
        {
            subt(num1, num2, result, n1, n2, n3, str1, str2);
            print(result, n3, str1, str2, ch);
        }
        else
        {
            amount(num1, num2, result, n1, n2, n3, str1, str2);
            print(result, n3, str1, str2, ch);
        }
        break;
    case '*':
        work(num1, num2, result, n1, n2, n3, str1, str2);
        print(result, n3, str1, str2, ch);
        break;
    case '/':
    division (num1, num2, result, n1, n2, n3, str1, str2);
    Div_print(result, n3, str1, str2, ch);
    break;
    default:
        break;
    }
    cout << endl;
    return ch;
}

int main()
{
    char temp = '1';
    while (temp != '0')
    {
        temp = otwet();
    }
}