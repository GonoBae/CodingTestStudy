#include <iostream>
#include <string>

using namespace std;

int main()
{
	int answer = 0;
	string temp = "";
	string input;
	cin >> input;

	// 첫 '-'가 나올때까지 나온 숫자는 모두 더하기
	int firstMinus = input.find('-');
	if (firstMinus == -1) { firstMinus = input.length(); } // '-'가 없을 경우

	for (int i = 0; i < firstMinus; ++i)
	{
		if (input[i] == '+')
		{
			answer += stoi(temp);
			temp = "";
		}
		else
		{
			temp += input[i];
		}
	}
	answer += stoi(temp);
	temp = "";

	// '-' 이후의 숫자는 모두 합한 후 answer와 빼기
	for (int i = firstMinus + 1; i < input.length(); ++i)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			answer -= stoi(temp);
			temp = "";
		}
		else
		{
			temp += input[i];
		}
	}
	if ( temp != "") { answer -= stoi(temp); }
	
	cout << answer;

	return 0;
}