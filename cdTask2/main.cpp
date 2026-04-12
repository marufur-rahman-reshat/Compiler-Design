/*#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    string word;
    while (file >> word)
    {
        cout << word << " ";
    }
    file.close();
    return 0;
}
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("data.txt");
    string line;
    int ln = 1, i, n;
    char c;
    string w, num, s ,op;


    while (getline(file, line))
    {
        cout << "\nLine " << ln << ": " << line << endl;
        cout << "--------------------------" << endl;
        ln++;

        n = line.size();
        i = 0;

        while (i < n)
        {
            c = line[i];

            if (c == ' ' || c == '\t')
                { i++; continue; }
            if (c == '"')
            {
                s = "\""; i++;
                while (i < n && line[i] != '"') { s += line[i]; i++; }
                s += "\""; i++;
                cout << "String     : " << s << endl;
                continue;
            }
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_')
            {
                w = "";
                while (i < n && (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z' || line[i] >= '0' && line[i] <= '9' || line[i] == '_'))
                { w += line[i]; i++; }

                if (w=="int" || w=="float" || w=="char" || w=="double" || w=="return" ||
                    w=="if"  || w=="else"  || w=="while"|| w=="for"   || w=="void"   ||
                    w=="cout"|| w=="cin"   || w=="main")
                    cout << "Keyword    : " << w << endl;
                else
                    cout << "Identifier : " << w << endl;
                continue;
            }

            if (c >= '0' && c <= '9')
            {
                num = "";
                while (i < n && line[i] >= '0' && line[i] <= '9') { num += line[i]; i++; }
                cout << "Constant   : " << num << endl;
                continue;
            }

            if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>')
            {
                op = ""; op += c; i++;
                if (i < n && (line[i] == '=' || line[i] == '<' || line[i] == '>')) { op += line[i]; i++; }
                cout << "Operator   : " << op << endl;
                continue;
            }

            if (c == '(' || c == ')' || c == '{' || c == '}' || c == ';' || c == ',')
            {
                cout << "Punctuation: " << c << endl;
                i++; continue;
            }

            cout << "Unknown    : " << c << endl;
            i++;
        }
    }

    file.close();
    return 0;
}
