// 2018 ReVoL Primer Template
// 03-us.cpp (���������� ���������� ��������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 03 -us

// ���������� 1, ���� ������� ��������
int are_known_syms(RULE rule, SSET R) {
    return 1;
}

// ��������� ��������� �������� ������������
void find_usefull_syms(grammar & g1, SSET & R) {
}

// ���������� � g2 �������, ����������� ������� ����������� R
void find_usefull_rules(grammar & g2, grammar & g1, SSET R) {
}

// ������� ���������� �������
void remove_useless(grammar & g1, grammar & g2) {
}

// ����� ����� � ��������
// ���������� ���������� ��������
int algorithm_remove_useless(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ���������� ���������� ��������
    remove_useless(g1, g2);
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
.03.sxg
<S>
<S>=[a]
<S>=<A>
<A>=<A><B>
<B>=<C>
<C>=[b]
/*/
