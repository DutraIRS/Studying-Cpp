#include <iostream>

using namespace std;

/*
For simplicity's sake, we will treat doubly linked list as DLL.

Suppose we want to work with a structure a little different from integers.
We have a weird language composed of 2 types of letters: vowels "A", "U", "Y", and consonants
"B", "J", "S", "R" and "T". A word in this language is any sequence of 2 to 8 letters alternating
between vowels and consonants (for example, "ABUJY", "TURA" or "SURATURY").
Consider a DLL to store words in this language, we will use the following node for the
problems below:

struct Node
{
    Node* prev;
    Node* next;
    char letter;
};

Problem 1: (Useful functions) Implement the following functions:

(a) (is_valid) Given a word, tell if it is valid (that is, follows the rules of the weird language).
(b) (insert) Given a word and a DLL, add the new word at the end of the list if it is valid, or
print an error if it is not;
(c) (find) Given a word and a DLL, check if the word is in the list or not;
(d) (delete) Given a word and a DLL, delete the word from the list;
(e) (print) Given a DLL, print the list element by element;
(f) (comparison) Given two words check if one precedes the other in alphabetical order
(being A > U > Y > B > J > S > R > T the order of consideration).


Problem 2: (sort) In the previous list we implemented Bubble sort, which has a complexity
O(n²). Now, implement another sort algorithm, Merge sort, which has complexity
O(n log n), for a DLL with the words of the language we introduced at the beginning.

Problem 3: (there and back again) Make a function that first traverses the DLL from the
head of the list, finding the word that repeats the most and the number of repetitions. Then,
with this word, you must go back from the tail, removing the occurrences of this word from the
DLL until there are no more occurrences (note that it is until there are no occurrences, remember
the counter).

Problem 4: (comparison) In question 2 we mentioned that Merge sort has a lower complexity,
but how does that interfere? First adapt the Bubble sort from the previous list to work with a
DLL that stores words of the weird language. Then create some unordered DLLs with different
sizes (like 100, 1000, 10000) and check with both sorts the execution times. Make sure that the
words being inserted in the lists are as random as possible, having a variable number of digits
(between 4 to 7 letters, for example). Leave the results commented in the code, with execution time.
*/

struct Letter
{
    Letter* prev;
    Letter* next;
    char letter;
};

struct Word
{
    Word* prev;
    Word* next;
    Letter* head;
};

bool isValidVowel(Letter* letter)
{
    char validVowels[] = {'A', 'U', 'Y'};
    int vowelsCount = sizeof(validVowels) / sizeof(char);

    for (int i = 0; i < vowelsCount; i++)
    {
        if (letter->letter == validVowels[i])
        {
            return true;
        }
    }

    return false;
}

bool isValidConsonant(Letter* letter)
{
    char validConsonants[] = {'B', 'J', 'S', 'R', 'T'};
    int consonantsCount = sizeof(validConsonants) / sizeof(char);

    for (int i = 0; i < consonantsCount; i++)
    {
        if (letter->letter == validConsonants[i])
        {
            return true;
        }
    }

    return false;
}

int getWordSize(Word* word)
{
    int size = 0;
    Letter* current = word->head;

    while (current != nullptr)
    {
        size++;
        current = current->next;
    }

    return size;
}

int getListSize(Word* wordList)
{
    int size = 0;

    while (wordList != nullptr)
    {
        size++;
        wordList = wordList->next;
    }

    return size;
}

bool isValid(Word* word)
{
    if (word == nullptr)
    {   
        cout << "Word is empty!" << endl;
        return false;
    }

    Letter* current = word->head;
    int wordSize = getWordSize(word);

    if (wordSize < 2 || wordSize > 8)
    {
        return false;
    }
    else if (isValidVowel(current))
    {
        current = current->next;
        int posCounter = 1;

        while (current != nullptr)
        {
            if (posCounter % 2 != 0 && !isValidConsonant(current))
            {
                return false;
            }
            else if (posCounter % 2 == 0 && !isValidVowel(current))
            {
                return false;
            }

            posCounter++;
            current = current->next;
        }

        return true;
    }
    else if (isValidConsonant(current))
    {
        current = current->next;
        int posCounter = 1;

        while (current != nullptr)
        {
            if (posCounter % 2 != 0 && !isValidVowel(current))
            {
                return false;
            }
            else if (posCounter % 2 == 0 && !isValidConsonant(current))
            {
                return false;
            }

            posCounter++;
            current = current->next;
        }

        return true;
    }
    else 
    {
        return false;
    }
}

