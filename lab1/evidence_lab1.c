#include <stdlib.h>
#include <stdio.h>
#include "lab1.h"

/* evidence_expt: test expt */
void evidence_expt()
{
    printf("*** testing expt\n");
    printf("- expecting 1: %lld\n", expt(2,0));
    printf("- expecting 8: %lld\n", expt(2,3));
    printf("- expecting 125: %lld\n", expt(5,3));
    printf("- expecting 28561: %lld\n", expt(13,4));
}

/* evidence_ss: test ss */
void evidence_ss()
{
    printf("*** testing ss\n");
    printf("- expecting 1: %lld\n", ss(2, 0));
    printf("- expecting 2: %lld\n", ss(2, 1));
    printf("- expecting 4: %lld\n", ss(2, 2));
    printf("- expecting 8: %lld\n", ss(2, 3));
    printf("- expecting 16: %lld\n", ss(2, 4));
}

void evidence_ssm()
{
    printf("*** testing ssm\n");
    printf("- expecting 4: %d\n", ssm(2, 50, 13));
    printf("- expecting 3: %d\n", ssm(2, 40, 13));
    printf("- expecting 12: %d\n", ssm(2, 90, 13));
    printf("- expecting 9: %d\n", ssm(7, 4, 13));
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_expt();
    evidence_ss();
    evidence_ssm();
    return 0;
}