/* Header file generated by fdesign on Thu Sep 22 21:17:19 2016 */

#ifndef FD_calculator_h_
#define FD_calculator_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

void proc_num( FL_OBJECT *, long );
void operator( FL_OBJECT *, long );
void grouping( FL_OBJECT *, long );
void erase( FL_OBJECT *, long );
void unitangle( FL_OBJECT *, long );
void memory( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * calculator;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * dit;
    FL_OBJECT * neg;
    FL_OBJECT * nine;
    FL_OBJECT * ten;
    FL_OBJECT * six;
    FL_OBJECT * seven;
    FL_OBJECT * three;
    FL_OBJECT * four;
    FL_OBJECT * zero;
    FL_OBJECT * one;
    FL_OBJECT * two;
    FL_OBJECT * five;
    FL_OBJECT * eight;
    FL_OBJECT * elv;
    FL_OBJECT * exp;
    FL_OBJECT * div;
    FL_OBJECT * times;
    FL_OBJECT * minus;
    FL_OBJECT * plus;
    FL_OBJECT * equals;
    FL_OBJECT * sqrt;
    FL_OBJECT * expon;
    FL_OBJECT * closeparen;
    FL_OBJECT * openparen;
    FL_OBJECT * mod;
    FL_OBJECT * sin;
    FL_OBJECT * cosine;
    FL_OBJECT * tangent;
    FL_OBJECT * dozlog;
    FL_OBJECT * declog;
    FL_OBJECT * natlog;
    FL_OBJECT * baselog;
    FL_OBJECT * atan;
    FL_OBJECT * acos;
    FL_OBJECT * asin;
    FL_OBJECT * recip;
    FL_OBJECT * dublog;
    FL_OBJECT * hytan;
    FL_OBJECT * hycos;
    FL_OBJECT * hysin;
    FL_OBJECT * clear;
    FL_OBJECT * backspace;
    FL_OBJECT * factorial;
    FL_OBJECT * pi;
    FL_OBJECT * euler;
    FL_OBJECT * angleunit;
    FL_OBJECT * memappend;
    FL_OBJECT * memadd;
    FL_OBJECT * ansfield;
    FL_OBJECT * angletype;
    FL_OBJECT * greatcommfact;
    FL_OBJECT * leastcommult;
    FL_OBJECT * memrep;
    FL_OBJECT * clearmem;
} FD_calculator;

FD_calculator * create_form_calculator( void );

#endif /* FD_calculator_h_ */
