// 2018 ReVoL Primer Template
// main.h (�������� ��������, ����� � ������� ��������� ������)
#pragma once
#include <windows.h>

// ��������� ���� �������� �����
enum SOURCE_TYPE { SOURCE_INVALID, SOURCE_GRAMMAR, SOURCE_FA, SOURCE_REGEX };

// ������������ ����� ������������
#define MAX_FILE_SPEC 260

// ��������� ������� ���� ��� ������
int source_open(FILE ** source_file, const char * path, SOURCE_TYPE & source_type);

// ��������� �������������� ���� ��� ������
int target_open(FILE ** target_file, const char * path);

// ����� ��������� ��������
enum ACTION_KEY { 
    /* ����� �������� � �����������             */ ACT_NONE = 0,
    /* ������������� ������ ����������          */ ACT_GR,
    /* ���������� ���������� ��������           */ ACT_US,
    /* ���������� ������������ ��������         */ ACT_UR,
    /* ���������� ������ ������                 */ ACT_RE,
    /* ���������� ������ ������                 */ ACT_RC,
    /* ���������� ����� ��������                */ ACT_LR,
    /* ����� ������������                       */ ACT_LF,
    /* ���������� � ���������� ����� ��������   */ ACT_CNF,
    /* �������� ������������ ��������� �������� */ ACT_FAUS,
    /* �������������� �������� � ����������     */ ACT_FAAU,
    /* �������������� ���������� � �������      */ ACT_AUFA,
    /* �������������� ��������                  */ ACT_DFA,
    /* �������������� ��������                  */ ACT_FAINV,
    /* ����������� ���                          */ ACT_MINFA,
    /* �������������� ��������� � �������       */ ACT_REXFA,
    /* �������������� �������� � ���������      */ ACT_FAREX
};

// ���������
// 01. ��������������� ��������
int algorithm_general(grammar & g1, FILE * target);
// 02. ������������� ������
int algorithm_group_rules(grammar & g1, FILE * target);
// 03. ���������� ���������� ��������
int algorithm_remove_useless(grammar & g1, FILE * target);
// 04. ���������� ������������ ��������
int algorithm_remove_unreachable(grammar & g1, FILE * target);
// 05. ���������� ������ ������
int algorithm_remove_empty(grammar & g1, FILE * target);
// 06. ���������� ������ ������
int algorithm_remove_units(grammar & g1, FILE * target);
// 07. ���������� ����� ��������
int algorithm_eliminate_leftr(grammar & g1, FILE * target);
// 08. ����� ������������
int algorithm_left_factoring(grammar & g1, FILE * target);
// 09. ���������� � ���������� ����� ��������
int algorithm_chomsky_normal_form(grammar & g1, FILE * target);
// 10. ���������� ������������ ��������� ��������
int algorithm_fa_remove_unreachable(NFA & fa, FILE * target);
// 11. �������������� �������� � ����������
int algorithm_fa_to_grau(NFA & fa, grammar & gr, FILE * target);
// 12. �������������� ���������� � �������
int algorithm_grau_to_fa(grammar & gr, NFA & fa, FILE * target);
// 13. �������������� ��� � ���
int algorithm_dfa(NFA & fa, FILE * target);
// 14. �������������� ��������
int algorithm_fa_invert(NFA & fa, FILE * target);
// 15. ����������� ���
int algorithm_min_dfa(NFA & fa, FILE * target);
// 16. �������������� ��������� � �������
int algorithm_rex_to_fa(char * rex, NFA & fa, FILE * target);
// 17. �������������� �������� � ���������
int algorithm_fa_to_rex(NFA & fa, char * rex, FILE * target);

// ��������
// 01. ��������������� �������� � �����������
int action_grammar_general(grammar & g1);
// 02. ������������� ������
int action_group_rules(grammar & g1);
// 03. ���������� ���������� ��������
int action_remove_useless(grammar & g1);
// 04. ���������� ������������ ��������
int action_remove_unreachable(grammar & g1);
// 05. ���������� ������ ������
int action_remove_empty(grammar & g1);
// 06. ���������� ������ ������
int action_remove_units(grammar & g1);
// 07. ���������� ����� ��������
int action_eliminate_leftr(grammar & g1);
// 08. ����� ������������
int action_left_factoring(grammar & g1);
// 09. ���������� � ���������� ����� ��������
int action_chomsky_normal_form(grammar & g1);
// 10. �������� ������������ ��������� ��������
int action_fa_remove_unreachable(NFA & fa);
// 11. �������������� �������� � ����������
int action_fa_to_grau(NFA & fa, grammar & gr);
// 12. �������������� ���������� � �������
int action_grau_to_fa(grammar & gr, NFA & fa);
// 13. �������������� ��� � ���
int action_dfa(NFA & fa);
// 14. �������������� ��������
int action_fa_invert(NFA & fa);
// 15. ����������� ���
int action_min_dfa(NFA & fa);
// 16. �������������� ��������� � �������
int action_rex_to_fa(char * rex, NFA & fa);
// 17. �������������� �������� � ���������
int action_fa_to_rex(NFA & fa, char * rex);

// ���������� �������� �� �����
ACTION_KEY get_key(char * buf);
// ���������� ��������� ���������
void reset_rex_pointer(void);
// ���������� ���� � ���������
void char_to_rex(char c);
// ������� ����� ���������
void clear_regex();
// ����������
void except(const char * err);
// �������
void help();
