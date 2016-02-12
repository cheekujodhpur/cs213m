/*
 * Assignment 3, Solution 1
 * Author: Kumar Ayush
 */

#include "mfile.hpp"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
    string input_filename;
    cin >> input_filename;
    int line_size;
    cin >> line_size; 

    MFile the_file;
    if(the_file.init(input_filename,line_size))
    {
        cout << "Error in reading file.";
        return 1;
    }

    string the_line;
    unordered_map<string,int> clerk;
    int number_of_unique_lines = 0;
    do
    {
        the_line = the_file.readNext();
        if(clerk.count(the_line)>0)
            clerk[the_line]++;
        else
        {
            clerk[the_line]=1;
            number_of_unique_lines++;
        }
    }while(the_line!="");

    if(the_file.close())
    {
        cout << "Could not close properly" << endl;
        return 1;
    }

    cout << number_of_unique_lines-1 << endl;
    return 0;
}
