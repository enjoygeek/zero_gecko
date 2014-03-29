/***************************************************************************//**
 * @file displayconfigapp.h
 * @brief Display application specific configuration file.
 * @author Energy Micro AS
 * @version 3.20.3
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2013 Energy Micro AS, http://www.energymicro.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 * 4. The source and compiled code may only be used on Energy Micro "EFM32"
 *    microcontrollers and "EFR4" radios.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Energy Micro AS has no
 * obligation to support this Software. Energy Micro AS is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Energy Micro AS will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 *****************************************************************************/
#ifndef _DISPLAY_CONFIG_APP_H_
#define _DISPLAY_CONFIG_APP_H_

/* Include TEXTDISPLAY support because this example prints text to the
   display. */
#define INCLUDE_TEXTDISPLAY_SUPPORT

/* Enable/disable video terminal escape sequences. */
#define INCLUDE_VIDEO_TERMINAL_ESCAPE_SEQUENCE_SUPPORT

/* Select one of the fonts listed below:
   TEXTDISPLAY_FONT_6x8
   TEXTDISPLAY_FONT_8x8
*/
#define TEXTDISPLAY_FONT_8x8

/* Enable or disable scroll mode on the text display. */
#define RETARGETTEXTDISPLAY_SCROLL_MODE  (false)

/* Enable or disable adding Carriage Return (CR) to Line Feed (LF) characters
   on the text display. */
#define RETARGETTEXTDISPLAY_LINE_FEED_MODE  (true)

/* On EFM32ZG_STK3200, the DISPLAY driver Platform Abstraction Layer (PAL)
   uses the RTC to time and toggle the EXTCOMIN pin of the Sharp memory
   LCD per default. However, this example wants to use the RTC for other
   purposes too. Therefore it implements a function (RtcIntCallbackRegister)
   that enables the PAL to register the callback function that needs to be 
   called in order to toggle the EXTCOMIN pin.
   I.e we need to undefine the INCLUDE_PAL_GPIO_PIN_AUTO_TOGGLE (which
   is defined by default and uses the RTC) and we need to define the
   PAL_TIMER_REPEAT_FUNCTION. */
#undef INCLUDE_PAL_GPIO_PIN_AUTO_TOGGLE
#define PAL_TIMER_REPEAT_FUNCTION  (RtcIntCallbackRegister)
extern int RtcIntCallbackRegister (void(*pFunction)(void*),
                                   void* argument,
                                   unsigned int frequency);

#endif /* _DISPLAY_CONFIG_APP_H_ */
