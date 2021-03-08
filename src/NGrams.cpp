#include <iostream>
#include "console.h"
#include "ginteractors.h" // for GWindow
#include "gwindow.h"
#include <fstream>
#include <iostream>// for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "queue.h"
#include "stack.h"
#include <map>
#include <set>
#include "foreach.h"

using namespace std;
const string ERROR_MSG="Can't open the file specified, please try again: ";
const string PROMPT_FILE_MSG="Grid input file name? ";
const string N_NGRAM_CHOICEDLG="Enter the number of words in NGRAM: ";
string promptUserFile(ifstream &infile, string prompt);
void createMap(map<Queue<string>, vector<string>> &map,ifstream &infile, int n_words);
//void readFileContent(ifstream &infile, );
int main() {

    int numb=getInteger(N_NGRAM_CHOICEDLG);
    //Map<Queue<string>, string> _map ;
    map<Queue<string>, vector<string>> _map ;



    return 0;
}

string promptUserFile(ifstream &infile, string prompt){
    while (true) {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail()) return filename;
        infile.clear();
        cout<<ERROR_MSG <<endl;
        if (prompt=="") prompt = PROMPT_FILE_MSG;

    }}
void createMap(map<Queue<string>, vector<string>> &map,ifstream &infile, int n_words){
    string word;
    string collocation=word;
    vector<string> vec;
    Queue<string> line;
    Queue<string> que;
    if (infile.is_open()){
            while (infile.good()){
                if (!infile.eof()){
                    infile >> word;
                    line.add(word);
                    if (line.size()==n_words){
                        que=line;
                    }
                    if (line.size()>n_words){
                        line.dequeue();
                        if(map.find(que)!=map.end()){
                            vec.push_back(line.back());
                            map.insert({que,vec});
                        } else {map[que].push_back(line.back());}
                    }
    } else {
                    infile.clear();
                    infile.seekg (0, ios::beg);
                while (line.size()!=n_words){
                    infile >> word;
                    line.add(word);

                }
                infile >>word;
                vec.push_back(word);
                map.insert({line,vec});
                break;

                }}
            }}




