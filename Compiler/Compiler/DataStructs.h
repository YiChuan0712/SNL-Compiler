#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <fstream> 
#include <string>

#include"queue"
#include"math.h"
#include"vector"
#include"stack"

using namespace std;

/*
�ʷ��������� 
*/


typedef enum
{
	ENDFILE, ERROR,
	PROGRAM, PROCEDURE, TYPE, VAR, IF,
	THEN, ELSE, FI, WHILE, DO, ENDWH,
	BEGIN, END1, READ, WRITE, ARRAY, OF,
	RECORD, RETURN1,
	INTEGER, CHAR1,
	ID, INTC, CHARC,
	ASSIGN, EQ, LT, PLUS, MINUS,
	TIMES, OVER, LPAREN, RPAREN, DOT,
	COLON, SEMI, COMMA, LMIDPAREN, RMIDPAREN,
	UNDERANGE
}lexType;

static struct word
{
	string str;
	lexType tok;
}reservedWords[21] = { {"program",PROGRAM},{"type",TYPE},{"var",VAR},
	{"procedure",PROCEDURE},{"begin",BEGIN},{"end",END1},{"array",ARRAY},
	{"of",OF},{"record",RECORD},{"if",IF},{"then",THEN},{"else",ELSE},{"fi",FI},
	{"while",WHILE},{"do",DO},{"endwh",ENDWH},{"read",READ},{"write",WRITE},
	{"return",RETURN1},{"integer",INTEGER},{"char",CHAR1} };

struct token {
	int line;
	struct word wd;
};

/*
�﷨��������
*/


//����Ϊ�﷨���������ݺͺ�������
class Tree {       //������������ֵܵĽṹ�������
public:
	string Item;           //��ŵ��ַ���
	vector<Tree*> Children;//������Ŷ���
	Tree(string S) { Item = S; }
	void add(Tree* T) {
		Children.push_back(T);
	}
};
Tree* root;        //��������﷨��
int ERRCount = 0;
int ErrorFlag = 0;
string CurrentString = "";   //��ŵ�ǰ����ĵ���
int    CurrentLine = 1;      //��ŵ�ǰ������
#endif