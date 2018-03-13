#include <iostream>
#include <windows.h>

using namespace std;

int *read(int *n);
void show(int tab[], int n);
void selectSort(int tab[], int n);
void bubbleSort(int tab[], int n);

int main()
{
    int choice, l = 0;
    int *arr, asize;
    bool req = false;

    do
    {
        cout << "Wybierz opcje menu:" << endl;
        cout << "1 - Podanie danych" <<  endl;
        cout << "2 - Sortowanie babelkowe" <<  endl;
        cout << "3 - Insert Sort" <<  endl;
        cout << "4 - Select Sort" <<  endl;
        cout << "5 - Wydruk tablicy" <<  endl;
        cout << "6 - Koniec programu" <<  endl;

        cin >> choice;
        switch(choice)
        {
            case 1:
                arr = read(&asize);
                req = true;
            break;

            case 2:
                if(req == true)
                    bubbleSort(arr, asize);
                else{
                    system("cls");
                    cout << "Nie wczytano tablicy!" << endl;
                }
            break;

            case 3:

            break;

            case 4:
                if(req == true)
                    selectSort(arr, asize);
                else{
                    system("cls");
                    cout << "Nie wczytano tablicy!" << endl;
                }
            break;

            case 5:
                if(req == true)
                    show(arr, asize);
                else{
                    system("cls");
                    cout << "Nie wczytano tablicy!" << endl;
                }
            break;

            case 6:
                system("cls");
               cout << "Koniec programu" << endl;
               return 0;
            break;

            default:
                cout << "Podano zla opcje menu!" << endl;
        }
    }while(choice != 6);
}

int *read(int *n)
{
        system("cls");
        do
        {
            cout << "Podaj rozmiar tablicy (>0)" << endl;
            cin >> *n;
        }while(*n<=0);

        int *tab = new int[*n];

        for(int i = 0; i < *n; i++)
        {
            cout << "Podaj element tab[" << i << "]" << endl;
            cin >> tab[i];
        }
    return tab;
}

void show(int tab[], int n)
{
    for(int i=0; i < n; i++)
        cout << "tab[" << i << "] = " << tab[i] << endl;
}

void selectSort(int tab[], int n)
{
    int k, mini, j, temp;

    for(k = 0; k < n-1; k++)
    {
        mini = k;
        for(j = k+1; j < n; j++)
        {
            if(tab[j] < tab[mini])
                mini = j;
        }
        temp = tab[mini];
        tab[mini] = tab[k];
        tab[k] = temp;
    }

}

void bubbleSort(int tab[], int n)
{
    int i,j,temp;

    for(i = 0; i < n; i++)
        for(j = 1; j <= n-1-i; j++)
        {
            if(tab[j-1] > tab[j])
            {
                temp = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = temp;
            }
        }
}
