#include "functions.h"

int main()
{
    ifstream in("duomenys.txt");
    if (!in) {
        cout << "Nerastas failas\n";
        return 1;
    }

    set<string> urls;
    map<string, vector<int>> zodziai;

    Read_File(in, zodziai);
    Counter(zodziai);
    in.clear();
    in.seekg(0);

    WriteCrossReference(zodziai);
    FindURLs(in, urls);

    return 0;
}