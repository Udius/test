// 2018 ReVoL Primer Template
// 17-farex.cpp (�������������� �������� � ���������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// a17 -farex

/* ���������� ������������ ������� */
// ���������� ��������� ���������
void reset_rex_pointer(void);

// ���������� ���� � ���������
void char_to_rex(char c);

// �������� �������
int has_tran_from_final(SYMB A, NFA & fa);
/* ����� ���������� ������������ ������� */

// ������� �������������
CSET COT[MAX_FA_STATE][MAX_FA_STATE];

// ������� ����
void putplus(char * rex, int & plus) {
}

// ������� �����������
void coeff(char * rex, CSET C) {
}

// ������� ��� ��������� A
void solve(SYMB A, NFA fa, char * rex) {
}

// ����������� �������� ������� � ���������� ���������
// �������� ������� ������ ���� ������������
int fa_to_rex(NFA & fa, char * rex) {
    return 1;
}

// ����� ����� � ��������
// �������������� �������� � ���������
int algorithm_fa_to_rex(NFA & fa, char * rex, FILE * target) {
    // ��������
    int result = fa_to_rex(fa, rex);
    // ������� ��������� � �������
    fprintf(stdout, "%s\n\n", rex);
    // ������� ��������� � ����
    fprintf(target, "%s\n", rex);
    // ���������
    return result;
}
/*/
.a17
{A}
(A,a)={B}
(B,b)={B}
{B}
/*/
