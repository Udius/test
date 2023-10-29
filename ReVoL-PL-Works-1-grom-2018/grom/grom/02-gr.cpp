// 2018 ReVoL Primer Template
// 02-gr.cpp (группирование правил)
#include "stdafx.h"
#include "grammar.h"
// командные строки
// 02 -gr

// группирует правила в порядке появления нетерминалов
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
    
    // Как получить целевой символ?
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

// точка входа в алгоритм
// группирование правил
int algorithm_group_rules(grammar & g1, FILE * target) {
    // результирующая грамматика
    grammar g2;
    // алгоритм
    group_rules(g1, g2);
    // выводим грамматику в консоль
    g2.print(stdout);
    // выводим грамматику в файл
    g2.print(target);
    // выходная грамматика
    g1 = g2;
    // результат
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
