// 2018 ReVoL Primer Template
// 02-gr.cpp (������������� ������)
#include "stdafx.h"
#include "grammar.h"
// ��������� ������
// 02 -gr

// ���������� ������� � ������� ��������� ������������
void group_rules(grammar & g1, grammar & g2) {
    SSET Q;
    SSET P;
    SYMB S = g1.start();

    Q.insert(S);

    SYMB A;
    int rule_count = g1.count();
    while (Q.count() != 0) {
        A = Q[1];

    }

    /*
    int rule_count = g1.count();
    for (int r = 1; r <= rule_count; r++) {
        RULE rule = g1[r];
        Q.rule_add_from(g1, rule);
    }
    Q.set_start_from(g1);
    
    // ��� �������� ������� ������?
    for (int r = 1; r <= rule_count; r++) {
        RULE rule = Q[r];
        int symbol_count = rule.count();
        for (int s = 1; s <= symbol_count; s++) {
            if (rule[s] < 0) {
                printf("nont ");
            }
            else {
                printf("term ");
            }
        }
    }
    */
}

// ����� ����� � ��������
// ������������� ������
int algorithm_group_rules(grammar & g1, FILE * target) {
    // �������������� ����������
    grammar g2;
    // ��������
    group_rules(g1, g2);
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
.02.sxg
<S>
<A>=<S><A>
<A>=<B>
<B>=[b]
<A>=[a]
<S>=<B>
<S>=<A><B>
/*/
