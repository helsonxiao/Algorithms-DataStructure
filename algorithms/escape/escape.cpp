#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

struct dfs
{
    int length;
    int time;
    int M;
    dfs(int length, int time, int M)
    {
        this->length = length, this->time = time, this->M = M;
    }
};

int main()
{
    ifstream fin("escape.in");
    ofstream fout("escape.out");
    int M, S, T;
    fin >> M >> S >> T;

    dfs d(0, 0, M);
    stack<dfs> s;
    s.push(d);

    int length = 0, time = T + 1;
    bool flag = false;
    int count = 0;
    while (!s.empty())
    {
        dfs d1 = s.top();
        s.pop();

        if (d1.time > T)
            continue;

        if (d1.length > S)
        {
            time = min(time, d1.time);
            flag = true;
        }
        else
            length = max(length, d1.length);

        d1.time++;

        if (d1.M < 10)
        {
            d1.M += 4;
            s.push(d1);
            d1.M -= 4;
            d1.length += 17;
            s.push(d1);
        }
        else
        {
            d1.length += 60;
            d1.M -= 10;
            s.push(d1);
        }
        
        count++;
    }

    if (!flag)
        fout << "No" << endl << length;
    else
        fout << "Yes" << endl << time;
}