#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
// 자료형의 함수
//isspace(a) 함수는 a가 공백이면 참 값을 반환

using namespace std;

// 인수가 공백일 때는 false,
// 그렇지 않을 때는 true 반환
bool not_space(char c) {
	return !isspace(c);
}

// 인수가 공백일 때는 true,
// 그렇지 않을 때는 false 반환
bool space(char c) {
	return isspace(c);
}


vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type str_sz;
	str_sz i = 0;

	//불변성: 지금까지 [원래의 i, 현재의 i] 범위에 있는
	// 문자들을 처리
	while (i != s.size()) {
		//선행하는 공백들을 무시
		//불변성: 지금까지 [원래의 i, 현재의 i] 범위에 있는
	// 문자들은 모두 공백(isspace())
		while (i != s.size() && isspace(s[i])) {
			++i;
		}

		str_sz j = i;
		//불변성: 지금까지 [원래의 i, 현재의 i] 범위에 있는
	// 문자들은 모두 공백이 아님 (!isspace())
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}
		//공백이 아닐때
		if (i != j) {
			ret.push_back(s.substr(i, j));
			i = j;
		}
	}
	return ret;
}
vector<string> lib_split(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter i = s.begin(); //첫 요소에 가리키는 포인터 (개념)

	//불변성: 지금까지 [원래의 i, 현재의 i] 범위에 있는
	// 문자들을 처리
	while (i != s.end()) {
		// 선행 공백을 무시
		i = find_if(i, s.end(), not_space);
		
		//다음 단어의 끝을 찾음
		iter j = find_if(i, s.end(), space);

		
	//	[원래의 i, 현재의 j) 범위에 있는
	
    //문자들을 복사
		if (i != s.end()) {
			
			ret.push_back(string(i, j));
		}
		i = j;
	}
	return ret;
}
int main() {
	string s;

	//문자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v1 = split(s);
		vector<string> v2 = lib_split(s);

		cout << "Original split(): " << endl;
		for (vector <string>::size_type i = 0;
			i != v1.size(); i++) {
			cout << v1[i] << endl;
		}

		cout << endl << "New lib_split(): " << endl;
		for (vector <string>::size_type i = 0;
			i != v2.size(); i++) {
			cout << v2[i] << endl;
		}

	}
	return 0;
}
