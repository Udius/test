// 2018 ReVoL Primer Template
// 04-ur.cpp (���������� ������������ ��������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 03 -us -ur -gr

// ��������� ����������� ������� rule � ��������� R
void find_rule_syms(RULE rule, SSET & R) {
}

// ��������� ��������� ���������� ��������
void find_reachable_syms(grammar & g1, SSET & R) {
}

// ���������� � g2 �������, ����� ������� ������� ����������� R
void find_reachable_rules(grammar & g2, grammar & g1, SSET R) {
}

// ������� ������������ �������
void remove_unreachable(grammar & g1, grammar & g2) {
}

// ����� ����� � ��������
// ���������� ������������ ��������
int algorithm_remove_unreachable(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ���������� ������������ ��������
    remove_unreachable(g1, g2);
    // ������� ���������� � �������
    g2.print(stdout);
    // ������� ���������� � ����
    g2.print(target);
    // �������� ����������
    g1 = g2;
    // ���������
    return 1;
}
