// 2018 ReVoL Primer Template
// 07-lr.cpp (���������� ����� ��������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 07 -lr -gr

// ��������� ���������������� �������� ������ ��� A
void eliminate_direct(SYMB Ai, grammar & g1) {
}

// ��������� ����� ������� �� ����
void compile_rule(RULE rule_k, RULE rule_j, RULE & rule_new) {
}

// �������� ������� Ak->Ajx �� ������� Ak->wx, w - ������ ����� Aj
// k - ����� ������� Ak->Ajx
void replace_Aj(int k, grammar & g1) {
}

// ����������� ������� �������� � �����
// ��� ������������ �� ������� �� Ak
// �������� ������� ���� Ak->Ajx �� Ak->wx, w - ������ ����� Aj
void indirect_to_direct(SYMB Ak, grammar & g1) {
}

// ��������� ����� ��������
void eliminate_leftr(grammar & g1) {
}

// ����� ����� � ��������
// ���������� ����� ��������
int algorithm_eliminate_leftr(grammar & g1, FILE * target) {
    // ��������
    eliminate_leftr(g1);
    // ������� ���������� � �������
    g1.print(stdout);
    // ������� ���������� � ����
    g1.print(target);
    // ���������
    return 1;
}
/*/
.07.sxg
<A>
<A>=<B>[b]
<A>=[a]
<B>=<A>[a]
<B>=<B>[b]
<B>=[b]
/*/