void insertLetter(Letter** head, Letter* letter)
{
    if (*head == nullptr)
    {
        *head = letter;
    }
    else
    {
        Letter* current = *head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = letter;
        letter->prev = current;
    }
}

void insertWord(Word** wordList, Word* word)
{
    if (!isValid(word))
    {
        cout << "Invalid word!" << endl;
        return;
    }

    if (*wordList == nullptr)
    {
        *wordList = word;
    }
    else
    {
        Word* current = (*wordList);

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = word;
        word->prev = current;
    }
}

void printWord(Word* word)
{
    Letter* current = word->head;

    while (current != nullptr)
    {
        cout << current->letter;
        current = current->next;
    }

    cout << endl;
}

void printList(Word* wordList)
{
    if (wordList == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List: \n{";

    while (wordList != nullptr)
    {
        printWord(wordList);
        wordList = wordList->next;
    }

    cout << "}" << endl;
}

bool isSame(Word* word1, Word* word2)
{
    int iSize1 = getWordSize(word1);
    int iSize2 = getWordSize(word2);

    if (iSize1 != iSize2)
    {
        return false;
    }
    else
    {
        Letter* current1 = word1->head;
        Letter* current2 = word2->head;

        while (current1 != nullptr)
        {
            if (current1->letter != current2->letter)
            {
                return false;
            }

            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }
}

bool find(Word* wordList, Word* word)
{
    if (!isValid(word))
    {
        cout << "Invalid word!" << endl;
        return false;
    }
    else if (wordList == nullptr)
    {
        cout << "List is empty!" << endl;
        return false;
    }
    else
    {
        while (wordList != nullptr)
        {
            if (isSame(wordList, word))
            {
                return true;
            }

            wordList = wordList->next;
        }

        return false;
    }
}

void deleteWord(Word** wordList, Word* word)
{
    // deletes first occurence of word
   if ((*wordList) == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else if (!find((*wordList), word))
    {
        cout << "Word not found!" << endl;
        return;
    }
    else
    {
        Word* temp = (*wordList);
        while (temp != nullptr)
        {
            if (isSame(temp, word))
            {
                if (temp->prev != nullptr)
                {
                    if (temp->next != nullptr)
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                    else
                    {
                        temp->prev->next = nullptr;
                    }
                }
                else
                {
                    if (temp->next != nullptr)
                    {
                        temp->next->prev = nullptr;
                        (*wordList) = temp->next;
                    }
                    else
                    {
                        (*wordList) = nullptr;
                        return;
                    }
                }

                // decided not to delete in order to reuse the word
                temp->prev = nullptr;
                temp->next = nullptr;

                return;
            }
            temp = temp->next;
        }
    }
}

void deleteAt(Word** wordList, int idx)
{
    int iListSize = getListSize((*wordList));
    
    if (idx < 0 || idx >= iListSize)
    {
        cout << "Invalid index!" << endl;
        return;
    }
    else if ((*wordList) == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else if (idx == 0)
    {
        Word* temp = (*wordList);
        (*wordList) = (*wordList)->next;
        temp->next = nullptr;
        (*wordList)->prev = nullptr;
        return;
    }
    else if (idx == iListSize - 1)
    {
        Word* temp = (*wordList);
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        temp->prev = nullptr;
        return;
    }
    else
    {
        Word* temp = (*wordList);
        
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->prev = nullptr;
        temp->next = nullptr;
        return;
    }
}

bool comparison(Word* word1, Word* word2)
{   
    if (!isValid(word1) || !isValid(word2))
    {
        cout << "Invalid word!" << endl;
        return false;
    }

    int iSize1 = getWordSize(word1);
    int iSize2 = getWordSize(word2);

    int iArrScores1[iSize1];
    int iArrScores2[iSize2];

    Letter* current1 = word1->head;

    for (int i = 0; i < iSize1; i++)
    {
        if (current1->letter == 'A')
        {
            iArrScores1[i] = 1;
        }
        else if (current1->letter == 'U')
        {
            iArrScores1[i] = 2;
        }
        else if (current1->letter == 'Y')
        {
            iArrScores1[i] = 3;
        }
        else if (current1->letter == 'B')
        {
            iArrScores1[i] = 4;
        }
        else if (current1->letter == 'J')
        {
            iArrScores1[i] = 5;
        }
        else if (current1->letter == 'S')
        {
            iArrScores1[i] = 6;
        }
        else if (current1->letter == 'R')
        {
            iArrScores1[i] = 7;
        }
        else if (current1->letter == 'T')
        {
            iArrScores1[i] = 8;
        }

        current1 = current1->next;
    }

    Letter* current2 = word2->head;

    for (int i = 0; i < iSize2; i++)
    {
        if (current2->letter == 'A')
        {
            iArrScores2[i] = 1;
        }
        else if (current2->letter == 'U')
        {
            iArrScores2[i] = 2;
        }
        else if (current2->letter == 'Y')
        {
            iArrScores2[i] = 3;
        }
        else if (current2->letter == 'B')
        {
            iArrScores2[i] = 4;
        }
        else if (current2->letter == 'J')
        {
            iArrScores2[i] = 5;
        }
        else if (current2->letter == 'S')
        {
            iArrScores2[i] = 6;
        }
        else if (current2->letter == 'R')
        {
            iArrScores2[i] = 7;
        }
        else if (current2->letter == 'T')
        {
            iArrScores2[i] = 8;
        }

        current2 = current2->next;
    }

    if (iSize1 < iSize2)
    {
        for (int i = 0; i < iSize1; i++)
        {
            if (iArrScores1[i] < iArrScores2[i])
            {
                return true;
            }
            else if (iArrScores1[i] > iArrScores2[i])
            {
                return false;
            }
        }

        return true;
    }
    else if (iSize1 > iSize2)
    {
        for (int i = 0; i < iSize2; i++)
        {
            if (iArrScores1[i] < iArrScores2[i])
            {
                return true;
            }
            else if (iArrScores1[i] > iArrScores2[i])
            {
                return false;
            }
        }

        return false;
    }
    else
    {
        for (int i = 0; i < iSize1; i++)
        {
            if (iArrScores1[i] < iArrScores2[i])
            {
                return true;
            }
            else if (iArrScores1[i] > iArrScores2[i])
            {
                return false;
            }
        }

        return true;
    }
}

int main()
{
    cout << "============= Testing insertLetter =============" << endl;
    
    Letter* head1 = new Letter;
    head1->letter = 'A';
    head1->prev = nullptr;
    head1->next = nullptr;

    Letter* letter1 = new Letter;
    letter1->letter = 'B';
    letter1->prev = nullptr;
    letter1->next = nullptr;

    Letter* letter2 = new Letter;
    letter2->letter = 'U';
    letter2->prev = nullptr;
    letter2->next = nullptr;

    Letter* letter3 = new Letter;
    letter3->letter = 'J';
    letter3->prev = nullptr;
    letter3->next = nullptr;

    Letter* letter4 = new Letter;
    letter4->letter = 'Y';
    letter4->prev = nullptr;
    letter4->next = nullptr;

    Word* word1 = new Word;
    word1->head = head1;
    word1->prev = nullptr;
    word1->next = nullptr;

    insertLetter(&(word1->head), letter1);
    insertLetter(&(word1->head), letter2);
    insertLetter(&(word1->head), letter3);
    insertLetter(&(word1->head), letter4);

    cout << "Word 1: ";
    printWord(word1);

    Letter* head2 = new Letter;
    head2->letter = 'T';
    head2->prev = nullptr;
    head2->next = nullptr;

    Letter* letter5 = new Letter;
    letter5->letter = 'U';
    letter5->prev = nullptr;
    letter5->next = nullptr;

    Letter* letter6 = new Letter;
    letter6->letter = 'R';
    letter6->prev = nullptr;
    letter6->next = nullptr;

    Letter* letter7 = new Letter;
    letter7->letter = 'A';
    letter7->prev = nullptr;
    letter7->next = nullptr;

    Word* word2 = new Word;
    word2->head = head2;
    word2->prev = nullptr;
    word2->next = nullptr;

    insertLetter(&(word2->head), letter5);
    insertLetter(&(word2->head), letter6);
    insertLetter(&(word2->head), letter7);

    cout << "Word 2: ";
    printWord(word2);

    Letter* head3 = new Letter;
    head3->letter = 'T';
    head3->prev = nullptr;
    head3->next = nullptr;

    Letter* letter8 = new Letter;
    letter8->letter = 'R';
    letter8->prev = nullptr;
    letter8->next = nullptr;

    Letter* letter9 = new Letter;
    letter9->letter = 'A';
    letter9->prev = nullptr;
    letter9->next = nullptr;

    Word* word3 = new Word;
    word3->head = head3;
    word3->prev = nullptr;
    word3->next = nullptr;

    insertLetter(&(word3->head), letter8);
    insertLetter(&(word3->head), letter9);

    cout << "Word 3: ";
    printWord(word3);

    cout << "\n============= Testing isValid =============" << endl;

    cout << "Is word1 valid? " << isValid(word1) << endl;
    cout << "Is word2 valid? " << isValid(word2) << endl;
    cout << "Is word3 valid? " << isValid(word3) << endl;

    cout << "\n============= Testing insertWord =============" << endl;
    
    Word* wordList = new Word;
    wordList->head = nullptr;
    wordList->prev = nullptr;
    wordList->next = nullptr;

    printList(wordList);
    cout << "\n" << endl;
    
    insertWord(&wordList, word1);
    printList(wordList);
    cout << "\n" << endl;

    insertWord(&wordList, word2);
    printList(wordList);
    cout << "\n" << endl;

    insertWord(&wordList, word3);
    printList(wordList);

    cout << "\n============= Testing find =============" << endl;
    
    cout << "Is word1 in the list? " << find(wordList, word1) << endl;
    cout << "Is word2 in the list? " << find(wordList, word2) << endl;
    cout << "Is word3 in the list? " << find(wordList, word3) << endl;

    Word* word4 = new Word;
    word4->head = nullptr;
    word4->prev = nullptr;
    word4->next = nullptr;

    Letter* head4 = new Letter;
    head4->letter = 'B';
    head4->prev = nullptr;
    head4->next = nullptr;

    Letter* letter10 = new Letter;
    letter10->letter = 'E';
    letter10->prev = nullptr;
    letter10->next = nullptr;

    Letter* letter11 = new Letter;
    letter11->letter = 'B';
    letter11->prev = nullptr;
    letter11->next = nullptr;

    insertLetter(&(word4->head), head4);
    insertLetter(&(word4->head), letter10);
    insertLetter(&(word4->head), letter11);

    cout << "\nWord 4: ";
    printWord(word4);
    cout << "Is word4 in the list? " << find(wordList, word4) << endl;


    cout << "\n============= Testing deleteWord =============" << endl;
    
    cout << "Deleting word1..." << endl;
    deleteWord(&wordList, word1);
    printList(wordList);

    cout << "\nDeleting word2..." << endl;
    deleteWord(&wordList, word2);
    printList(wordList);

    cout << "\nDeleting word3..." << endl;
    deleteWord(&wordList, word3);
    printList(wordList);

    cout << "\nDeleting word4..." << endl;
    deleteWord(&wordList, word4);
    printList(wordList);

    cout << "\n============= Testing deleteAt =============" << endl;
    
    insertWord(&wordList, word1);
    insertWord(&wordList, word2);
    letter10->letter = 'A';
    insertWord(&wordList, word4);
    printList(wordList);

    cout << "\nDeleting 3rd word..." << endl;
    deleteAt(&wordList, 3);
    printList(wordList);

    cout << "\nDeleting 1st word..." << endl;
    deleteAt(&wordList, 1);
    printList(wordList);

    cout << "\nDeleting 1st word..." << endl;
    deleteAt(&wordList, 1);
    printList(wordList);

    cout << "\nRestoring list..." << endl;
    insertWord(&wordList, word1);
    insertWord(&wordList, word2);
    letter10->letter = 'A';
    insertWord(&wordList, word4);
    printList(wordList);

    cout << "\nDeleting 2nd word..." << endl;
    deleteAt(&wordList, 2);
    printList(wordList);

    cout << "\nDeleting 1st word..." << endl;
    deleteAt(&wordList, 1);
    printList(wordList);

    cout << "\nDeleting 1st word..." << endl;
    deleteAt(&wordList, 1);
    printList(wordList);

    cout << "\n============= Testing comparison =============" << endl;
    
    cout << "Word 1: ";
    printWord(word1);

    cout << "Word 2: ";
    printWord(word2);

    cout << "Word 4: ";
    printWord(word4);

    cout << "Comparing word1 and word2: " << comparison(word1, word2) << endl;
    cout << "Comparing word1 and word4: " << comparison(word1, word4) << endl;
    cout << "Comparing word4 and word1: " << comparison(word4, word1) << endl;
    cout << "Comparing word4 and word4: " << comparison(word4, word4) << endl;
    cout << "Comparing word2 and word4: " << comparison(word2, word4) << endl;

    return 0;
}