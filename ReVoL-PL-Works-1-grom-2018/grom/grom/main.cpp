// 2018 ReVoL Primer Template
// main.cpp
#include "stdafx.h"
#include "grammar.h"
#include "main.h"

#define MAXREX 512
// ���������� ���������
char rex[MAXREX];
// ��������� ���������
int rexindex = 0;
// ������� ����������
grammar gr;
// ������� �������� �������
NFA fa;
// ������� �������
// ���������:
// 1  - ������� ����
// 2+ - ����� ���� "-�������������_�����"
void mainf(int argc, char* argv[]) {
    SOURCE_TYPE source_type = SOURCE_GRAMMAR;
    FILE * source_file = 0;
    int i = 0, parse_result = 0;
    char c = 0;
    if (argc < 2) {
        help();
        return;
    }
    // ��������� �������� ���� ��� ������
    if (!source_open(&source_file, argv[1], source_type)) {
        // ������ �������� �������� �����
        return;
    }
    if (source_type == SOURCE_FA) {
        // ��������� ���� ��������� ��������
        printf("-- parse automation\n");
        parse_result = fa.parse(source_file, stdout);
    } else if (source_type == SOURCE_GRAMMAR) {
        // ��������� ���� ����������
        printf("-- parse grammar\n");
        parse_result = gr.parse(source_file, stdout);
    } else {
        // ��������� �� ���������
        parse_result = 1;
        // ������� �����
        clear_regex();
        for (i = 0; i <= MAX_INREX; i++) rex[i] = 0;
        // ��������� ���������� ���������
        int n = 0;
        while (1) {
            if (n >= MAX_INREX) {
                parse_result = 0;
                printf("-- regex too long\n");
                break;
            }
            c = getc(source_file);
            if (c == EOF || c == 10 || c == 13) {
                break;
            } else if (c == '1' || c == '(' || c == ')' || c == '+' || c == STAR) {
                rex[n++] = c;
            } else if (c > 64 && c < 91) {
                rex[n++] = (c |= 32);
            } else if (c > 96 && c < 123) {
                rex[n++] = c;
            } else {
                continue;
            }
        }
        rex[n++] = 10;
    }
    // ��������� �������� ����
    fclose(source_file);
    if (parse_result <= 0) {
        // ���������� ������
        return;
    }
    if (argc < 3) {
        // ������ ���
        action_grammar_general(gr);
    } else try {
        // ������������� �����
        for (int k = 2; k < argc; k++) {
            // ������� ����
            ACTION_KEY key = get_key(argv[k]);
            switch (key) {
            case ACT_GR:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_group_rules(gr) == 0) return;
                break;
            case ACT_US:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_remove_useless(gr) == 0) return;
                break;
            case ACT_UR:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_remove_unreachable(gr) == 0) return;
                break;
            case ACT_RE:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_remove_empty(gr) == 0) return;
                break;
            case ACT_RC:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_remove_units(gr) == 0) return;
                break;
            case ACT_LR:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_eliminate_leftr(gr) == 0) return;
                break;
            case ACT_LF:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_left_factoring(gr) == 0) return;
                break;
            case ACT_CNF:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_chomsky_normal_form(gr) == 0) return;
                break;
            case ACT_FAUS:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                if (action_fa_remove_unreachable(fa) == 0) return;
                break;
            case ACT_AUFA:
                if (source_type != SOURCE_GRAMMAR) { printf("Grammar source expected.\n\n"); return; }
                if (action_grau_to_fa(gr, fa) == 0) return;
                // ������� ��������� �������� �������� �������
                source_type = SOURCE_FA;
                // ������� ���������� �������
                gr.clear();
                break;
            case ACT_FAAU:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                if (action_fa_to_grau(fa, gr) == 0) return;
                // ������� ��������� �������� ����������
                source_type = SOURCE_GRAMMAR;
                // ������� �� �������
                fa.clear();
                break;
            case ACT_DFA:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                if (action_dfa(fa) == 0) return;
                break;
            case ACT_FAINV:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                if (action_fa_invert(fa) == 0) return;
                break;
            case ACT_MINFA:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                if (action_min_dfa(fa) == 0) return;
                break;
            case ACT_REXFA:
                if (source_type != SOURCE_REGEX) { printf("Regular expression source expected.\n\n"); return; }
                if (action_rex_to_fa(rex, fa) == 0) return;
                // ������� ��������� �������� �������
                source_type = SOURCE_FA;
                break;
            case ACT_FAREX:
                if (source_type != SOURCE_FA) { printf("Automation source expected.\n\n"); return; }
                // ������� �����
                clear_regex();
                if (action_fa_to_rex(fa, rex) == 0) return;
                // ������� ��������� �������� ���������
                source_type = SOURCE_REGEX;
                break;
            default:;
                printf("Unknown key \"%s\".\n\n", argv[k]);
            }
        }
    } catch (const char * err) {
        except(err);
    } catch (...) {
        except("Software");
    }
}

