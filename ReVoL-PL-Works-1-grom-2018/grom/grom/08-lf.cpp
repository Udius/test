// 2018 ReVoL Primer Template
// 08-lf.cpp (����� ������������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 08 -lf -gr

// �������� pref ��������� ������� rule ?
int is_prefix_for(RULE rule, RULE pref) {
    return 1;
}

// ������������ ������� ��� ������� j
// ���������� ����� �������� ������� j
int max_prefix_for_rule_number(int j, grammar g1) {
    return 0;
}

// ���� ������� ������������ ����� ��� A
// ���������� ����� ��������
int find_prefix_for(SYMB A, grammar g1, RULE & pref) {
    return 0;
}

// ��������� ������� pref ����������� pref[0]
void eliminate_prefix(grammar & g1, RULE pref) {
}

// �������� ����� ������������
int left_factoring(grammar & g1) {
    return 1;
}

// ����� ����� � ��������
// ����� ������������
int algorithm_left_factoring(grammar & g1, FILE * target) {
    // ��������
    int result = left_factoring(g1);
    // ������� ���������� � �������
    g1.print(stdout);
    // ������� ���������� � ����
    g1.print(target);
    // ���������
    return result;
}
/*/
.08.sxg
<A>
<A>=[a][b][a][b]
<A>=[a][b][c][d]
<A>=[a][b][c][e]
<A>=[a][b][c][f]
/*/
