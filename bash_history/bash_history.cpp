#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    // TAKING INPUT
    int num_cmnds, pos;
    string str1, str2, curr_dir = "/", key;
    map<string, set<string>> dir_file_pair;
    set<string> value;

    cin >> num_cmnds;

    // SOLVING PROBLEM
    for (int i = 0; i <= num_cmnds; i++) // iterating one more time than the number of input commands "num_cmnds" but taking only "num_cmnds" inputs
    {
        if (i != num_cmnds) // adding one more iteration for the last "filename" of a directory
        {
            cin >> str1 >> str2;
        }
        if (str1 == "ls") // checking if the input command is of the form "ls <filename>"
        {
            if (dir_file_pair[curr_dir].find(str2) == dir_file_pair[curr_dir].end()) // checking if the file is already present in the map
            {
                dir_file_pair[curr_dir].insert(str2); // inserting the filename in the set (value part of the map)
            }
        }
        else if (str1 == "cd" && str2 == "..") // checking if the input command is of the form "cd .."
        {
            dir_file_pair[curr_dir].insert(""); // initializing an empty string value for the curent path just in case if it has no files
            pos = curr_dir.size() - 1;          // finding the postion of the last occurence of "/" in the string curr_dir due to the extra "/"
            if (curr_dir != "/")                // checking if the current path is not the root directory
            {
                pos = curr_dir.rfind("/", pos - 1); // finding the postion of the second last occurence of "/" in the string curr_dir
                curr_dir.erase(pos + 1);            // erasing the part of the string curr_dir after the second last occurence of "/" to "go back" one step
            }
        }
        else // code section if the input is of the form "cd <directoryname>"
        {
            dir_file_pair[curr_dir].insert(""); // initializing an empty string value for the curent path just in case if it has no files
            curr_dir += str2 + "/";             // changing the current path (going iside a directory or subdirectory)
        }
    }

    // PRESENTING RESULTS
    for (auto pair : dir_file_pair) // iterating over the key-value map dir_file_pair
    {
        key = pair.first;    // obtaining the key (here, path name) of the map
        value = pair.second; // obtaining the value (here, set of filenames in that path (key)) of the map
        if (key != "/")      // checking if the path is not the root directory (i.e., "/")
        {
            key.erase(key.size() - 1); // removing the extra "/" at the end of a pathname
        }
        cout << key;                                                 // printing out the pathname
        for (auto iter = value.begin(); iter != value.end(); iter++) // iterating over the set (value part of the map)
        {
            if (*iter != "") // checking if the file name is not empty
            {
                cout << " "; // adding a space between the filenames
            }
            cout << *iter; // printing out the filename
        }
        cout << endl;
    }

    return 0;
}