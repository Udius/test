// 2018 ReVoL Primer Template
// 09-cnf.cpp (���������� � ���������� ����� ��������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 002 -cnf -gr

// ������� ��� ������ ���������
void term_rule(SYMB A, SYMB a, grammar & g1, grammar & g2) {
}

// �������� ������� � ���������� ����� ��������
void rule_to_cnf(RULE rule_old, grammar & g1, grammar & g2) {
}

// �������� ��������� �������������
void terms_to_nonts(RULE & rule, grammar & g1, grammar & g2) {
}

// �������� ���������� � ���������� ����� ��������
int chomsky_normal_form(grammar & g1, grammar & g2) {
    return 1;
}

// ����� ����� � ��������
// ���������� � ���������� ����� ��������
int algorithm_chomsky_normal_form(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ��������
    int result = chomsky_normal_form(g1, g2);
    // ������� ���������� � �������
    g2.print(stdout);
    // ������� ���������� � ����
    g2.print(target);
    // �������� ����������
    g1 = g2;
    // ���������
    return result;
}
/*/
.002.sxg
<S>
<S>=<S>[+]<S>
<S>=<S>[*]<S>
<S>=[a]
<S>=[(]<S>[)]
/*/
