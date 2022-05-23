#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Timer.h"

using namespace std;

int main()
{


    int x = 10;
    int y = 20;
    int* Ptx = &x;
    int* Pty = &y;

    cout << *Ptx << " " << Ptx << " " << *Pty << " " << Pty << endl;
    swap(*Ptx, *Pty);
    cout << *Ptx << " " << Ptx << " " << *Pty << " " << Pty << endl;



    vector<int> Vec;
    for (size_t i = 0; i < 10; i++)
    {
        x = rand();
        int* ptr = new int{ x };
        Vec.push_back(*ptr);
    }

    for (int x : Vec) {

        cout << x << "; ";

    }
    cout << endl;

    sort(Vec.begin(), Vec.end());

    for (int x : Vec) {

        cout << x << "; ";

    }
    cout << endl;



    char buff;
    vector<char> vec;
    ifstream BookOpen("Some book.txt");
    if (BookOpen.is_open()) {
        while (BookOpen >> buff) {
            vec.push_back(buff);
        }

    }
    BookOpen.close();

    vector<char>::iterator it;



    string alpha = "AEIOUYaeiouy";


    Timer timer("For+ count");
    int countLetters{ 0 };
    for (size_t i = 0; i < alpha.size(); i++)
    {
        size_t a_count = count(vec.begin(), vec.end(), alpha[i]);
        countLetters += a_count;
    }
    cout << "For + count :" << countLetters << endl;
    timer.print();


    Timer timer1("for + find");
    int foundLetters{ 0 };
    for (it = vec.begin(); it != vec.end(); it++) {

        auto FindRes = find(alpha.begin(), alpha.end(), *it);
        if (FindRes == alpha.end()) {
            //этот блок кода необходим, чтобы не выскакивало исключение.Но, на деле, мне кажется, это неправильно.
        }
        else {
            foundLetters++;
        }
    }
    cout << "for + find :" << foundLetters << endl;
    timer1.print();

    Timer timer2("For + For");
    int ForFor{ 0 };
    for (it = vec.begin(); it != vec.end(); it++) {
        for (size_t i = 0; i < alpha.size(); i++) {
            if (*it == alpha[i]) {
                ForFor++;
            }
        }
    }
    cout << "For + For :" << ForFor << endl;
    timer2.print();



}

