#include <iostream>
#include <string>
using namespace std;


void lsd(string a[], int n, int w)
{
    int R = 256;
    string aux[n];
    for (int d = w-1; d>=0; d--)
    {
        int count[R+1];
        for (int r=0; r<R+1; r++)
            count[r] = 0;
        for(int i=0; i<n; i++)
            count[a[i][d] + 1] ++;
        for(int r=0; r<R; r++)
            count[r+1] += count[r];
        for(int i =0;i<n; i++)
            aux[count[a[i][d]]++] = a[i];
        for(int i=0; i< n; i++)
            a[i] = aux[i];
    }
}

int main(int argc, char const *argv[])
{
    string a[] = {
        "4PGC938",
        "2IYE230",
        "3CIO720",
        "1ICK750",
        "1OHV845",
        "4JZY524",
        "1ICK750",
        "3CIO720",
        "1OHV845",
        "1OHV845",
        "2RLA629",
        "2RLA629",
        "3ATW723" 
    };
    lsd(a, 13, 3);
    for (int i=0;i<13; i++)
        cout << a[i] << endl;
}

