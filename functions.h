#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

void Read_File(ifstream& in, map<string, vector<int>>& zodziai);

void Counter(map<string, vector<int>>& zodziai);

void WriteCrossReference(const map<string, vector<int>>& zodziai);

void FindURLs(ifstream& in, set<string>& urls);