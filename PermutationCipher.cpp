#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

string open_textfile(string filename);
void save_textfile(string text, string filename);
string permutation_cipher(vector<vector<char>>message, vector<int> permutation, int n);

int main()
{
    string message, filename, finaltext;
    int n;
    vector<int>permutation;

    cout<<"Textfile name (Without extension): ";
    cin>>filename;
    message = open_textfile(filename + ".txt");

    if(message.substr(0, 23) == "Error with the textfile")
    {
        cout<<message;
        return 0;
    }

    cout<<"\nWrite a permutation: (a b c...): ";
    while(cin>>n)
    {
        permutation.push_back(n);
        if(cin.peek() == '\n')
            break;
    }

    if(message.length()%permutation.size() != 0)
        for(int i=0; i<message.length()%permutation.size(); i++)
            message += "X";
    
    vector<vector<char>>blocks(message.length()/permutation.size(), vector<char>(permutation.size()));
    for(int i=0; i<message.length()/permutation.size(); i++)
        for(int j=0; j<permutation.size(); j++)
            blocks[i][j] = message[i*permutation.size() + j];

    finaltext = permutation_cipher(blocks, permutation, message.length());
    save_textfile(finaltext, filename);

    return 0;
}

string open_textfile(string filename)
{
    ifstream textfile(filename);
    if(!textfile.is_open())
        return "Error with the textfile " + filename;
    
    stringstream buffer;

    buffer<<textfile.rdbuf();
    textfile.close();

    string content = buffer.str(), message = "";
    for(int i=0; i<content.length(); i++)
    {
        unsigned char c = content[i];
        if(c>=32 && c<=126)
            message += content[i];
    }

    return message;
}

void save_textfile(string text, string filename)
{
    ofstream textfile(filename + ".pi");
    if(!textfile.is_open())
    {
        cout<<"Error with the textfile " + filename + ".pi";
        return;
    }

    textfile<<text;
    textfile.close();
    cout<<"The textfile has been saved as " + filename + ".pi";

    return;
}

string permutation_cipher(vector<vector<char>>message, vector<int> permutation, int n)
{
    int k;
    k = n / permutation.size();
    string finalText = "";

    for(int i=0; i<k; i++)
        for(int j=0; j<permutation.size(); j++)
            finalText += message[i][permutation[j]-1];

    return finalText;
}