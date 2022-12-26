# define N 3
# define ABS(x)   (x>=0?x:-x)
# define YiHao(a,b)   ((a)>0&&(b)<0||(a)<0&&(b)>0)
#include <stdio.h>
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<math.h>
using namespace std;

void change(long long* a, long long* b)//���� a b��ֵ
{
    long long  c = *a;
    *a = *b;
    *b = c;
}
long long  gcd(long long  x, long long  y)//���� x y���������
{
    long long  a;
    if (!y)return x;
    while (a = x % y)
        (x = y) && (y = a);
    return y;
}
long long  Dsum(long long  A[][N])//����N������ʽ��ֵ
{
    long long  i, sum = 0;
    for (i = 0; i < N; i++)//��D��ֵ
        sum += A[i][0] * A[(i + 1) % N][1] * A[(i + 2) % N][2] - A[i][2] * A[(i + 1) % N][1] * A[(i + 2) % N][0];
    return sum;
}
long long  A[N][N];
long long  D[N][2], X[N], Y[N];
long long  i, j, k, sum;

const char Q = 'Q';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board,int move);
int humanMove(const vector<char>& board,char human);
int computerMove(vector<char> board,char computer);
void annouceWinner(char winner, char computer, char human);
int main()
{
	short input = 1;
	while (input != 0)
	{
		cout << "\n\n����0--6\n   0--�˳�\n   1--��һԪ���η���\n   2--�´�\n   3--������\n   4--���������ܳ����\n   5--���������������ʽ\n   6--������\n";
		cin >> input;
		if (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
			cout << "���Ů��\n";
		else
		{
			switch (input)
			{
			case 1:
			{
				long double x1, x2, a, b, c, dlt;
				cout << "����һԪ���η��̵�����ϵ��abc��\n";
				cin >> a >> b >> c;
				if (a == 0)
					cout << "error:unexpected parameter\n";
				else if (a > 1000000000000 || a < -1000000000000 || b > 1000000000000 || b < -1000000000000 || c > 1000000000000 || c < -1000000000000)
					cout << "�������Ů��\n";
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
						x2 = (-b - sqrt(dlt)) / 2 / a;
						cout << "x1=" << x1 << " x2=" << x2 << "\n";
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
								cout << "���Ů��\n";
						} while (guess != secretNumber);
					}
					else if (esc == "quit")
						cout << "" << endl;
					else
						cout << "���Ů��\n";
				}
			}break;
			case 4:
			{
				double a, b, c, S, C, p;
				cout << "�������������߳�\n";
				cin >> a >> b >> c;
				if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
				{
					C = a + b + c;
					p = C / 2;
					S = sqrt(p * (p - a) * (p - b) * (p - c));
					cout << "�����\n" << S;
				}
				else if (a > 1000000000000 || a < -1000000000000 || b > 1000000000000 || b < -1000000000000 || c > 1000000000000 || c < -1000000000000)
					cout << "�������Ů��\n";
				else
					cout << "fw\n";
			}break;
			}
			case 5:
			{
					for (i = 0; i < N; i++)
					{
						printf("�����%d����x y:", i + 1);
						scanf_s("%lld%lld", &D[i][0], &D[i][1]);//�����
						A[i][0] = D[i][0] * D[i][0];//��D ����ʽ
						A[i][1] = D[i][0];
						A[i][2] = 1;
					}
					sum = Dsum(A);//������ʽA��ֵ
					if (sum)
					{
						printf("\nf(x)=");
						for (i = 0; i < N; i++)
						{
							for (j = 0; j < N; j++)
								change(&A[j][i], &D[j][1]);//��D�ĵڶ��е� ��Yi ��ֵ��A[][]�еĵ�j�� ����
							X[i] = Dsum(A);//�󽻻���i��֮�������ʽA��ֵ
							for (j = 0; j < N; j++)//�������� �ָ�Aֵ
								change(&A[j][i], &D[j][1]);
							Y[i] = gcd(sum, X[i]);//��sum ��X[i] ���������
							X[i] /= Y[i];//
							Y[i] = sum / Y[i];//���˷��� ��Ϊ���   �õ����� X[i]/Y[i]
						}
						if (X[0]) //���������ϵ��
						{
							if (YiHao(X[0], Y[0]))printf("-");//���ϵ���ķ���
							if (Y[0] != 1 && X[0] != Y[0])
								printf("(%lld/%lld)", ABS(X[0]), ABS(Y[0]));
							else if (X[0] != 1)printf("%lld", ABS(X[0]));
							printf("x^2");
						}
						if (X[1])
						{
							if (YiHao(X[1], Y[1]))printf("-");//���ϵ���ķ���
							else if (X[0])printf("+");
							if (Y[1] != 1 && X[1] != Y[1])
								printf("(%lld/%lld)", ABS(X[1]), ABS(Y[1]));
							else if (X[1] != 1)printf("%lld", ABS(X[1]));
							printf("x");
						}
						if (X[2])
						{
							if (YiHao(X[2], Y[2]))printf("-");//���ϵ���ķ���
							else if (X[0] || X[1]) printf("+");
							if (Y[2] != 1 && X[2] != Y[2])
								printf("(%lld/%lld)", ABS(X[2]), ABS(Y[2]));
							else printf("%lld", ABS(X[2]));
						}
						if (!X[0] && !X[1] && !X[2])printf("0");
						printf("\n");
					}
					else printf("No answer!\n");
			}
			case 6:
			{
				int move;
				const int NUM_SQUARES = 9;
				vector<char> board(NUM_SQUARES, EMPTY);
				instructions();
				char human = humanPiece();
				char computer = opponent(human);
				char turn = Q;
				displayBoard(board);
				while (winner(board) == NO_ONE)
				{
					if (turn == human)
					{
						move = humanMove(board, human);
						board[move] = human;
					}
					else
					{
						move = computerMove(board, computer);
						board[move] = computer;
					}
					displayBoard(board);
					turn = opponent(turn);
				}
				annouceWinner(winner(board), computer, human);
			}
			}
		}
	}
	system("pause");
	return 0;
}
void instructions()
{
	cout << "������\n";
	cout << "ʹ��1--8������\n";
	cout << "��Ӧ����������̵�λ�ã���ͼ��ʾ\n";
	cout << " 0 | 1 | 2\n";
	cout << " ---------\n";
	cout << " 3 | 4 | 5\n";
	cout << " ---------\n";
	cout << " 6 | 7 | 8\n";
	cout << "�Լ�����׼��,���ࡣս��������ʼ\n";
}
char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << "(y/n):";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}
int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);
	return number;
}
char humanPiece()
{
	char go_first = askYesNo("do you want to move first?");
	if (go_first == 'y')
	{
		cout << "go.\n";
		return Q;
	}
	else
	{
		cout << "you will regret.\n";
		return O;
	}
}
char opponent(char piece)
{
	if (piece == 'X')
		return O;
	else
		return Q;
}
void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------\n";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------\n";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}
char winner(const vector<char>& board)
{
	const int WINNING_ROWS[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
			return board[WINNING_ROWS[row][0]];
	}
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return	TIE;
	return NO_ONE;
}
inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("where will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "sb,gun.\n";
		move = askNumber("where will you move?", (board.size() - 1));
	}
	cout << "fine...\n";
	return move;
}
int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
			++move;
	}
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		if (isLegal(move, board))
		{
			board[move] = human;
			found = winner(board) == human;
			board[move] = EMPTY;
		}
		if (!found)
			++move;
	}
	if (!found)
	{
		move = 0;
		unsigned int i = 0; const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
				found = true;
			++i;
		}
	}
	cout << "��Ӧ����ȡƽ����" << move;
	return move;
}
void annouceWinner(char winner, char computer, char human)
{
	if (winner == computer)
		cout << "lj,fw.\n";
	else if (winner == human)
		cout << "��Ӯ�ˣ����������\n";
	else
		cout << "ƽ�֣�lj��\n";
}