// 2018 ReVoL Primer Template
// 05-re.cpp (���������� ������ ������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 05 -re -gr

// ���������� 1, ���� ������� �������������
int is_nullable_rule(RULE rule, SSET E) {
    return 1;
}

// ��������� ��������� ������������� ������������ E
void nullable_syms(grammar & g1, SSET & E) {
}

// �������� ������� �������� � g2
void useful_rules(grammar & g2, grammar g1) {
}

// ������� ������ N ������ P �� ������� rule
// ���� ���������� ������� �� �����, ��������� ��� � g2
// ���������� �������� ���� ��� ����������� ������� �������
// ��������������� ��� �������� N-1, N-2...
void remove_nullable_from(grammar & g2, RULE rule, SSET P, int N) {
}

// ��������� ������ ������������� �������� �������
void rule_nullable_syms(RULE rule, SSET E, SSET & P) {
}

// ��������� �������, �������������� ��������� ������ �������
void complement_rules(grammar & g2, SSET E) {
}

// ��������� ������ �������
void remove_empty(grammar & g1, grammar & g2) {
}

// ����� ����� � ��������
// ���������� ������ ������
int algorithm_remove_empty(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ��������
    remove_empty(g1, g2);
    // ������� ���������� � �������
    g2.print(stdout);
    // ������� ���������� � ����
    g2.print(target);
    // �������� ����������
    g1 = g2;
    // ���������
    return 1;
}
/*/
.05.sxg
<S>
<S>=<A><B>
<A>=[a]
<A>=<B><B>
<B>=[b]
<B>=.
/*/
