#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tests[5];
    tests[0] = "ab";
    tests[1] = "abb";
    tests[2] = "aabb";
    tests[3] = "abbb";
    tests[4] = "b";

    string expected[5];
    expected[0] = "ACCEPT";
    expected[1] = "ACCEPT";
    expected[2] = "ACCEPT";
    expected[3] = "ACCEPT";
    expected[4] = "REJECT";

    cout << "DFA for RE: ab* + [a*(b+)* + ab]+" << endl;
    cout << "Alphabet  : {a, b}" << endl;
    cout << "States    : A(start), B(accept), C, D(accept), E(accept), DEAD" << endl;
    cout << "  " << endl;

    int passed = 0;

    for (int t = 0; t < 5; t++)
    {
        string input = tests[t];
        int state = 0;

        cout << endl;
        cout << "Test " << t + 1 << " : " << input << endl;
        cout << "Start state : A" << endl;

        for (int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            int next = 5;

            switch (state)
            {
                case 0:
                    switch (c)
                    {
                        case 'a': next = 1; break;
                        case 'b': next = 5; break;
                    }
                    break;

                case 1:
                    switch (c)
                    {
                        case 'a': next = 2; break;
                        case 'b': next = 3; break;
                    }
                    break;

                case 2:
                    switch (c)
                    {
                        case 'a': next = 1; break;
                        case 'b': next = 4; break;
                    }
                    break;

                case 3:
                    switch (c)
                    {
                        case 'a': next = 1; break;
                        case 'b': next = 3; break;
                    }
                    break;

                case 4:
                    switch (c)
                    {
                        case 'a': next = 1; break;
                        case 'b': next = 4; break;
                    }
                    break;

                case 5:
                    next = 5;
                    break;
            }

            string sName = "";
            switch (state)
            {
                case 0: sName = "A";    break;
                case 1: sName = "B";    break;
                case 2: sName = "C";    break;
                case 3: sName = "D";    break;
                case 4: sName = "E";    break;
                case 5: sName = "DEAD"; break;
            }

            string nName = "";
            switch (next)
            {
                case 0: nName = "A";    break;
                case 1: nName = "B";    break;
                case 2: nName = "C";    break;
                case 3: nName = "D";    break;
                case 4: nName = "E";    break;
                case 5: nName = "DEAD"; break;
            }

            cout << "Read '" << c << "' : " << sName << " --> " << nName << endl;

            state = next;
        }

        string finalName = "";
        switch (state)
        {
            case 0: finalName = "A";          break;
            case 1: finalName = "B (accept)"; break;
            case 2: finalName = "C";          break;
            case 3: finalName = "D (accept)"; break;
            case 4: finalName = "E (accept)"; break;
            case 5: finalName = "DEAD";       break;
        }

        cout << "Final state : " << finalName << endl;

        string result = "REJECT";
        if (state == 1 || state == 3 || state == 4)
        {
            result = "ACCEPT";
        }

        cout << "Result      : " << result << endl;
        cout << "Expected    : " << expected[t] << endl;

        if (result == expected[t])
        {
            cout << "test result     : PASS" << endl;
            passed++;
        }
        else
        {
            cout << "test result     : FAIL" << endl;
        }

        cout << "-------------------------------------------------" << endl;
    }

    cout << endl;
    cout << "Total Passed : " << passed << " / 5" << endl;

    return 0;
}
