#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("escape.in");
    ofstream fout("escape.out");
    int M, S, T;
    fin >> M >> S >> T;
    vector<int> times(T + 1);
    times[0] = 0;

    int i = 0, result = 0;

    for (i = 1; i < T + 1; i++)
        if (M >= 10)
            times[i] = times[i - 1] + 60, M -= 10;
        else
            times[i] = times[i - 1], M += 4;

    for (i = 1; i < T + 1; i++)
    {
        if (times[i - 1] + 17 > times[i])
            times[i] = times[i - 1] + 17;

        if (times[i] >= S)
        {
            result = i;
            break;
        }
    }

    if (result)
        fout << "Yes" << endl << result;
    else
        fout << "No" << endl << times[i - 1];
}