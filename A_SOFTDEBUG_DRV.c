#include "A_SOFTDEBUG_DRV.h"



#if _SOFTDEBUG
//===========================================================
//*@brief		: S_SFUART_Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SFUART_Init(void)
{
    // Set TX pin (PA4) as output and initialize it to low (0)
    PC_SFUART_TX = 0;
    P_SFUART_TX = 1;

    // Set RX pin (PA1) as input and enable internal pull-up
    P_SFUART_RX = 1;
    PC_SFUART_RX = 1;
    PU_SFUART_RX = 1;
    _pac5 = 1; // PA1 (RX) direction control (set as input)
    _papu5 = 0; // Disable PA1 (RX) pull-up

    // Configure PA1 as an external interrupt (INT1) input
    _pas02 = 0; // Clear INT1 interrupt flag (in case it was set before)
    _pas03 = 0; // Clear INT1 polarity flag (in case it was set before)

    // Set INT1 to trigger on falling edge
    _int1s1 = 1;
    _int1s0 = 0;

    // Enable the ISR (Interrupt Service Routine) for INT1
    _int1e = 1;
}


//===========================================================
//*@brief		: S_SFUART_SEND(9600BPS)
//*@param[in]	: R_SFUART_DATA
//*@retval		: None
//===========================================================
void S_SFUART_SEND(unsigned char R_SFUART_DATA)
{
	

    // Include the appropriate header file (BA45F5240.inc) for the target platform.
    asm("include BA45F5240.inc");

    // Local variables used in assembly code
    asm("LOCAL R_SFUART_TCNT DB ?");
    asm("LOCAL R_SFUART_TDAT DB ?");

    // Copy the data to be transmitted (R_SFUART_DATA) to the transmission data register.
    asm("MOV R_SFUART_TDAT, A");

    // Update the checksum by adding the data byte to it.
    asm("ADDM A, _R_SFCHECK_SUM");

    // Clear the EMI (External Memory Interface) to prevent any potential interference.
    asm("CLR EMI");

    // Set the transmission count (number of bits to transmit) to 8.
    asm("MOV A, 8");
    asm("MOV R_SFUART_TCNT, A");

    // Set the TX pin (transmission pin) to logic low (0) to start the transmission.

    // Calculate the appropriate delay based on the configured HIRCC (High-Frequency Internal RC Clock) value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.

    // Loop to transmit each bit in the data byte.
    asm("L_SFUART_SEND_LOOP:");
    asm("SNZ R_SFUART_TDAT.0"); // Check the least significant bit (LSB) of the data byte.
    asm("JMP L_SFUART_SEND_D0"); // If it is 0, jump to L_SFUART_SEND_D0.
    asm("JMP L_SFUART_SEND_D1"); // If it is 1, jump to L_SFUART_SEND_D1.

    asm("L_SFUART_SEND_D0:");
    // Perform a delay (NOP) before setting the TX pin to logic low (0) for 0-bit transmission.
    asm("NOP");
    // Set the TX pin to logic low (0).
    P_SFUART_TX = 0;
    // Jump to the next bit transmission.
    asm("JMP L_SFUART_SEND_NEXT");

    asm("L_SFUART_SEND_D1:");
    // Set the TX pin to logic high (1) for 1-bit transmission.
    P_SFUART_TX = 1;
    // Jump to the next bit transmission.
    asm("JMP L_SFUART_SEND_NEXT");

    asm("L_SFUART_SEND_NEXT:");
    // Calculate the appropriate delay based on the configured HIRCC (High-Frequency Internal RC Clock) value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.

    // Right-rotate the data byte to get the next bit to be transmitted in the LSB position.
    asm("RRC R_SFUART_TDAT");

    // Decrement the transmission count (number of bits remaining to transmit).
    asm("SDZ R_SFUART_TCNT");

    // Jump back to the start of the loop if there are more bits to transmit.
    asm("JMP L_SFUART_SEND_LOOP");

    // The following lines of code seem to be unreachable (placed after an infinite loop).
    // They might have been included in error.
    asm("MOV A, 2");
    asm("SDZ ACC");
    asm("JMP $-1");

    // Set the TX pin to logic high (1) after the transmission is complete.

    // Calculate the appropriate delay based on the configured HIRCC (High-Frequency Internal RC Clock) value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.

    // The following lines of code also seem to be unreachable.
    // They might have been included in error.

    // Set the EMI (External Memory Interface) after the transmission is complete.
    asm("SET EMI");
}

