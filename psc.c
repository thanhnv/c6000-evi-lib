/*
 * psc.c
 *
 *  Created on: May 18, 2013
 *      Author: NGUYEN
 */





#include "include/psc.h"

Int32 PSC0_lPSC_enable(Uint32 PD, Uint32 LPSC_num) {
  *(unsigned int*) (PSC0_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
  PSC0_PTCMD = 0x1<<PD;
  while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3);
  return 1;
}

Int32 PSC0_lPSC_disable(Uint32 PD, Uint32 LPSC_num) {
  *(unsigned int*) (PSC0_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0002;
  PSC0_PTCMD = 0x1<<PD;
  while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(unsigned int*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) !=0x2);
  return 1;
}

Int32 PSC1_lPSC_enable(Uint32 PD, Uint32 LPSC_num) {
  *(unsigned int*) (PSC1_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC1_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
  PSC1_PTCMD = 0x1<<PD;
  while( (PSC1_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3);
  return 1;
}

Int32 PSC1_lPSC_disable(Uint32 PD, Uint32 LPSC_num) {
  *(unsigned int*) (PSC1_MDCTL+4*LPSC_num) = (*(unsigned int*) (PSC1_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0002;
  PSC1_PTCMD = 0x1<<PD;
  while( (PSC1_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(unsigned int*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) !=0x2);
  return 1;
}
