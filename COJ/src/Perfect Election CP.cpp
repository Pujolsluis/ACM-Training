//============================================================================
// Name        : Perfect.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <string>
using namespace std;

int main() {
	char readBuffer[20];
	scanf("%s", &readBuffer);

	string s;
	s = readBuffer;
	while(s.length() > 1){
		int cnt = 0;
		for(int i = 0; i < s.length(); i++){
			cnt += (s[i] - '0');
		}
		char buffer[20];
		sprintf(buffer, "%d", cnt);
		s = buffer;
	}
	printf("%s", s.c_str());
	return 0;
}
