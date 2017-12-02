/**************************************************************************//**
 * @file     system_MK20D7.h
 * @brief    CMSIS Cortex-M# MK20D7 Peripheral Access Layer Header File for
 *           Device <MK20D7>
 * @version  V3.10
 * @date     11. January 2017
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef SYSTEM_<MK20D7>_H 
#define SYSTEM_<MK20D7>_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_<MK20D7>_H */


// NONE OF THE STUFF BELOW IS SUPPOSED TO BE IN THIS FILE. THE ABOVE IS IT.
// TODO: Figure out where it all goes.





//TODO: Added common.h contents.
/*
 * File:        common.h
 * Purpose:     File to be included by all project files
 *
 * Notes:
 *  This is a common header file for Teensy 3.1 projects.  It should
 *  be included in all Teensy 3.1 projects.
 *
 *  If you choose, you can move the PRDIV_VAL and VDIV_VAL settings
 *  to a project-specific file.  This would let you build projects
 *  with different system clock frequencies.
 *
 *  This file is derived from the original found in the Freescale
 *  CodeWarrior source files.  There have been several variations
 *  of these on the Internet; one such is kinetis_50MHz_sc, though
 *  I can't swear that is where this file came from originally.
 *
 *  12 Apr 14  KEL
 */

#ifndef _COMMON_H_
#define _COMMON_H_


#include  <stdint.h>
#include  "mk20d7.h"

/*
 *  Define characteristics of the target platform.
 *
 *  Choose PRDIV_VAL and VDIV_VAL based on your project hardware and system
 *  needs.
 *
 *  Note that PRDIV_VAL is *not* the value written to MCG_C5!  PRDIV_VAL is
 *  an integer divisor for prescaling the external clock for use by the PLL.
 *  PRDIV_VAL must be selected so that:
 *    XTAL_FREQ_HZ / PRDIV_VAL is between 2 MHz and 4 Mhz.
 *
 *  Note that VDIV_VAL is *not* the value written to MCG_C6!  VDIV_VAL is
 *  an integer multiplier for creating the final PLL frequency.
 *  VDIV_VAL must be selected so that:
 *    (XTAL_FREQ_HZ / PRDIV_VAL) * VDIV_VAL is between 48 MHz and 100 MHz.
 *
 * The final clock frequency is determined by PRDIV_VAL and VDIV_VAL.  Here are
 * some sample values for a Teensy 3.1:
 *    For system clock of	PRDIV_VAL	VDIV_VAL
 *    -------------------	---------	--------
 *         48 MHz			    8		   24
 *		   64 MHz				8		   32
 *		   72 MHz			    8		   36
 *
 */
#define PRDIV_VAL			8				/* PLL prescaler */
#define VDIV_VAL			32				/* PLL multiplier */

/*
 *  Optionally define the system console (one of the UARTs) for serial I/O.
 *  The value for TERM_PORT must be a UART base pointer, such as
 *  UART0_BASE_PTR.
 *  The value for TERMINAL_BAUD must be the baud rate, such as
 *  115200.
 *
 *  If your project does not include any of the UART drivers, these
 *  defines are meaningless and can be set to anything.
 */
#define TERM_PORT           UART0_BASE_PTR
#define TERMINAL_BAUD       115200


extern  int32_t				mcg_clk_hz;		// following PLL init, holds actual MCG clock in Hz
extern  int32_t				mcg_clk_khz;	// following PLL init, holds actual MCG clock in kHz
extern  int32_t				core_clk_khz;	// following PLL init, holds actual core clock in kHz
extern  int32_t				periph_clk_khz;	// following PLL init, holds actual peripheral clock in kHz

/********************************************************************/

#endif /* _COMMON_H_ */







//TODO: Added sysinit.h contents.
/*
 * File:        sysinit.h
 * Purpose:     Kinetis Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 */

/********************************************************************/

// function prototypes
void			sysinit(void);
void			trace_clk_init(void);
void			fb_clk_init(void);
int32_t			pll_init(int8_t  prdiv_val, int8_t  vdiv_val);
void			wdog_disable(void);

/********************************************************************/









//TODO: Added uart.h. Is this needed as generic system initialization? Perhaps it does if Teensy uart will always be used. Still, it seems like something that should be added when needed.
/*
 * File:		uart.h
 * Purpose:     Provide common ColdFire UART routines for polled serial IO
 *
 * Notes:
 * Modified to hide getchar, putchar, and char_avail routines; those now exist
 * as statics inside the uart.c code.  Modified uart_init() to take a UART
 * number (0-2), rather than a UART base pointer, and to remove the clock
 * argument; baud calcs are now based on the selected UART.
 */

#ifndef __UART_H__
#define __UART_H__


/*
 *  These routines support access to all UARTs on the Teensy 3.x (K20).
 *  To use a UART, first call UARTInit() with the UART number (0-2) and
 *  a desired baud rate; this call marks the selected UART as active.
 *  You can then call UARTWrite() to send chars to the active UART.  Use
 *  UARTAvail() to check for received chars.  Use UARTRead() to read
 *  chars (with blocking) from the active UART.
 *
 *  To use a different UART as the active UART, call UARTAssignActiveUART().
 */
void			UARTInit(uint32_t  uartnum, int32_t  baudrate);
uint32_t		UARTAssignActiveUART(uint32_t  uartnum);
int32_t			UARTWrite(const char *ptr, int32_t len);
int32_t			UARTAvail(void);
int32_t			UARTRead(char *ptr, int32_t len);


#
