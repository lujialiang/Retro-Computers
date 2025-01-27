/* ========================================
 *
 * Copyright LAND BOARDS, LLC, 2019
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards, LLC.
 *
 * ========================================
*/

#if !defined(Z80PIOEMU_H)
#define Z80PIOEMU_H
    
#include <project.h>
    
#define MCP23017_PIO_ADDR   0x20 // I2C Address of the MCP23017

#define PIO_OP_MODE_MASK    0xC0 // The Mode bits
#define PIO_OP_MODE_0       0x00 // Output
#define PIO_OP_MODE_1       0x40 // Input
#define PIO_OP_MODE_2       0x80 // Bidirectional
#define PIO_OP_MODE_3       0xC0 // Control which bits are ins/outs
#define PIO_OP_DIR          0x01 // 1=input, 0-output
#define PIO_MODE_WORD_BITS  0x0F // Mode word bits
#define PIO_MODE_WORD_VAL   0x0F // Mode word value

#define PIO_INT_EN_BIT      0x80 // 1=enable interrupts, 0-disable interrupts
#define PIO_AND_OR_BIT      0x40 // 1=AND, 0=OR
#define PIO_HIGH_LOW        0x20 // 1=monitor for high, 0=monitor for low
#define PIO_MASK_FOLLOWS    0x10 // Define mask bits follow
#define PIO_INT_CTL_WORD    0x07 // Signifies Interrupt Control Word
#define PIO_MASK_BITS       0xFF // Bit mask values

enum PIO_State
    {
        PIO_UNINIT, 
        PIO_INIT,
        PIO_INTR,
        PIO_MODE_3A,
        PIO_INTR_MASK
    };

enum PIO_OpMode
    {
        PIO_MODE_0,
        PIO_MODE_1,
        PIO_MODE_2,
        PIO_MODE_3
    };
    
extern volatile uint8 PIO_Input_Register_Port_A;
extern volatile uint8 PIO_Input_Register_Port_B;

void init_PIO(void);
void PioReadDataA(void);
void PioWriteDataA(void);
void PioWriteCtrlA(void);
void PioReadDataB(void);
void PioWriteDataB(void);
void PioWriteCtrlB(void);

/* [] END OF FILE */
#endif
