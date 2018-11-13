#include "json.hpp"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

void appendToFile(const string &fileName, const string &data);
void vider(const string & fileName);
json readFile(const string &fileName);
string getMakefileHeader(const json &data);
string getMakefileDependance(const json &data);

int main()
{
    json j_data = readFile("data.json");
    string s_data = "";
    s_data += getMakefileHeader(j_data);
    vider("test");
    appendToFile("test",s_data);
    return 0;
}

string getMakefileDependance(const json &data){
    
}

string getMakefileHeader(const json &data){
    string res = "";
    res += "CC = " + data["CC"].dump() + "\n";
    res += "CPP_FLAGS = " + data["CPP_FLAGS"].dump() + "\n";
    res += "INCLUDE_DIR = " + data["INCLUDE_DIR"].dump() + "\n";
    res += "INCLUDE_LIB = " + data["INCLUDE_LIB"].dump() + "\n\n";
    return res;
}

void appendToFile(const string &fileName, const string &data){
    ofstream file (fileName, std::ofstream::out | std::ofstream::app);
    cerr<<"appending to "<<fileName<<"...\n";
    if(!file.is_open()){
        cerr<<"\n failed: please check the path of the file."<<endl;
        return;
    }
    file<<data;
    file.close();
    cerr<<" sucess\n";
}

json readFile(const string &fileName){
    json data;
    ifstream file (fileName, std::ifstream::in);
    cerr<<"reading from "<<fileName<<"...";
    if(!file.is_open())
    {
        cerr<<"\n failed: please check the path of the file."<<endl;
        return data;
    }
    file>>data;
    cerr<<"\n sucess\n";
    file.close();
    return data;
}
void vider(const string & fileName){
    ofstream file (fileName, std::ofstream::out);
    if(!file.is_open()){
        cerr<<fileName<<": le fichier n'existe pas \n";
        return;
    }
    cerr<<fileName<<": vider avec sucess\n";
}