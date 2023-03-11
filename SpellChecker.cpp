#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

// Function to load dictionary of correctly spelled words into memory
unordered_set<string> loadDictionary(const string& filename) {
    unordered_set<string> dictionary;
    ifstream file(filename);

    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            dictionary.insert(word);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return dictionary;
}

// Function to check if a word is spelled correctly
bool checkSpelling(const string& word, const unordered_set<string>& dictionary) {
    return dictionary.find(word) != dictionary.end();
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(const string& word, const unordered_set<string>& dictionary) {
    cout << "Did you mean:  ";
    for (const string& s : dictionary) {
        if (abs(int(s.size() - word.size())) > 1) {
            continue;
        }
        int count = 0;
        for (int i = 0, j = 0; i < s.size() && j < word.size(); ++i, ++j) {
            if (s[i] != word[j]) {
                ++count;
                if (count > 1) {
                    break;
                }
                if (s.size() > word.size()) {
                    --j;
                } else {
                    --i;
                }
            }
        }
        if (count == 1) {
            cout << s << endl;
        }
    }
}


//print function for unordered_set<string> 
void print(unordered_set<string> const &s)
{
    copy(s.begin(),
            s.end(),
            ostream_iterator<string>(cout, " "));
}


int main() {
    // Load dictionary into memory
    unordered_set<string> dictionary = loadDictionary("dictionary.txt");
    //print(dictionary);
    
    // Spell check text
    string line;
    while (getline(cin, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        string word;
        for (char c : line) {
            if (isalpha(c)) {
                word.push_back(c);
            } else {
                if (!word.empty() && !checkSpelling(word, dictionary)) {
                    cout << "Misspelled word: " << word << endl;
                    suggestCorrections(word, dictionary);
                }
                word.clear();
            }

        }
        if (!word.empty() && !checkSpelling(word, dictionary)) {
            cout << "Misspelled word: " << word << endl;
            suggestCorrections(word, dictionary);
        }
        
    }

    return 0;
}