int main(int argc, char* argv[]) {
    __try {
        mainf(argc, argv);
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        unsigned int code = GetExceptionCode();
        if (code == EXCEPTION_ACCESS_VIOLATION) {
            except("Access violation");
        } else if (code == EXCEPTION_STACK_OVERFLOW) {
            except("Stack overflow");
        } else {
            except("Hardware");
        }
    }
}
// ���� � ����� ����������
char main_path[MAX_FILE_SPEC] = {0};
// ������������ ����� ����������
char ente_path[MAX_FILE_SPEC] = {0};
// ���������� ��� �����
SOURCE_TYPE get_source_type(FILE * source) {
    char c = 0;
    while (1) {
        c = getc(source);
        if (c == EOF) {
            fprintf(stdout, "\nUnexpected end of file.\n\n");
            return SOURCE_INVALID;
        } else if (c == 10) {
            fprintf(stdout, "\nInvalid file format.\n\n");
            return SOURCE_INVALID;
        } else if (c == 9 || c == 13 || c == 32) {
        } else {
            break;
        }
    }
    if (c == '<') {
        return SOURCE_GRAMMAR;
    } else if (c == '{') {
        return SOURCE_FA;
    } else {
        if (c == '(' || c == '1') {
            return SOURCE_REGEX;
        } else if (c > 64 && c < 91) {
            return SOURCE_REGEX;
        } else if (c > 96 && c < 123) {
            return SOURCE_REGEX;
        } else {
            return SOURCE_INVALID;
        }
    }
}
// ��������� ������� ���� ��� ������
int source_open(FILE ** source_file, const char * path, SOURCE_TYPE & source_type) {
    // �������� ������������ �����
    strcpy(main_path, path);
    // ��������� ����� � ����� �����
    char * p = strrchr(main_path, '.');
    if (p) {
        // �������� ����������
        main_path[p - main_path] = 0;
    }
    // �������� ����
    strcpy(ente_path, main_path);
    // ��������� ����������
    strcat(ente_path, ".sxg");
    // ��������� ���� ��� ������
    *source_file = fopen(ente_path, "rt");
    if (!*source_file) {
        if (errno == ENOENT) {
            printf("Source file or path not found \"%s\".\n\n", ente_path);
            return 0;
        } else {
            printf("Error open source file \"%s\".\n\n", ente_path);
            return 0;
        }
    }
    source_type = get_source_type(*source_file);
    if (source_type == SOURCE_INVALID) {
        printf("SYNAX format invalid in source file \"%s\".\n\n", ente_path);
        return 0;
    }
    freopen(ente_path, "rt", *source_file);
    return 1;
}
// ��������� ���� ��� ������ ����������
// ��������� � ����� ����� ��������
int target_open(FILE ** target_file, const char * tail) {
    // ��������� ��������� ����� � ����
    strcat(main_path, tail);
    // �������� ����
    strcpy(ente_path, main_path);
    // ��������� ����������
    strcat(ente_path, ".sxg");
    // ��������� ������� �����
    FILE * f = fopen(ente_path, "rt");
    if (f) {
        fclose(f);
        DeleteFile((LPCSTR)ente_path);
    }
    // ��������� ���� ��� ������
    *target_file = fopen(ente_path, "wt");
    if (!*target_file) {
        if (errno == ENOENT) {
            printf("Target path not found \"%s\".\n\n", ente_path);
            return 0;
        } else {
            printf("Error open target file \"%s\".\n\n", ente_path);
            return 0;
        }
    }
    return 1;
}
// ���������� �������� �� �����
// ���� �������� � ��������� ������ � ����� ��� "-identifier"
ACTION_KEY get_key(char * buf) {
    if (_stricmp("-gr",    buf) == 0) return ACT_GR;    // ������������� ������ ����������
    if (_stricmp("-us",    buf) == 0) return ACT_US;    // ���������� ���������� ��������
    if (_stricmp("-ur",    buf) == 0) return ACT_UR;    // ���������� ������������ ��������
    if (_stricmp("-re",    buf) == 0) return ACT_RE;    // ���������� ������ ������
    if (_stricmp("-rc",    buf) == 0) return ACT_RC;    // ���������� ������ ������
    if (_stricmp("-lr",    buf) == 0) return ACT_LR;    // ���������� ����� ��������
    if (_stricmp("-lf",    buf) == 0) return ACT_LF;    // ����� ������������
    if (_stricmp("-cnf",   buf) == 0) return ACT_CNF;   // ���������� � ���������� ����� ��������
    if (_stricmp("-faus",  buf) == 0) return ACT_FAUS;  // �������� ������������ ��������� ��������
    if (_stricmp("-aufa",  buf) == 0) return ACT_AUFA;  // �������������� �������� � ����������
    if (_stricmp("-faau",  buf) == 0) return ACT_FAAU;  // �������������� ���������� � �������
    if (_stricmp("-dfa",   buf) == 0) return ACT_DFA;   // �������������� ��������
    if (_stricmp("-fainv", buf) == 0) return ACT_FAINV; // �������������� ��������
    if (_stricmp("-minfa", buf) == 0) return ACT_MINFA; // ����������� ���
    if (_stricmp("-rexfa", buf) == 0) return ACT_REXFA; // �������������� ��������� � �������
    if (_stricmp("-farex", buf) == 0) return ACT_FAREX; // �������������� �������� � ���������
    return ACT_NONE;
}
// ������� ����� ���������
void clear_regex() {
    int count = sizeof(rex) / sizeof(char);
    for (int i = 0; i < count; i++) rex[i] = 0;
}
// ���������� ��������� ���������
void reset_rex_pointer(void) {
    rexindex = 0;
}
// ���������� ���� � ���������
void char_to_rex(char c) {
    if (rexindex >= MAXREX) {
        throw "regex overflow";
    }
    rex[rexindex++] = c;
}
// 01 ��������������� �������� � �����������
int action_grammar_general(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-gen")) return 0;
    printf("-- grammar general\n");
    algorithm_general(gr, target_file);
    fclose(target_file);
    return 0;
}
// 02 ������������� ������
int action_group_rules(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-gr")) return 0;
    printf("-- group rules\n");
    int result = algorithm_group_rules(gr, target_file);
    fclose(target_file);
    return result;
}
// 03 ���������� ���������� ��������
int action_remove_useless(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-us")) return 0;
    printf("-- remove useless\n");
    int result = algorithm_remove_useless(gr, target_file);
    fclose(target_file);
    return result;
}
// 04 ���������� ������������ ��������
int action_remove_unreachable(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-ur")) return 0;
    printf("-- remove unreachable\n");
    int result = algorithm_remove_unreachable(gr, target_file);
    fclose(target_file);
    return result;
}
// 05 ���������� ������ ������
int action_remove_empty(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-re")) return 0;
    printf("-- remove empty\n");
    int result = algorithm_remove_empty(gr, target_file);
    fclose(target_file);
    return result;
}
// 06 ���������� ������ ������
int action_remove_units(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-rc")) return 0;
    printf("-- remove units\n");
    int result = algorithm_remove_units(gr, target_file);
    fclose(target_file);
    return result;
}

