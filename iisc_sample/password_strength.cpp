#include<iostream>

using namespace std;

int main() 
{
	char p[64];
	cin >> p;

	bool special = false, lower=false, upper=false, number=false;

	for (int i=0; p[i]!='\0'; i++){
		if (!special)	
			if((int)p[i] >= 58 && (int)p[i] <= 64)
				special = true;
	    if(!lower)
			if((int)p[i] >= (int)'a' && (int)p[i] <= (int)'z')
				lower = true;
		if(!upper)
			if((int)p[i] >= (int)'A' && (int)p[i] <= (int)'Z')
			    upper = true;
		if(!number)
			if((int)p[i] >= (int)'0' && (int)p[i] <= (int)'9')
				number = true;

	}

	if (special && lower && upper && number)
		cout << "1";
	else 
		cout << "0";
}
