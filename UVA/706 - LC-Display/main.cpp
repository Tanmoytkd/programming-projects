#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

int size, len;
char num[9];
int top (char ch) {
	switch(ch) {
		case '1':
		case '4': return 0;
		default: return 1;
	}
}

int mid(char ch) {
	switch(ch) {
		case '1':
		case '7':
		case '0': return 0;
		default: return 1;
	}
}

int bottom(char ch) {
	switch(ch) {
		case '1':
		case '4':
		case '7': return 0;
		default: return 1;
	}
}

int top_left(char ch) {
	switch(ch) {
		case '1':
		case '2':
		case '3':
		case '7': return 0;
		default: return 1;
	}
}

int top_right(char ch) {
	switch(ch) {
		case '5':
		case '6': return 0;
		default: return 1;
	}
}

int down_left(char ch) {
	switch(ch) {
		case '2':
		case '6':
		case '8':
		case '0': return 1;
		default: return 0;
	}
}

int down_right(char ch) {
	switch(ch) {
		case '2': return 0;
		default: return 1;
	}
}
void print_top() {
	for(int i=0; i<len; i++) {
		pf(" ");
		char ch= " -"[top(num[i])];
		for(int j=0; j<size; j++) pf("%c", ch);
		pf(" ");
		pf("%c", " \n"[i==len-1]);
	}
}

void print_mid() {
	for(int i=0; i<len; i++) {
		pf(" ");
		char ch= " -"[mid(num[i])];
		for(int j=0; j<size; j++) pf("%c", ch);
		pf(" ");
		pf("%c", " \n"[i==len-1]);
	}
}

void print_bottom() {
	for(int i=0; i<len; i++) {
		pf(" ");
		char ch= " -"[bottom(num[i])];
		for(int j=0; j<size; j++) pf("%c", ch);
		pf(" ");
		pf("%c", " \n"[i==len-1]);
	}
}

void print_up() {
	for(int i=0; i<len; i++) {
		pf("%c", " |"[top_left(num[i])]);
		for(int j=0; j<size; j++) pf(" ");
		pf("%c", " |"[top_right(num[i])]);
		pf("%c", " \n"[i==len-1]);
	}
}

void print_down() {
	for(int i=0; i<len; i++) {
		pf("%c", " |"[down_left(num[i])]);
		for(int j=0; j<size; j++) pf(" ");
		pf("%c", " |"[down_right(num[i])]);
		pf("%c", " \n"[i==len-1]);
	}
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	//int start=1;
	while(sc("%d %s", &size, num)==2) {
		if(size==0) break;
		//if(!start) pf("\n");
		//else start=0;

		len=strlen(num);
		print_top();
		for(int i=0; i<size; i++) print_up();
		print_mid();
		for(int i=0; i<size; i++) print_down();
		print_bottom();
		pf("\n");
	}

	return 0;
}
