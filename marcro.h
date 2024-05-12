#ifndef MARCRO_H
#define MARCRO_

// ================
// STANDARD DEFINES
// ================
#define TRUE 1
#define FALSE 0

#define ARRAYSIZE(array) ((int)(sizeof(array) / sizeof(array[0])))
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
#define _UNUSED_ __attribute__((unused))

// defines for functions
#define DPFREE(pointer) pfree((void**)&(pointer));
#define ZERO(pointer) memset(pointer, 0, sizeof(pointer));

// =======================================
// =======================================
// =======================================

// ============
// == Copied ==
// ============
#define MIN(x, y)           (((x) < (y)) ?  (x) : (y))
#define MAX(x, y)           (((x) > (y)) ?  (x) : (y))
#define IS_ODD( num )       ((num) & 1)
#define IS_EVEN( num )      (!IS_ODD( (num) ))
#define IS_BETWEEN(n,L,H)   ((unsigned char)((n) >= (L) && (n) <= (H)))
#define ABS(x)              (((x) <  0) ? -(x) : (x))
#define DIFF(a,b)           ABS((a)-(b))

// BITS
#define BIT(x)          (1<<(x))
#define SETBIT(x,p)     ((x)|(1<<(p)))
#define CLEARBIT(x,p)   ((x)&(~(1<<(p))))
#define GETBIT(x,p)     (((x)>>(p))&1)
#define TOGGLEBIT(x,p)  ((x)^(1<<(p)))

/*
#define AND       &&
#define OR        ||
#define NOT       !
#define NOTEQUALS !=
#define EQUALS    ==
#define IS        =
*/

#endif
