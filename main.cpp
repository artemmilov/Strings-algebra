#include <iostream>
#include <string>
#include <ctime>

using namespace std;

inline int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int LCS_length(string str1, string str2)
{
	int** LCS_len = new int*[str1.length() + 1];
	for (int i = 0; i < str1.length() + 1; i++)
		LCS_len[i] = new int[str2.length() + 1];
	pair <int, int>** prev = new pair <int, int>*[str1.length()];
	for (int i = 0; i < str1.length(); i++)
		prev[i] = new pair <int, int>[str2.length()];
	for (int i(0); i < str1.length() + 1; i++)
		LCS_len[i][0] = 0;
	for (int i(0); i < str2.length() + 1; i++)
		LCS_len[0][i] = 0;
	for (int i(1); i < str1.length() + 1; i++)
		for (int j(1); j < str2.length() + 1; j++)
			if (str1[i - 1] == str2[j - 1])
			{
				LCS_len[i][j] = LCS_len[i - 1][j - 1] + 1;
				prev[i - 1][j - 1] = { i - 1, j - 1 };
			}
			else
			{
				if (LCS_len[i - 1][j] >= LCS_len[i][j - 1])
				{
					LCS_len[i][j] = LCS_len[i - 1][j];
					prev[i - 1][j - 1] = { i - 1, j };
				}
				else
				{
					LCS_len[i][j] = LCS_len[i][j - 1];
					prev[i - 1][j - 1] = { i, j - 1 };
				}
			}
	return LCS_len[str1.length()][str2.length()];
}
string LCS(string str1, string str2)
{
	int** LCS_len = new int*[str1.length() + 1];
	for (int i = 0; i < str1.length() + 1; i++)
		LCS_len[i] = new int[str2.length() + 1];
	pair <int, int>** prev = new pair <int, int>*[str1.length()];
	for (int i = 0; i < str1.length(); i++)
		prev[i] = new pair <int, int>[str2.length()];
	for (int i(0); i < str1.length() + 1; i++)
		LCS_len[i][0] = 0;
	for (int i(0); i < str2.length() + 1; i++)
		LCS_len[0][i] = 0;
	for (int i(1); i < str1.length() + 1; i++)
		for (int j(1); j < str2.length() + 1; j++)
			if (str1[i - 1] == str2[j - 1])
			{
				LCS_len[i][j] = LCS_len[i - 1][j - 1] + 1;
				prev[i-1][j-1] = { i - 1, j - 1 };
			}
			else
			{
				if (LCS_len[i - 1][j] >= LCS_len[i][j - 1])
				{
					LCS_len[i][j] = LCS_len[i - 1][j];
					prev[i-1][j-1] = { i - 1, j };
				}
				else
				{
					LCS_len[i][j] = LCS_len[i][j - 1];
					prev[i-1][j-1] = { i, j - 1 };
				}
			}
	string result_str = "";
	int i = str1.length() - 1;
	int j = str1.length() - 1;
	while (i != -1 && j != -1)
	{
		if (prev[i][j].first == i && prev[i][j].second == j)
		{
			result_str = str1[i] + result_str;
			i--;
			j--;
		}
		else
		{
			if (prev[i][j].first == i)
				i--;
			else
				j--;
		}
	}
	return result_str;
}

string LongestPalindrome(string str)
{
	int** L = new int*[str.length()];
	for (int i = 0; i < str.length(); i++)
		L[i] = new int[str.length()];
	pair <int, int>** prev = new pair <int, int>*[str.length()];
	for (int i = 0; i < str.length(); i++)
		prev[i] = new pair <int, int>[str.length()];

	int i = 0;
	int j = 0;
	for (int k = 0; k < str.length(); k++)
		for (int t = 0; t < str.length(); t++)
		{
			i = t;
			j = (k + t + str.length()) % str.length();

			if (i > j)
			{
				L[i][i] = 0;
			}
			if (i == j)
			{
				L[i][i] = 1;
			}
			if (i < j)
			{
				if (str[i] == str[j])
				{
					L[i][j] = 2 + L[i + 1][j - 1];
					prev[i][j] = { i + 1, j - 1 };
				}
				else
				{
					if (L[i + 1][j] >= L[i][j - 1])
					{
						L[i][j] = L[i + 1][j];
						prev[i][j] = { i + 1, j };
					}
					else
					{
						L[i][j] = L[i][j - 1];
						prev[i][j] = { i, j - 1 };
					}
				}
			}
		}
	cout << L[0][str.length() - 1] << endl;
	string result_str1 = "";
	string result_str2 = "";
	i = 0;
	j = str.length() - 1;
	while (i <= j)
	{
		if (i < j)
		{
			if (prev[i][j].first == i + 1 && prev[i][j].second == j - 1)
			{
				result_str1 += str[i];
				result_str2 = str[j] + result_str2;
				i++;
				j--;
			}
			if (prev[i][j].first == i + 1 && prev[i][j].second == j)
				i++;
			if (prev[i][j].first == i && prev[i][j].second == j - 1)
				j--;
		}
		if (i == j)
		{
			result_str1 += str[i];
			i++;
		}
	}
	return result_str1 + result_str2;
}

string random_generate(int n)
{
	string str = "";
	for (int i = 0; i < n; i++)
		if (rand() % 2 == 0)
			str += 'a';
		else
			str += 'b';
	return str;
}
float calculate_C(float accuracy_value)
{
	double delta;
	string a = random_generate(1);
	string b = random_generate(1);
	double c_last = 0;
	double c_now = 0;
	long sample_counter = 1;
	delta = 100;
	while (delta >= accuracy_value || sample_counter <= 10)
	{
		c_last = c_now;
		a = random_generate(sample_counter);
		b = random_generate(sample_counter);
		c_now = (c_last * sample_counter + LCS_length(a, b) / double(sample_counter)) / (sample_counter + 1);

		delta = abs(c_now - c_last);
		sample_counter++;
	}
	cout << sample_counter << '\t';
	return c_now;
}

int main()
{
}