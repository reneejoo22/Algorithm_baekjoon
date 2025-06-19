#include <iostream>

#include <string>

using namespace std;

 

int main()

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        string s;

        cin >> s;

        int A = 0, C = 0;

        for (int i = 0; i <

s.size(); ++i)

                 if (i == 0 || s[i - 1] == '|') 

                 {

                         if (s[i] == 'A' || s[i] == 'D' || s[i] == 'E')

                                 A++;

                         if (s[i] == 'C' || s[i] == 'F' || s[i] == 'G')

                                 C++;

                 }

 

        if (A == C)

        {

                 A

+= (s[(int)s.size() - 1] == 'A');

                 C

+= (s[(int)s.size() - 1] == 'C');

        }

        if (A > C)

                 cout

<< "A-minor\n";

        else

                 cout

<< "C-major\n";

        return 0;

}

