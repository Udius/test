// 2018 ReVoL Primer Template
// 15-minfa.cpp (����������� ��� ������� ����������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 

// ������������ ���
int minimize_dfa(NFA & fa1, NFA & fa2, FILE * target) {
    return 1;
}

// ����� ����� � ��������
// ����������� ��� ������� ����������
int algorithm_min_dfa(NFA & fa1, FILE * target) {
    // �������������� ��
    NFA fa2;
    // ��������
    int result = minimize_dfa(fa1, fa2, target);
    // ������� �� � �������
    fa2.printi(stdout);
    // ������� �� � ����
    fa2.printi(target);
    // �������� ��
    fa1 = fa2;
    // ���������
    return result;
}
