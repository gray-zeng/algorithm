#include <iostream>
#include <string>
using namespace std;

void msd(string a[], int n)
{
    
}


int main(int argc, const char *argv[])
{
    string a[] = {
        "she",
        "sells",
        "seashells",
        "by",
        "the",
        "sea",
        "shore",
        "the",
        "shells",
        "she",
        "sells",
        "are",
        "surely",
        "seashells"
    };
    msd(a, 14);
    for (int i=0; i< 14; i++)
        cout << a[i] << endl;
    return 0;
}
