#include "functions.h"

void Read_File(ifstream& in, map<string, vector<int>>& zodziai)
{
    string zodis;
    string line;
    int line_number = 1;

    while (getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find_first_of("- – ")) != string::npos) {
            string zodis = line.substr(0, pos);
            zodis.erase(remove_if(zodis.begin(), zodis.end(), [](char c) { return ispunct(c) || isdigit(c); }), zodis.end());
            if (!zodis.empty()) {
                zodziai[zodis].push_back(line_number);
            }
            line = line.substr(pos + 1);
        }
        if (!line.empty()) {
            line.erase(remove_if(line.begin(), line.end(), [](char c) { return ispunct(c) || isdigit(c); }), line.end());
            zodziai[line].push_back(line_number);
        }
        line_number++;
    }
}


void Counter(map<string, vector<int>>& zodziai)
{
    ofstream out ("counter.txt");
    for (const auto& pair : zodziai) {
        out << pair.first << ": " << pair.second.size() << "\n";
    }
}

void WriteCrossReference(const map<string, vector<int>>& zodziai)
{
    ofstream out("cross_reference.txt");
    for (const auto& pair : zodziai) {
        if (pair.second.size() > 1) {
            out << pair.first << ": ";
            for (int line : pair.second) {
                out << line << " ";
            }
            out << "\n";
        }
    }
}

void FindURLs(ifstream& in, set<string>& urls)
{
    string word;
    string line;
    vector<string> domains = {".com", ".net", ".org", ".lt", ".edu", ".gov"};

    while (getline(in, line)) {
        istringstream iss(line);
        while (iss >> word) {
            for (const string& tld : domains) {
                if (word.find(tld) != string::npos) {
                    urls.insert(word);
                    break;
                }
            }
        }
    }

    ofstream out("urls.txt");
    for(const string& url : urls) {
        out << url << "\n";
    }
}