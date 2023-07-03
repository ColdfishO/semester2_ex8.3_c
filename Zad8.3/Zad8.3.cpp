#include <iostream>
#include<locale.h>
using namespace std;
void autor(void) {
    cout << endl;
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "Autor programu: Simon Dudek\n\n";
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "\n\n";
}
template <typename T>
class wektor {
private:
    T *tab[10];
    int liczba;
public:
    wektor() {
        for (int i = 0;i < 10;i++) {
            tab[i] = NULL;
        }
        liczba = 0;
    }
    wektor(T *x) {
        for (int i = 0;i < 10;i++) {
            tab[i] = x;
        }
        liczba = 10;
    }
    ~wektor(){};
    int ile_elementów() {
        return liczba;
    }
    T& co_na(int gdzie) {
        if (gdzie < 10 && gdzie >= 0) {
            return *tab[gdzie];
        }
        else {
            exit(0);
        }
    }
    void wstaw(T *obiekt) {
        if (liczba < 10) {
            tab[liczba] = obiekt;
            liczba++;
        }
    }
    void wstaw(T *obiekt, int gdzie) {
        if (gdzie < 10 && gdzie >= 0) {
            if (liczba < 10) {
                for (int i = 9 - gdzie;i > 0;i--) {
                    tab[gdzie + i] = tab[gdzie + i - 1];
                }
                tab[gdzie] = obiekt;
                liczba++;
            }
        }

    }
    void usun() {
        if (liczba > 0) {
            if (tab[liczba - 1] != NULL) {
                tab[liczba - 1] = NULL;
                liczba--;
            }
        }
    }
    void usun(int gdzie) {
        if (gdzie < 10 && gdzie >= 0) {
            if (tab[gdzie] != NULL) {
                for (int i = 1;i + gdzie < 10;i++) {
                    tab[gdzie + i - 1] = tab[gdzie + i];
                }
                tab[liczba - 1] = NULL;
                liczba--;
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "");
    autor();
    char znk = 'a';
    char *x = &znk;
    int cal = 5;
    int cal1 = 6;
    int cal2 = 10;
    int cal3 = 20;
    int cal4 = 2;
    int *c = &cal;
    double przec = 2.5;
    double przec1 = 5.6;
    double przec2 = 2.3;
    double przec3 = 4.6;
    double przec4 = 6.8;
    double przec5 = 5.4;
    double *p = &przec;
    char litera = 'd';
    char *z = &litera;
    int ile;
    int cocal;
    double coprze;
    char coznak;
    wektor<int> calkowite;
    wektor<double> przecinkowe;
    wektor<char> znaki(x);
    calkowite.wstaw(c);
    c = &cal1;
    calkowite.wstaw(c);
    c = &cal2;
    calkowite.wstaw(c);
    c = &cal3;
    calkowite.wstaw(c, 2);
    c = &cal4;
    calkowite.wstaw(c, 1);
    calkowite.usun();
    calkowite.usun(0);
    ile = calkowite.ile_elementów();
    cocal = calkowite.co_na(0);
    cout << "Tablica calkowite ma " << ile << " elementów." << endl;
    cout << "Tablica calkowite ma " << cocal << " na pozycji 0" << endl;
    przecinkowe.wstaw(p);
    p = &przec1;
    przecinkowe.wstaw(p);
    p = &przec2;
    przecinkowe.wstaw(p);
    p = &przec3;
    przecinkowe.wstaw(p);
    p = &przec4;
    przecinkowe.wstaw(p);
    p = &przec5;
    przecinkowe.wstaw(p, 2);
    przecinkowe.usun();
    przecinkowe.usun(3);
    ile = przecinkowe.ile_elementów();
    coprze = przecinkowe.co_na(3);
    cout << "Tablica przecinkowe ma " << ile << " elementów." << endl;
    cout << "Tablica przecinkowe ma " << coprze << " na pozycji 3" << endl;
    znaki.usun();
    znaki.usun();
    znaki.wstaw(z);
    litera = 'f';
    znaki.wstaw(z, 4);
    znaki.usun(3);
    ile = znaki.ile_elementów();
    coznak = znaki.co_na(3);
    cout << "Tablica znaki ma " << ile << " elementów." << endl;
    cout << "Tablica znaki ma " << coznak << " na pozycji 3" << endl;
    system("pause");
    return 0;
}