// 2018 ReVoL Primer Template
// 11-faau.cpp (�������������� �������� � ����������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// a11 -faau

// ���������� ������� �������� �� ���������� ���������
int has_tran_from_final(SYMB A, NFA & fa) {
    return 0;
}

// ����������� ������� � ����������
void fa_to_grau(NFA & fa, grammar & gr) {
}

// ����� ����� � ��������
// �������������� �������� � ����������
int algorithm_fa_to_grau(NFA & fa, grammar & gr, FILE * target) {
    // ��������
    fa_to_grau(fa, gr);
    // ������� ���������� � �������
    gr.print(stdout);
    // ������� ���������� � ����
    gr.print(target);
    // ���������
    return 1;
}
/*/
.a11.sxg
{A}
(A,a)={B}
(B,b)={E}
(E,d)={F}
(E,c)={B}
{E,F}
/*/
