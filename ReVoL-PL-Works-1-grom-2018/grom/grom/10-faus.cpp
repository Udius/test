// 2018 ReVoL Primer Template
// 10-faus.cpp (���������� ������������ ��������� ��������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// a13a -faus
// a10 -faus

// ��������������� �������� � ���������
void fa_general(NFA & fa) {
}

// ���������� ������������ ��������� ��������� ��������
void fa_remove_unreachable(NFA & fa1, NFA & fa2) {
    fa_general(fa2);
}

// ����� ����� � ��������
// ���������� ������������ ��������� ��
int algorithm_fa_remove_unreachable(NFA & fa1, FILE * target) {
    // �������� ��
    NFA fa2;
    // ��������
    fa_remove_unreachable(fa1, fa2);
    // ������� �� � �������
    fa2.printi(stdout);
    // ������� �� � ����
    fa2.printi(target);
    // �������������� ��
    fa1 = fa2;
    // ���������
    return 1;
}
/*/
.a13b.sxg
{A}
(A,a)={A}
(A,b)={B}
(B,a)={A}
(B,a)={S}
{S}
/*/