// 07 ���������� ����� ��������
int action_eliminate_leftr(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-lr")) return 0;
    printf("-- eliminate left recursion\n");
    int result = algorithm_eliminate_leftr(gr, target_file);
    fclose(target_file);
    return result;
}
// 08 ����� ������������
int action_left_factoring(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-lf")) return 0;
    printf("-- left factoring\n");
    int result = algorithm_left_factoring(gr, target_file);
    fclose(target_file);
    return result;
}
// 09 ���������� � ���������� ����� ��������
int action_chomsky_normal_form(grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-cnf")) return 0;
    printf("-- Chomsky normal form\n");
    int result = algorithm_chomsky_normal_form(gr, target_file);
    fclose(target_file);
    return result;
}
// 10 ���������� ������������ ��������� ��������
int action_fa_remove_unreachable(NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-faus")) return 0;
    printf("-- fa remove unreachable\n");
    int result = algorithm_fa_remove_unreachable(fa, target_file);
    fclose(target_file);
    return result;
}
// 11 �������������� �������� � ����������
int action_fa_to_grau(NFA & fa, grammar & gr) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-faau")) return 0;
    printf("-- fa to grammar\n");
    int result = algorithm_fa_to_grau(fa, gr, target_file);
    fclose(target_file);
    return result;
}
// 12 �������������� ���������� � �������
int action_grau_to_fa(grammar & gr, NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-aufa")) return 0;
    printf("-- grammar to fa\n");
    int result = algorithm_grau_to_fa(gr, fa, target_file);
    fclose(target_file);
    return result;
}
// 13 �������������� ��� � ���
int action_dfa(NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-dfa")) return 0;
    printf("-- nfa to dfa\n");
    int result = algorithm_dfa(fa, target_file);
    fclose(target_file);
    return result;
}
// 14 �������������� ��������
int action_fa_invert(NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-fainv")) return 0;
    printf("-- fa invert\n");
    int result = algorithm_fa_invert(fa, target_file);
    fclose(target_file);
    return result;
}

