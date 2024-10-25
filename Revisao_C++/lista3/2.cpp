#include <iostream>
using namespace std;

void inverteString(char str[])
{
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main()
{
    char str[] = "Hello, World!";
    inverteString(str);
    cout << "String invertida: " << str << endl;
    return 0;
}
