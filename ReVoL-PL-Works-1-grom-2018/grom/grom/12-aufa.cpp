// 2018 ReVoL Primer Template
// 12-aufa.cpp (�������������� ���������� � �������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// a11 -faau -aufa

// ������� ���� A->a ��� A->aB, ���������� ����� �������
int has_pair_rule(RULE rule, int length, grammar gr) {
    return 0;
}

// ����������� ���������� � �������
int grau_to_fa(grammar & gr, NFA & fa) {
    return 1;
}

// ����� ����� � ��������
// �������������� ���������� � �������
int algorithm_grau_to_fa(grammar & gr, NFA & fa, FILE * target) {
    // ��������
    int result = grau_to_fa(gr, fa);
    // ������� �� � �������
    fa.printi(stdout);
    // ������� �� � ����
    fa.printi(target);
    // ���������
    return result;
}
