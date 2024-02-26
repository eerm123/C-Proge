#ifndef KODU3_KODU3_FUN_DEKL_H
#define KODU3_KODU3_FUN_DEKL_H

#include <string>
using string = std::string;

int fun(int, int);
int fun(double);
string fun(unsigned int, string);
double kehamassiindeks(double, double);
string hinnang(double);
unsigned long int faktoriaal_li(int n);
string otsi_mustrit(int& argc, char* argv[]);
void andmed_failist(const string&);

#endif