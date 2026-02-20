#include<bits/stdc++.h>
using namespace std;
void generate(int n, vector<string> &res, string curr, int countOpen, int countClosed1)
{
    if (countOpen == countClosed && curr.size() == 2 * n)
    {
        res.push_back(curr);
        return;
    }
    if (countOpen == countClosed)
    {
        generate(n, res, curr + '(', countOpen + 1, countClosed);
    }
    else
    {
        if (countOpen == n)
        {
            generate(n, res, curr + ')', countOpen, countClosed + 1);
        }
        else
        {
            generate(n, res, curr + '(', countOpen + 1, countClosed);
            generate(n, res, curr + ')', countOpen, countClosed + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

}