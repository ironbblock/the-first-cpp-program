#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	short input = 1;
	while (input != 0)
	{
		cout << "\n\n输入0--4\n   0--退出   1--解一元二次方程\n   2--猜词\n   3--猜数字\n   4三角形求周长面积\n";
		cin >> input;
		if (input != 0 && input != 1 && input != 2 && input != 3 && input != 4)
			cout << "亻尔女马\n";
		else
		{
			switch (input)
			{
			case 1:
			{
				long double x1, x2, a, b, c, dlt;
				cout << "输入一元二次方程的三个系数abc：\n";
				cin >> a >> b >> c;
				if (a == 0)
					cout << "error:unexpected parameter\n";
				else
				{
					dlt = b * b - 4 * a * c;
					if (dlt < 0)
						cout << "fw\n";
					else if (dlt == 0)
					{
						x1 = x2 = -b / 2 / a;
						cout << "x1=x2=" << x1 << "\n";
					}
					else
					{
						x1 = (-b + sqrt(dlt)) / 2 / a;
						x2 = (-b + sqrt(dlt)) / 2 / a;
						cout << "x1=" << x1 << "x2=" << x2 << "\n";
					}
				}break;
			case 2:
			{
				const int MAX_WRONG = 25;
				vector<string> words;
				words.push_back("CONGRATOLATION");
				words.push_back("FUCK");
				words.push_back("LIXINHAOSB");
				words.push_back("ZHANGYIJIAFW");
				srand(static_cast<unsigned int>(time(0)));
				random_shuffle(words.begin(), words.end());
				const string THE_WORD = words[0];
				int wrong = 0;
				string soFar(THE_WORD.size(), '-');
				string used = "";
				cout << "Welcome to Hangman,you need to guess the word that written by your PC.";
				while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
				{
					cout << "You have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
					cout << "You've used the following letters:\n" << used << endl;
					cout << "So far,the word is: \n" << soFar << endl;
					char guess;
					cout << "Enter your guess:\n";
					cin >> guess;
					guess = toupper(guess);
					while (used.find(guess) != string::npos)
					{
						cout << "You've already guessed " << guess << endl;
						cout << "Enter your guess:\n";
						cin >> guess;
						guess = toupper(guess);
					}
					used += guess;
					if (THE_WORD.find(guess) != string::npos)
					{
						cout << "\n\nThat's right!" << guess << " is in the word.\n";
						for (int i = 0; i < THE_WORD.length(); ++i)
						{
							if (THE_WORD[i] == guess)
								soFar[i] = guess;
						}
					}
					else
					{
						cout << "\n\nsorry," << guess << " isn't in the word.";
						++wrong;
					}
				}

				if (wrong == MAX_WRONG)
					cout << "You are hanged.\n";
				else
					cout << "You guess it.\n";
				cout << "The word was " << THE_WORD << endl;
			}break;
			case 3:
			{
				srand(static_cast<unsigned int>(time(0)));
				int secretNumber = rand() % 100 + 1, tries = 0, guess;
				vector<string> esc;
				for (string esc = ""; esc != "quit";)
				{
					cout << "Welcome To guess number,type 'continue' or 'quit'.\n\n";
					cin >> esc;
					if (esc == "continue")
					{
						do
						{
							cout << "Enter a number between 0 and 100,dont press a float,or there will be a bug.\n";
							cin >> guess;
							++tries;
							if (guess >= 0 && guess <= 100)
							{
								if (guess < secretNumber)
									cout << "Too Low!\n";
								else if (guess > secretNumber)
									cout << "Too high!\n";
								else
									cout << "You got it in " << tries << " guess\n";
							}
							else
								cout << "亻尔女马\n";
						} while (guess != secretNumber);
					}
					else if (esc == "quit")
						cout << "" << endl;
					else
						cout << "亻尔女马\n";
				}
			}break;
			case 4:
			{
				double a, b, c, S, C, p;
				cout << "输入三角形三边长\n";
				cin >> a >> b >> c;
				if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
				{
					C = a + b + c;
					p = C / 2;
					S = sqrt(p * (p - a) * (p - b) * (p - c));
					cout << "面积：\n" << S;
				}
				else
					cout << "fw\n";
			}break;
			}
			}
		}
	}
	system("pause");
	return 0;
}