/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/local/PODS/jschwel1/EECE387/Lab1/Q1/Design_Lab_1.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0494197484_3212880686_p_0(char *t0)
{
    char t3[16];
    char *t1;
    unsigned char t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2984);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(53, ng0);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t4 = (t0 + 4872U);
    t6 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t3, t5, t4, 2);
    t7 = (t0 + 3064);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t6, 4U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1352U);
    t4 = *((char **)t1);
    t1 = (t0 + 3128);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t4, 4U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(57, ng0);
    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t1 = (t0 + 3192);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t4, 4U);
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

}


extern void work_a_0494197484_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0494197484_3212880686_p_0};
	xsi_register_didat("work_a_0494197484_3212880686", "isim/Test_bench_isim_beh.exe.sim/work/a_0494197484_3212880686.didat");
	xsi_register_executes(pe);
}
