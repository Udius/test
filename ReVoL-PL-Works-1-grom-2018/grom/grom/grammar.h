// 2018 ReVoL Primer Template
// grammar.h
// �������� ������� ���������� grammar.lib
#pragma once
// ������ ��������� CSET
#define MAX_CSET 3
// ������ ��������� SSET
#define MAX_SSET 63
// ����� ��������������
#define MAX_ID 7
// ���������� ����������
#define MAX_TERM 31
// ���������� ������������
#define MAX_NONT 31
// ���������� ������
#define MAX_RULE 31
// ����� ������ ����� �������
#define MAX_BODY 8
// ����� �������������� ���������
#define MAX_FA_ID 7
// ���������� ���������
#define MAX_FA_STATE MAX_SSET
// ���������� ���������
#define MAX_FA_DELTA 63
// ����� �������� ���������
#define MAX_INREX 63
// ������ �������� *
#define STAR '*'
// ����������� ���� �������
typedef short SYMB;
// ��������������� ���������� �������
class CSET;
class SSET;
class RULE;
class grammar;
class TRAN;
class NFA;
// ��������� ������
class CSET {
    // ��������
    char items[1 + MAX_CSET];
public:
    // ����������� �� ���������
    CSET();
    // ������� ������
    void clear();
    // ���������� ���������� ���������
    int count();
    // ��������� �������
    int insert(char item);
    // ���������� �������
    char operator [] (int index);
    // ���������� ���������
    int operator == (CSET A);
};
// ���������
class SSET {
    // ��������
    SYMB items[1 + MAX_SSET];
public:
    // ����������� �� ���������
    SSET();
    // ����������� ����������
    SSET(SYMB item);
    // ������� ������
    void clear();
    // ���������� ���������� ���������
    int count();
    // ���������� ������� ��������
    int contains(SYMB item);
    // ���������� ���������� ��������
    int misses(SYMB item);
    // ��������� �������
    int insert(SYMB item);
    // ������� �������
    int remove(int index);
    // ���������� �������
    SYMB operator [] (int index);
    // �������� ���������
    int operator == (SSET A);
};
// ����� ������� ����������
class RULE {
    // �������
    SYMB symbols[4 + MAX_BODY];
public:
    // ����������� �� ���������
    RULE();
    // ������� ������
    void clear();
    // ������� ������ ����� �������
    void clean();
    // ����� ������ �����
    int count();
    // ����������/������������� ������ �������
    SYMB & operator [] (int index);
    // ��������� ������
    void append(SYMB symbol);
    // ������� ������ �� ������
    void remove(int index);
    // ������� ��������� ������
    void remove(void);
    // �������� ���������
    int operator == (RULE rule);
    // ���������� ������� ������� �������
    int is_unit();
    // ���������� ������� ���������������� �������
    int is_leftr();
};
// ����� ����������
class grammar {
    // �������
    RULE rules[1 + MAX_RULE];
    // �������������� ��������
    char ident[2 + MAX_TERM + MAX_NONT][1 + MAX_ID];
public:
    // ����������� �� ���������
    grammar();
    // ������� ������
    void clear();
    // ���������� ���������� ������
    int count();
    // ���������� ���������� ����������
    int term_count();
    // ���������� ���������� ������������
    int nont_count();
    // ���������� ������ �������� �������
    SYMB start();
    // ������������� ������� ������
    void set_start(SYMB sym);
    // ������������ ������� ������ �� ��������������
    SYMB set_start_id(const char * id);
    // ������������ ������� ������ ������ ����������
    SYMB set_start_from(grammar gr);
    // ���������� ������� �� ������
    RULE & operator [] (int index);
    // ��������� �������
    void rule_add(RULE rule);
    // ��������� ������� ������ ����������
    void rule_add_from(grammar gr, RULE rule);
    // ���������� ����� ������� ��� 0
    int rule_exist(RULE rule);
    // ����������� ������� ������ ���������� � ������� ���� ����������
    void rule_cast(grammar gr, RULE & rule);
    // ������������ ����������
    SYMB reg_nont(const char * id);
    // ������������ ��������
    SYMB reg_term(const char * id);
    // ������������ ������ ��� ��������
    SYMB reg_char(char c);
    // ������������ ������ ������ ����������
    SYMB reg_from(grammar gr, SYMB symbol);
    // ������������ ��������� �� ��� ���������� ����������
    SYMB reg_from(NFA fa, SYMB state);
    // ��������� ������������� ���������� � ������������ ���
    SYMB get_star_nont(SYMB sym);
    // ��������� ����� ���������� � ������������ ���
    SYMB get_new_nont();
    // ���������� ������������� �������
    char * getid(SYMB symbol);
    // ���������� ������ ������ ���������
    char get_char(SYMB tok);
    // ���������� ������� ���������������� �� ������� �������
    int is_symbol_leftr(SYMB sym);
    // ����������� ����������� ����������
    int analyse();
    // ������� ����� ������� � ��������� �����
    void rule_print(FILE * stream, RULE rule);
    // ������� ����� ���������� � ��������� �����
    void print(FILE * stream);
    // ��������� ���� ����������
    int parse(FILE * input_stream, FILE * err_stream);
    // ���������� ������ �� �������������� ���������
    SYMB find_term(const char * id);
    // ���������� ������ �� �������������� �����������
    SYMB find_nont(const char * id);
private:
    // ��������� �� ������ ������
    int parse_line(FILE * input_stream, FILE * err_stream);
};
// ����� �������� ��
class TRAN {
public:
    SYMB a; // ���������
    char c; // ������ ��������
    SYMB b; // ��������� ��������
    char f; // ��������
    // ����������� �� ���������
    TRAN();
    // �������� ���������
    int operator == (TRAN t);
};
// ����� ��������� �������� (��)
class NFA {
    // ��������
    TRAN delta[1 + MAX_FA_DELTA];
    // �������������� ���������
    char ident[1 + MAX_FA_STATE][1 + MAX_FA_ID];
public:
    // ��������� ���������
    SSET initials;
    // ��������� ���������
    SSET finals;
    // ������� ���������
    SSET chars;
    // ����������� �� ���������
    NFA();
    // ������� ������
    void clear();
    // ���������� ���������� ���������
    int delta_count();
    // ���������� ���������� ���������
    int state_count();
    // ����������/������������� �������
    TRAN & operator [] (int index);
    // ��������� �������
    SYMB tran_add_immediate(SYMB a, char c, SYMB b);
    // ��������� �������
    SYMB tran_add(TRAN tran);
    // ��������� ������� ������� ��
    SYMB tran_add_from(NFA fa, TRAN tran);
    // ������������ ���������
    SYMB reg_state_id(const char * id);
    // ������������ ��������� ������� ��
    SYMB reg_state_from(NFA fa, SYMB state);
    // ������������ ������ ���������� ��� ���������
    SYMB reg_state_from(grammar gr, SYMB sym);
    // ������������ ��������� ���������
    SYMB reg_initial_id(const char * id);
    // ������������ ��������� ��������� ������� ��
    SYMB reg_initial_from(NFA fa, SYMB state);
    // ������������ ������ ���������� ��� ��������� ���������
    SYMB reg_initial_from(grammar gr, SYMB sym);
    // ������������ ��������� ���������
    SYMB reg_final_id(const char * id);
    // ������������ ��������� ��������� ������� ��
    SYMB reg_final_from(NFA fa, SYMB state);
    // ������������ ������ ���������� ��� ��������� ���������
    SYMB reg_final_from(grammar gr, SYMB sym);
    // ��������� ����� ��������� � ������������ ���
    SYMB get_new_state();
    // ���������� ������������� ���������
    char * getid(SYMB state);
    // ����������� ��
    int analyse();
    // ������� ����� �������� �� � ��������� �����
    void trans_printi(FILE * stream, TRAN tran);
    // ������� ����� �������� �� � ��������� �����
    void trans_printn(FILE * stream, TRAN tran);
    // ������� ����� �� � ��������� �����
    void printn(FILE * stream);
    // ������� ����� �� � ��������� �����
    void printi(FILE * stream);
    // ��������� ���� ��
    int parse(FILE * input_stream, FILE * err_stream);
private:
    // ���������� ��������� �� �������������� ��� 0
    SYMB find_state(const char * id);
    // ��������� �� ������ ������
    int parse_line(FILE * input_stream, FILE * err_stream);
};
