// 2018 ReVoL Primer Template
// 14-fainv.cpp (�������������� ��������)
#include "stdafx.h"
#include "grammar.h"
#include "main.h"
// ��������� ������
// a13e -fainv -dfa -fainv -dfa

// �������� �������
void fa_invert(NFA & fa) {
}

// ����� ����� � ��������
// �������������� ��������
int algorithm_fa_invert(NFA & fa, FILE * target) {
    // ��������
    fa_invert(fa);
    // ������� �� � �������
    fa.printn(stdout);
    // ������� �� � ����
    fa.printn(target);
    return 1;
}