//===========================================================
//*@brief       : Software UART Receive Interrupt Handler (9600 BPS)
//*@param[in]   : None
//*@retval      : None
//===========================================================
void S_SFUART_RXINT(void)
{
    unsigned char R_SFUART_RDAT;
    asm("LOCAL R_SFUART_RCNT DB ?");
    asm("P_SFUART_RX EQU PA1");

    // Set the count of received bits to 8.
    asm("MOV A, 8");
    asm("MOV R_SFUART_RCNT, A");

    // Calculate the appropriate delay based on the configured HIRCC (High-Frequency Internal RC Clock) value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.
    #if _HIRCC_8M
        asm("MOV A, 27");
    #elif _HIRCC_4M
        asm("JMP $+1");
        asm("MOV A, 9");
    #else
        asm("MOV A, 1");
    #endif
    asm("SDZ ACC");
    asm("JMP $-1");

    // Clear the received data variable.
    asm volatile ("CLR %0" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));

    // Loop to receive the 8 data bits.
    asm("L_SFUART_RXINT_BLOOP:");

    // Calculate the appropriate delay based on the configured HIRCC (High-Frequency Internal RC Clock) value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.
    #if _HIRCC_8M
        asm("NOP");
        asm("MOV A, 65");
    #elif _HIRCC_4M
        asm("JMP $+1");
        asm("MOV A, 30");
    #else
        asm("NOP");
        asm("MOV A, 13");
    #endif
    asm("SDZ ACC");
    asm("JMP $-1");

    // Check the RX pin (PA1) for the received bit.
    asm("CLR C");
    asm volatile ("RRC %0" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
    asm("SZ P_SFUART_RX"); // Check if the RX pin is high (1).
    asm("JMP L_SFUART_RXINT_D1"); // If it is high, jump to L_SFUART_RXINT_D1 (received 1-bit).
    asm("JMP L_SFUART_RXINT_D0"); // If it is low, jump to L_SFUART_RXINT_D0 (received 0-bit).

    // Handle received 1-bit.
    asm("L_SFUART_RXINT_D1:");
    asm("NOP");
    asm volatile ("SET %0.7" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
    asm("JMP L_SFUART_RXINT_N0");

    // Handle received 0-bit.
    asm("L_SFUART_RXINT_D0:");
    asm volatile ("CLR %0.7" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
    asm("JMP L_SFUART_RXINT_N0");

    // Decrement the received bit count (number of bits remaining to receive).
    asm("L_SFUART_RXINT_N0:");
    asm("SDZ R_SFUART_RCNT");

    // Jump back to the start of the loop if there are more bits to receive.
    asm("JMP L_SFUART_RXINT_BLOOP");

    // Store the received data in the R_SFUART_RXDAT array and increment the receive count.
    R_SFUART_RXDAT[R_SFUART_RXCNT] = R_SFUART_RDAT;
    R_SFUART_RXCNT++;

    // Calculate the appropriate delay after receiving each byte based on the configured HIRCC value.
    // The actual values used for the delay depend on the specific platform and the chosen HIRCC setting.
    #if _HIRCC_8M
        GCC_DELAY(104);
    #elif _HIRCC_4M
        GCC_DELAY(52);
    #else
        GCC_DELAY(26);
    #endif
}

//===========================================================
//*@brief       : Software data processing for received UART data
//*@param[in]   : p - Pointer to the received UART data array
//*@retval      : None
//===========================================================
void S_SFUART_DEAL(unsigned char *p)
{
    unsigned char i;
    unsigned char R_CHECK_DATA;
    R_CHECK_DATA = 0;

    // Check if the received UART data starts with the marker (0xAA).
    if (p[0] != 0xAA)
    {
        // If the marker is not found, reset the receive count and return.
        R_SFUART_RXCNT = 0;
        return;
    }

    // Check if the received UART data has reached the expected size (sizeof(R_SFUART_RXDAT)).
    // If not, return without further processing.
    if (R_SFUART_RXCNT < sizeof(R_SFUART_RXDAT))
    {
        return;
    }

    // Calculate the checksum (R_CHECK_DATA) by adding the first 11 bytes of the received data.
    for (i = 0; i < 11; i++)
    {
        R_CHECK_DATA += p[i];
    }

    // Check if the received checksum (p[11]) matches the calculated checksum (R_CHECK_DATA).
    // If not, reset the receive count and return.
    if (p[11] != R_CHECK_DATA)
    {
        R_SFUART_RXCNT = 0;
        return;
    }

    // If the received data is valid (contains the marker and the correct checksum):

    _sdpgac0 = p[2];                 // Assign the received value to _sdpgac0.
    _sdpgac1 = p[3] + (p[4] << 6);   // Assign the received values to _sdpgac1 (combine p[3] and p[4]).
    R_ISINK0_VALUE = p[5];           // Assign the received value to R_ISINK0_VALUE.
    R_ISINK1_VALUE = p[6];           // Assign the received value to R_ISINK1_VALUE.
    R_OPA_DELAY = p[7];              // Assign the received value to R_OPA_DELAY.
    R_ISINK0_DELAY = p[8];           // Assign the received value to R_ISINK0_DELAY.
    R_ISINK1_DELAY = p[9];           // Assign the received value to R_ISINK1_DELAY.
    R_SM_BD_KQ_SET = p[10];          // Assign the received value to R_SM_BD_KQ_SET.

    S_CLR_OUTPUT();                 // Clear the output (perform a specific operation).

    F_SM_ALARM = 0;                 // Clear the F_SM_ALARM flag.

    F_BD_DATA_DONT_SAVE = 1;        // Set the flag F_BD_DATA_DONT_SAVE to 1.

    S_SM_BD_AIR();                  // Call the S_SM_BD_AIR function (perform a specific operation).

    // Reset the received UART data array by setting its elements to 0.
    for (i = 0; i < 12; i++)
    {
        p[i] = 0;
    }

    R_SFUART_RXCNT = 0;             // Reset the receive count for the next reception.
}


//===========================================================
//*@brief		: Software debug data output
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SOFTDEBUG_Output(void)
{
    R_SFCHECK_SUM = 0; // Initialize the checksum variable to zero.

    // Check if the UART running count (R_UART_RUNCNT) is zero.
    if (R_UART_RUNCNT == 0)
    {
        // Send debug information over the UART using the S_SFUART_SEND function.

        // S_SFUART_SEND(0XAA); // Send a specific marker (0xAA) to indicate the start of debug data.

        // Send various debug information one by one using the S_SFUART_SEND function.

        S_SFUART_SEND(0XAA);               // 0: Marker (Start of debug data)
        S_SFUART_SEND(17);                 // 1: Value (Debug info 1)
        S_SFUART_SEND(_sdpgac0);           // 2: Value (Debug info 2)
        S_SFUART_SEND(_sdpgac1 & (0X3F));  // 3: Bits 0-5 of _sdpgac1
        S_SFUART_SEND(_sdpgac1 >> 6);      // 4: Bits 6-7 of _sdpgac1
        S_SFUART_SEND(_isgdata0);          // 5: Value (Debug info 3)
        S_SFUART_SEND(_isgdata1);          // 6: Value (Debug info 4)
        S_SFUART_SEND(R_OPA_DELAY);        // 7: Value (Debug info 5)
        S_SFUART_SEND(R_ISINK0_DELAY);     // 8: Value (Debug info 6)
        S_SFUART_SEND(R_ISINK1_DELAY);     // 9: Value (Debug info 7)
        S_SFUART_SEND(R_SM_BD_ALARM);      // 10: Value (Debug info 8)
        S_SFUART_SEND(R_SYS_FG.byte);      // 11: Value (Debug info 9)
        S_SFUART_SEND(R_SM_FG.byte);       // 12: Value (Debug info 10)
        S_SFUART_SEND(R_BAT_ADC);          // 13: Value (Debug info 11)
        S_SFUART_SEND(R_T_ADC);            // 14: Value (Debug info 12)
        S_SFUART_SEND(R_SM_BD_ZERO);       // 15: Value (Debug info 13)
        S_SFUART_SEND(R_SM_ZERO_DATA);     // 16: Value (Debug info 14)
        S_SFUART_SEND(R_SM_IR_DATA);       // 17: Value (Debug info 15)
        S_SFUART_SEND(R_SM_DATA);          // 18: Value (Debug info 16)
        S_SFUART_SEND(R_SFCHECK_SUM);      // 19: Checksum (End of debug data)

        // The debug data is sent over the UART for debugging purposes.
        // The values sent depend on the specific system and its current state.
        // The function can be used to monitor and debug various variables and states.
    }
}
#endif


