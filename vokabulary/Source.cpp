#include <iostream>
#include <map>
#include <string>
#include <list>
#include <fstream>
#include <Windows.h>
using namespace std;

class Vocabulary
{
private:
	map<string, list<string>> dic;
public:

	void ShowAll()
	{
		map <string, list<string>> ::iterator it = dic.begin();
		for (int i = 0; it != dic.end(); it++, i++) 
		{ 
			cout << "Word: " << it->first << endl;
			cout << "Translate: " << endl;
			for (auto j = (it->second).begin(); j != (it->second).end(); j++)
			{
				cout << *(j) << "\t";
			}
			cout << endl;
		}
	}

	void word_search()
	{
		string input = "";
		cout << "Enter word to translate: "; getline(cin, input);

		if (dic.find(input) == dic.end())
			cout << "Translate not found! \n";
		else
		{
			cout << "\tMeans\n";
			for (string elem : dic[input])
			{
				cout << "Means: " << elem << "\t";
			}
		}
		cout << endl;
	}

	void AddTranslateToWord()
	{
		string input = "";
		cout << "Enter word to add translate: "; getline(cin, input);

		if (dic.find(input) == dic.end())
			cout << "Translate not found! \n";
		else
		{
			string translate = "";
			int a;
			cout << "Enter count of translates, which you want to add: "; 
			cin >> a;
			cin.ignore();
			for (int i = 0; i < a; i++)
			{
				cout << "Enter translate: "; getline(cin, translate);
				dic[input].push_back(translate);
			}
		}
	}

	void AddWordToVocebulary()
	{
		string word;
		cin.ignore();
		cout << "Enter word to add to vocabulary: "; getline(cin, word);

		list<string> temp;
		string translate;
		int tmp;
		cout << "Enter count of translates: ";
		cin >> tmp;
		cin.ignore();
		for (int i = 0; i < tmp; i++)
		{
			cout << "Enter translate: "; getline(cin, translate);
			temp.push_back(translate);
		}

		dic.insert(make_pair(word, temp));
	}

	void DeleteWordFromVocabulary()
	{
		string input = "";
		cout << "Enter word to delete: "; getline(cin, input);

		if (dic.find(input) == dic.end())
			cout << "Word not found! \n";
		else
		{
			dic.erase(input);
		}
	}

	/*void editing()
	{
		string input = "";
		cout << "Enter word to eidt: "; getline(cin, input);
		if (dic.find(input) == dic.end())
			cout << "Translate not found! \n";
		else
		{
			string newWord;
			cout << "Enter new word: "; getline(cin, newWord);
			dic.find(input) = newWord;
			cout << "\Editing means\n";
			for (string elem : dic[input])
			{
				string newMeans;
				cout << "Means: " << elem << " --> "; getline(cin, newMeans);
				elem = newMeans;
			}
		}
	}*/
	friend ofstream& operator<<(ofstream& out, Vocabulary& vk);
	friend ifstream& operator>>(ifstream& in, Vocabulary& vk);
};

ofstream& operator<<(ofstream& out, Vocabulary& vk)
{
	for (map<string, list<string>>::iterator i = vk.dic.begin(); i != vk.dic.end(); i++)
	{
		out << i->first << endl;
		out <<vk.dic[i->first].size() << endl;
		for (string elem : vk.dic[i->first])
		{
			out << elem << endl;
		}
	}
	return out;
}

ifstream& operator>>(ifstream& in, Vocabulary& vk)
{
	string key, word;
	int number;
	list<string>tmp;
	while (!in.eof())
	{
		if (!in.eof())
		{
			in >> key;
			in >> number;
			for (int i = 0; i < number; i++)
			{
				in >> word;
				tmp.push_back(word);
			}
			vk.dic.insert(make_pair(key, tmp));
			tmp.clear();
		}
	}
	return in;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	int a = 0;
	do
	{
		cout << "Select vocabulary: " << endl;
		cout << "1 - English to Russian" << endl;
		cout << "2 - Russian to English" << endl;
		cout << "0 - exit" << endl;
		cout << "--> ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			Vocabulary vk;
			int b;
			do
			{
				cout << " 1 - Add word to vocabulary" << endl;
				cout << " 2 - Delete word from vocabulary" << endl;
				cout << " 3 - Add translate word" << endl;
				cout << " 4 - Search word" << endl;
				cout << " 5 - Show all words from vocabulary" << endl;
				cout << " 6 - Save vocabulary to file" << endl;
				cout << " 7 - Load vocabulary from file" << endl;
				cout << " 0 - exit" << endl;
				cout << "--> ";
				cin >> b;
				switch (b)
				{
				case 1:
				{
					vk.AddWordToVocebulary();
				}
				break;
				case 2:
				{
					vk.DeleteWordFromVocabulary();
				}
				break;
				case 3:
				{
					vk.AddTranslateToWord();
				}
				break;
				case 4:
				{
					vk.word_search();
				}
				break;
				case 5:
				{
					vk.ShowAll();
				}
				break;
				case 6:
				{
					ofstream out("file.txt");

					out << vk;
				}
				break;
				case 7:
				{
					ifstream in("file.txt");;

					Vocabulary vk2;

					in >> vk2;
				}
				break;
				default:
					break;
				}
			} while (b != 0);
		}
		break;
		case 2:
		{
			Vocabulary vk;
			int b;
			do
			{
				cout << " 1 - Add word to vocabulary" << endl;
				cout << " 2 - Delete word from vocabulary" << endl;
				cout << " 3 - Add translate word" << endl;
				cout << " 4 - Search word" << endl;
				cout << " 5 - Show all words from vocabulary" << endl;
				cout << " 6 - Save vocabulary to file" << endl;
				cout << " 7 - Load vocabulary from file" << endl;
				cout << " 0 - exit" << endl;
				cout << "--> ";
				cin >> b;
				switch (b)
				{
				case 1:
				{
					vk.AddWordToVocebulary();
				}
				break;
				case 2:
				{
					vk.DeleteWordFromVocabulary();
				}
				break;
				case 3:
				{
					vk.AddTranslateToWord();
				}
				break;
				case 4:
				{
					vk.word_search();
				}
				break;
				case 5:
				{
					vk.ShowAll();
				}
				break;
				case 6:
				{
					ofstream out("file2.txt");

					out << vk;
				}
				break;
				case 7:
				{
					ifstream in("file2.txt");;

					Vocabulary vk2;

					in >> vk2;
				}
				break;
				default:
					break;
				}
			} while (b != 0);
		}
		break;
		default:
			break;
		}
		
	}while (a != 0);
	system("pause");
	return 0;
}