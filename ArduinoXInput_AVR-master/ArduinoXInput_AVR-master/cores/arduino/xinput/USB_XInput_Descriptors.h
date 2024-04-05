/*
 *  Project     Arduino XInput - AVR Core
 *  @author     David Madison
 *  @link       github.com/dmadison/ArduinoXInput_AVR
 *  @license    MIT - Copyright (c) 2019 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "USBAPI.h"

#ifndef USB_XINPUT_DESCRIPTORS_H
#define USB_XINPUT_DESCRIPTORS_H

#if defined(USBCON)

// Device Descriptor
extern const DeviceDescriptor USB_DeviceDescriptor PROGMEM;

// Config Descriptor
extern const u8  USB_ConfigDescriptor[] PROGMEM;
extern const u16 USB_ConfigDescriptorSize PROGMEM;

// String Descriptors
extern const u8 STRING_SERIAL[] PROGMEM;
extern const u8 STRING_SECURITY[] PROGMEM;

#define ISECURITY 4

// Endpoint Numbers
#define XINPUT_TX_ENDPOINT	1
#define XINPUT_RX_ENDPOINT	2

#endif /* if defined(USBCON) */

#endif /* ifndef USB_XINPUT_DESCRIPTORS_H */
