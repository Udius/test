// 2018 ReVoL Primer Template
// 13-dfa.cpp (�������������� ��� � ���)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// a13a -dfa
// a13e -dfa
// a13b -dfa

// ������������� ���������
SSET inspected;

// ��������� ��������� A ��������� ��� state
void closure(SYMB state, SSET & A, NFA & fa1) {
}

// ��������� ��������� A ��������� ��� A
void closureA(SSET & A, NFA & fa1) {
}

// ��������� 2^(n-1)
int power2n(int n) {
    return 0;
}

// ��������� ������������� ��������� ���, ������������ ���
// ������������ ��������� ���������, ���� ����
int reg_state(SSET & A, NFA & fa1, NFA & fa2) {
    return 0;
}

// ���� ������ ���������
// A - ��������� ��� - ��������� ��������� ���
// initial - ������� ���������� ���������
int follow_dfa_state(SSET A, NFA fa1, NFA & fa2, int initial = 0) {
    return 1;
}

// ����������� ��� � ���
int nfa_to_dfa(NFA & fa1, NFA & fa2) {
    inspected.clear();
    return follow_dfa_state(fa1.initials, fa1, fa2, 1);
}

// ����� ����� � ��������
// �������������� ��� � ���
int algorithm_dfa(NFA & fa1, FILE * target) {
    // �������� ��
    NFA fa2;
    // ��������
    int result = nfa_to_dfa(fa1, fa2);
    // ������� �� � �������
    fa2.printn(stdout);
    // ������� �� � ����
    fa2.printn(target);
    // �������� ��
    fa1 = fa2;
    // ���������
    return result;
}
/*/
.a13a.sxg
{A}
(A,a)={A}
(A,a)={B}
(A,b)={A}
(B,b)={C}
{C}
/*/
/*/
.a13e.sxg
{1}
(1, )={2,8}
(2, )={3,5}
(3,a)={4}
(4, )={7}
(7, )={2}
(5,b)={6}
(6, )={7}
(7, )={8}
{8}
/*/
