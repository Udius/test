// 2018 ReVoL Primer Template
// 06-r�.cpp (���������� ������ ������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 05 -re -gr -rc -gr

// ���� �� ������ ������� g1 � ��������� �� � g2
void nonunit_rules(grammar & g1, grammar & g2) {
}

// ���� ������� ����������� A
void find_chain_for(grammar & g1, SSET & R) {
}

// ��������� ����� �� ������ �������
void nonunit_rules_for(grammar & g2, grammar & g1, SSET R) {
}

// ��������� ������ �������
void remove_units(grammar & g1, grammar & g2) {
}

// ����� ����� � ��������
// ���������� ������ ������
int algorithm_remove_units(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ��������
    remove_units(g1, g2);
    // ������� ���������� � �������
    g2.print(stdout);
    // ������� ���������� � ����
    g2.print(target);
    // �������� ����������
    g1 = g2;
    // ���������
    return 1;
}