// 15 ����������� ���
int action_min_dfa(NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-minfa")) return 0;
    printf("-- min DFA\n");
    int result = algorithm_min_dfa(fa, target_file);
    fclose(target_file);
    return result;
}
// 16 �������������� ��������� � �������
int action_rex_to_fa(char * rex, NFA & fa) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-rexfa")) return 0;
    printf("-- regex\n%s\n\n", rex);
    printf("-- regex to fa\n");
    int result = algorithm_rex_to_fa(rex, fa, target_file);
    fclose(target_file);
    return result;
}
// 17 �������������� �������� � ���������
int action_fa_to_rex(NFA & fa, char * rex) {
    FILE * target_file = 0;
    if (!target_open(&target_file, "-farex")) return 0;
    printf("-- fa to regex\n");
    int result = algorithm_fa_to_rex(fa, rex, target_file);
    fclose(target_file);
    return result;
}
// ����������
void except(const char * err) {
    fprintf(stdout, "\n\n-- Exception encountered");
    fprintf(stdout, "\n-- %s\n\n", err);
}
// �������
void help() {
    printf("\nUsage:\n");
    printf("grom path -key1 -key2 . . .\n");
    printf("Keys:\n");
    printf("-gr    - group rules\n");
    printf("-us    - eliminate useless symbols\n");
    printf("-ur    - eliminate unreachable symbols\n");
    printf("-re    - eliminate empty rules\n");
    printf("-rc    - eliminate unit rules\n");
    printf("-lr    - eliminate left recursion\n");
    printf("-lf    - left factoring\n");
    printf("-cnf   - Chomsky normal form\n");
    printf("-faus  - eliminate unreachable states\n");
    printf("-faau  - automation to grammar\n");
    printf("-aufa  - grammar to automation\n");
    printf("-dfa   - NFA to DFA\n");
    printf("-fainv - NFA inverse\n");
    printf("-minfa - minimal DFA\n");
    printf("-rexfa - regex to e-NFA\n");
    printf("-farex - automation to regex\n");
    printf("\n");
}
