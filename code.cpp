#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<unordered_set>
#include<chrono>
using namespace std::chrono;
using namespace std;


static bool mycomparator( const string &a, const string &b){
 if(a.size()==b.size())return a>b;
 else return a.size()>b.size();
}
int main(){
    ifstream inputFile("INPUT.txt");
    ofstream outputFile;
    outputFile.open("OUTPUT.txt");

     if (!inputFile.is_open()) {
        cout<< "Could not open the file.\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    string line;
    vector<string>str;
    while (getline(inputFile, line)) {
        str.push_back(line);
    }


    auto time1=high_resolution_clock::now();
    unordered_set<string>s;
    for(int i=0;i<str.size();i++){
        s.insert(str[i]);
    }
    sort(str.begin(),str.end(),mycomparator);

    string longest="",sec_longest="";
    vector<bool>vis(1001);
    for(int i=0;i<str.size();i++){
        int size=str[i].size();
        for(int it=0;it<size;it++)vis[it]=false;

        for(int j=0;j<size;j++){
            for(int k=0;k<=j;k++){
                string temp=str[i].substr(k,j-k+1);
                if(s.find(temp)!=s.end()){
                    if(k==0 && j!=size-1){
                        vis[j]=true;
                        break;
                    }
                    else if(k>0 && vis[k-1]){
                        vis[j]=true;
                        break;
                    }
                }
            }
        }

        if(vis[size-1]){
            if(longest.size()<size){
                sec_longest=longest;
                longest=str[i];
            }
            else if(sec_longest.size()<size){
                sec_longest=str[i];
            }
        }
    }

    auto time2=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(time2-time1);
    outputFile<<"longest compounded word is "<<longest<<endl;
    outputFile<<"second longest compounded word is "<<sec_longest<<endl;
    outputFile<<"Time taken to process input file :"<<duration.count()<<" milliseconds";
    outputFile.close();
}
