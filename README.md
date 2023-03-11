# SpellSchecker
An implementation of a spell checker program in C++:

In this implementation, the loadDictionary() function loads a dictionary of correctly spelled words from a file into an unordered_set. The checkSpelling() function checks if a given word is spelled correctly by checking if it is in the unordered_set. The suggestCorrections() function suggests corrections for a misspelled word by comparing it to every word in the unordered_set and printing words that are one edit away from it.

The main() function reads in lines of text from standard input, converts them to lowercase, and checks the spelling of each word in the line using the checkSpelling() function. If a word is misspelled, the suggestCorrections() function is called to suggest corrections for it.

Note that this is a simple implementation and there are many ways to improve its performance and accuracy.
