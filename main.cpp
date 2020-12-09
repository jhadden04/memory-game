#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>  // these are just importing libraries to run the program
#include <time.h>
#include <stdio.h>
#include <list>
using namespace std;

int random()
{
    unsigned long j;
    srand( (unsigned)time(NULL) );

    for( j = 0; j < 100; ++j )
    {
        int n;

        /* skip rand() readings that would make n%6 non-uniformly distributed
          (assuming rand() itself is uniformly distributed from 0 to RAND_MAX) */
        while( ( n = rand() ) > RAND_MAX - (RAND_MAX-5)%6 )
        { /* bad value retrieved so get next one */ }

        cout << n % 9 + 1;
        return (n % 9 + 1);  // this is a sudo-random number generator, that I found on stackoverflow. I'm
    }                        // not fully sure how it works, but I think it gets random numbers by accessing time
                             // I modified it so that it only returns one number

}

int memorygame()
{
    std::list<int> numbers;    
    std::list<int>::iterator it;
    it = numbers.begin();  // this just introduces the list that stores the numbers
    int score = 0;
    while (true)
    {    string x = "";
         numbers.insert(it,random());
         for (auto v : numbers)
            {

               string b = to_string(v);
               x.append(b);
            }
         cout << "" <<endl;
         cout << "Type all the numbers so far: " ;
         string y;
         cin >> y;

         if (y == x)
            {
             for (int w = 0; w < 100; w++){
                cout << "no peeking" << endl;
             }
             cout << "you got it right" << endl;
             score++;
             cout << "your score is: ";
             cout << score << endl;

             continue;

            }
         else {
            cout << "you got it wrong" << endl;
            cout << "it was " + x << endl;
            break;
            }

    }
}

int main()
{
    memorygame();
}
