/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main()
{
	int num_guesses;
	cin >> num_guesses;

	vector<string> guesses(num_guesses);

	for (int i = 0; i < num_guesses; ++i) {
		cin >> guesses[i];
	}
	int num_yes;
	cin >> num_yes;

	unordered_map<string, vector<string>> Groups;

	for (string& guess : guesses) {
		string b = guess;
		sort(b.begin(), b.end());
		Groups[b].push_back(guess);
	}

	vector<string> expectedWords;

	for (auto& group : Groups) {
		auto& final_words = group.second;
		if (final_words.size() >= num_yes) {
			expectedWords.insert(expectedWords.end(), final_words.begin(), final_words.end());
		}
	}

	for (string& final_words : expectedWords) {
		std::cout << final_words << std::endl;
	}

	return 0;
}
