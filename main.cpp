#include <iostream>
#include <fstream>
#include <string>

extern "C" int find(int* intValueOfWord, int* intValueOfWord2);
using namespace std;

int main(int argc, char* argv[])
{

	fstream file;
	char word[150];
	char word2[50];
	char tempS[50];
	char temp;
	int intValueOfWord[150];
	int intValueOfWord2[50];
	int found = 0;
	char wc[50];
	file.open(argv[1]);

	word[0] = 0;

	int i = 0;
	int j = 0;
	while (!file.eof())
	{
		i = -1;
		do { //for gaps
			i++;
			file.get(wc[i]);
		} while (wc[i] == ' ' || wc[i] == '\t' || wc[i] == '\n');
		temp = wc[i];
		wc[i] = 0;
		file >> tempS;

		if (file.eof() == 1)
		{ //get the word 2 as the last word
			word2[0] = temp; //strcpy temp to word2
			for (i = 0; tempS[i] != 0 && i < 49; ++i) // strconcanate tempS to word2
			{
				word2[i + 1] = tempS[i];
			}
			word2[i + 1] = 0;
		}
		else
		{
			if (word[0] == 0) //strcpy tempS to word
			{
				for (i = 0, j = 0; wc[i] != 0 && j < 49; ++i, ++j) //strconcanate wc to word
				{
					word[j] = wc[i];
				}
				word[j] = temp;
				j++;
				for (i = 0, j; tempS[i] != 0 && j < 49; ++j, ++i)
				{
					word[j] = tempS[i];
				}
				word[j] = 0;
			}
			else
			{
				for (i = 0; wc[i] != 0 && j < 49; ++i, ++j) //strconcanate wc to word
				{
					word[j] = wc[i];
				}
				word[j] = temp; // strconcanate temp to word 
				j++;
				i = 0;
				for (; tempS[i] != 0 && j < 49; ++j) //strconcanate next word to word
				{
					word[j] = tempS[i];
					++i;
				}
				word[j] = 0;
			}
		}
	}
	file.close();
	cout << word << endl;
	cout << word2 << endl;

	int k = 0;
	while (word[k] != '\0')
	{
		intValueOfWord[k] = (int)word[k];
		k++;
	}
	intValueOfWord[k] = 0;
	k = 0;
	while (word2[k] != '\0')
	{
		intValueOfWord2[k] = (int)word2[k];
		k++;
	}
	intValueOfWord2[k] = 0;
	k = 0;

	found = find(intValueOfWord, intValueOfWord2);
	cout << found << endl;

	getchar();
	getchar();
}

