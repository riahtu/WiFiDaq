/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : UART_ESP8266.c
**     Project     : daq
**     Processor   : MK64FN1M0VLL12
**     Component   : Serial_LDD
**     Version     : Component 01.188, Driver 01.12, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-31, 13:42, # CodeGen: 1
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : UART_ESP8266
**          Device                                         : UART3
**          Interrupt service/event                        : Enabled
**            Interrupt RxD                                : INT_UART3_RX_TX
**            Interrupt RxD priority                       : medium priority
**            Interrupt TxD                                : INT_UART3_RX_TX
**            Interrupt TxD priority                       : medium priority
**            Interrupt Error                              : INT_UART3_ERR
**            Interrupt Error priority                     : medium priority
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : None
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 115200 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : J1_2
**            Transmitter                                  : Enabled
**              TxD                                        : J1_4
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnTxComplete                               : Disabled
**              OnError                                    : Disabled
**              OnBreak                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                 - LDD_TDeviceData* UART_ESP8266_Init(LDD_TUserData *UserDataPtr);
**         SendBlock            - LDD_TError UART_ESP8266_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock         - LDD_TError UART_ESP8266_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr,...
**         CancelBlockReception - LDD_TError UART_ESP8266_CancelBlockReception(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum   - uint16_t UART_ESP8266_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask         - LDD_TError UART_ESP8266_SetEventMask(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file UART_ESP8266.c
** @version 01.12
** @brief
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
*/         
/*!
**  @addtogroup UART_ESP8266_module UART_ESP8266 module documentation
**  @{
*/         

/* MODULE UART_ESP8266. */
/*lint -save  -e926 -e927 -e928 -e929 -e572 Disable MISRA rule (11.4,12.8) checking. */

/* {Default RTOS Adapter} No RTOS includes */
#include "UART_ESP8266.h"
#include "Events.h"
#include "UART_PDD.h"
#include "SIM_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! The mask of available events used to enable/disable events during runtime. */
#define AVAILABLE_EVENTS_MASK (LDD_SERIAL_ON_BLOCK_RECEIVED | LDD_SERIAL_ON_BLOCK_SENT)

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static UART_ESP8266_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static UART_ESP8266_TDeviceDataPtr INT_UART3_RX_TX__DEFAULT_RTOS_ISRPARAM;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static UART_ESP8266_TDeviceDataPtr INT_UART3_ERR__DEFAULT_RTOS_ISRPARAM;
/* Internal method prototypes */
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART_ESP8266_Init (component Serial_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* UART_ESP8266_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  /* Clear the receive counters and pointer */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Clear the counter of received characters */
  DeviceDataPrv->InpDataNumReq = 0x00U; /* Clear the counter of characters to receive by ReceiveBlock() */
  DeviceDataPrv->InpDataPtr = NULL;    /* Clear the buffer pointer for received characters */
  /* Clear the transmit counters and pointer */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters */
  DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
  DeviceDataPrv->OutDataPtr = NULL;    /* Clear the buffer pointer for data to be transmitted */
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Allocate interrupt vectors */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_UART3_RX_TX__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_UART3_ERR__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC4: UART3=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;
  /* SIM_SCGC5: PORTC=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
  /* PORTC_PCR16: ISF=0,MUX=3 */
  PORTC_PCR16 = (uint32_t)((PORTC_PCR16 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));
  /* PORTC_PCR17: ISF=0,MUX=3 */
  PORTC_PCR17 = (uint32_t)((PORTC_PCR17 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));
  /* NVICIP37: PRI37=0x70 */
  NVICIP37 = NVIC_IP_PRI37(0x70);
  /* NVICISER1: SETENA|=0x20 */
  NVICISER1 |= NVIC_ISER_SETENA(0x20);
  /* NVICIP38: PRI38=0x70 */
  NVICIP38 = NVIC_IP_PRI38(0x70);
  /* NVICISER1: SETENA|=0x40 */
  NVICISER1 |= NVIC_ISER_SETENA(0x40);
  UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset flags */
  DeviceDataPrv->EventMask = 0x03u;    /* Initialization of the event mask variable */
  /* UART3_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART3_C1 = 0x00U;                    /*  Set the C1 register */
  /* UART3_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART3_C3 = 0x00U;                    /*  Set the C3 register */
  /* UART3_C4: MAEN1=0,MAEN2=0,M10=0,BRFA=0 */
  UART3_C4 = UART_C4_BRFA(0x00);       /*  Set the C4 register */
  /* UART3_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART3_S2 = 0x00U;                    /*  Set the S2 register */
  /* UART3_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART3_MODEM = 0x00U;                 /*  Set the MODEM register */
  UART_ESP8266_SetClockConfiguration(DeviceDataPrv, Cpu_GetClockConfiguration()); /* Initial speed CPU mode is high */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_UART_ESP8266_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_SetEventMask (component Serial_LDD)
*/
/*!
**     @brief
**         Enables/Disables events. This method is available if the
**         interrupt service/event property is enabled and at least one
**         event is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         EventMask       - Mask of events to enable.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_PARAM_MASK - Invalid event mask.
*/
/* ===================================================================*/
LDD_TError UART_ESP8266_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual speed CPU mode? */
    return ERR_SPEED;                  /* If yes then error */
  }
  if ((EventMask & (LDD_TEventMask)(~(LDD_TEventMask)AVAILABLE_EVENTS_MASK)) != 0x00U) { /* Is the parameter EventMask within an expected range? */
    return ERR_PARAM_MASK;             /* If no then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->EventMask = EventMask; /* Set the new event mask. */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_ReceiveBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method [CancelBlockReception] can be used to
**         cancel a running receive operation. If a receive operation
**         is not in progress (the method was not called or a previous
**         operation has already finished) all received characters will
**         be lost without any notification. To prevent the loss of
**         data call the method immediately after the last receive
**         operation has finished (e.g. from the [OnBlockReceived]
**         event). This method finishes immediately after calling it -
**         it doesn't wait the end of data reception. Use event
**         [OnBlockReceived] to check the end of data reception or
**         method GetReceivedDataNum to check the state of receiving.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored. In case
**                           of 8bit character width each character in
**                           buffer occupies 1 byte. In case of 9 and
**                           more bit long character width each
**                           character in buffer occupies 2 bytes.
**     @param
**         Size            - Number of characters to receive
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError UART_ESP8266_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual speed CPU mode? */
    return ERR_SPEED;                  /* If yes then error */
  }
  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the previous receive operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->InpDataPtr = (uint8_t*)BufferPtr; /* Store a pointer to the input data. */
  DeviceDataPrv->InpDataNumReq = Size; /* Store a number of characters to be received. */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Set number of received characters to zero. */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_SendBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method [CancelBlockTransmission] can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled. This method finishes
**         immediately after calling it - it doesn't wait the end of
**         data transmission. Use event [OnBlockSent] to check the end
**         of data transmission or method GetSentDataNum to check the
**         state of sending.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to a buffer from where
**                           data will be sent. In case of 8bit
**                           character width each character in buffer
**                           occupies 1 byte. In case of 9 and more bit
**                           long character width each character in
**                           buffer occupies 2 bytes.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError UART_ESP8266_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual speed CPU mode? */
    return ERR_SPEED;                  /* If yes then error */
  }
  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->OutDataNumReq != 0x00U) { /* Is the previous transmit operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->OutDataPtr = (uint8_t*)BufferPtr; /* Set a pointer to the output data. */
  DeviceDataPrv->OutDataNumReq = Size; /* Set the counter of characters to be sent. */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters. */
  DeviceDataPrv->SerFlag |= ENABLED_TX_INT; /* Set the flag ENABLED_TX_INT */
  UART_PDD_EnableInterrupt(UART3_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER); /* Enable TX interrupt */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_GetReceivedDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Number of received characters in the receive
**                           buffer.
*/
/* ===================================================================*/
uint16_t UART_ESP8266_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->InpRecvDataNum); /* Return the number of received characters. */
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_CancelBlockReception (component Serial_LDD)
*/
/*!
**     @brief
**         Immediately cancels the running receive process started by
**         method [ReceiveBlock]. Characters already stored in the HW
**         FIFO will be lost.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
*/
/* ===================================================================*/
LDD_TError UART_ESP8266_CancelBlockReception(LDD_TDeviceData *DeviceDataPtr)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual speed CPU mode? */
    return ERR_SPEED;                  /* If yes then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->InpDataNumReq = 0x00U; /* Clear the counter of requested incoming characters. */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Clear the counter of received characters. */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  HWEnDi (component Serial_LDD)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  if (DeviceDataPrv->EnMode) {         /* Enable device? */
    UART_PDD_EnableFifo(UART3_BASE_PTR, (UART_PDD_TX_FIFO_ENABLE | UART_PDD_RX_FIFO_ENABLE)); /* Enable RX and TX FIFO */
    UART_PDD_FlushFifo(UART3_BASE_PTR, (UART_PDD_TX_FIFO_FLUSH | UART_PDD_RX_FIFO_FLUSH)); /* Flush RX and TX FIFO */
    UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
    UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_ENABLE); /* Enable receiver */
    UART_PDD_EnableInterrupt(UART3_BASE_PTR, ( UART_PDD_INTERRUPT_RECEIVER )); /* Enable interrupts */
  } else {
    UART_PDD_DisableInterrupt(UART3_BASE_PTR, ( UART_PDD_INTERRUPT_RECEIVER | UART_PDD_INTERRUPT_TRANSMITTER )); /* Disable interrupts */
    UART_PDD_EnableTransmitter(UART3_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
    UART_PDD_EnableReceiver(UART3_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  }
}
/*
** ===================================================================
**     Method      :  InterruptRx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptRx(UART_ESP8266_TDeviceDataPtr DeviceDataPrv)
{
  register uint16_t Data;              /* Temporary variable for data */

  Data = (uint16_t)UART_PDD_GetChar8(UART3_BASE_PTR); /* Read an 8-bit character from the receiver */
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the receive block operation pending? */
    *(DeviceDataPrv->InpDataPtr++) = (uint8_t)Data; /* Put an 8-bit character to the receive buffer */
    DeviceDataPrv->InpRecvDataNum++;   /* Increment received char. counter */
    if (DeviceDataPrv->InpRecvDataNum == DeviceDataPrv->InpDataNumReq) { /* Is the requested number of characters received? */
      DeviceDataPrv->InpDataNumReq = 0x00U; /* If yes then clear number of requested characters to be received. */
      if (DeviceDataPrv->EventMask & LDD_SERIAL_ON_BLOCK_RECEIVED) {
        UART_ESP8266_OnBlockReceived(DeviceDataPrv->UserDataPtr);
      }
    }
  }
}

/*
** ===================================================================
**     Method      :  InterruptTx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptTx(UART_ESP8266_TDeviceDataPtr DeviceDataPrv)
{

  if (DeviceDataPrv->OutSentDataNum < DeviceDataPrv->OutDataNumReq) { /* Is number of sent characters less than the number of requested incoming characters? */
    UART_PDD_PutChar8(UART3_BASE_PTR, *(DeviceDataPrv->OutDataPtr++)); /* Put a 8-bit character to the transmit register */
    DeviceDataPrv->OutSentDataNum++;   /* Increment the counter of sent characters. */
    if (DeviceDataPrv->OutSentDataNum == DeviceDataPrv->OutDataNumReq) {
      DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
      if (DeviceDataPrv->EventMask & LDD_SERIAL_ON_BLOCK_SENT) {
        UART_ESP8266_OnBlockSent(DeviceDataPrv->UserDataPtr);
      }
    }
  } else {
    UART_PDD_DisableInterrupt(UART3_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER); /* Disable TX interrupt */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLED_TX_INT); /* Clear the flag ENABLED_TX_INT */
  }
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_Interrupt (component Serial_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt. Calls InterruptTX/InterruptRX methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(UART_ESP8266_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = INT_UART3_RX_TX__DEFAULT_RTOS_ISRPARAM;
  register uint32_t StatReg = UART_PDD_ReadInterruptStatusReg(UART3_BASE_PTR); /* Read status register */

  if (StatReg & (UART_S1_NF_MASK | UART_S1_OR_MASK | UART_S1_FE_MASK | UART_S1_PF_MASK)) { /* Is any error flag set? */
    (void)UART_PDD_GetChar8(UART3_BASE_PTR); /* Dummy read 8-bit character from receiver */
    StatReg &= (uint32_t)(~(uint32_t)UART_S1_RDRF_MASK); /* Clear the receive data flag to discard the errorneous data */
  }
  if (StatReg & UART_S1_RDRF_MASK) {   /* Is the receiver's interrupt flag set? */
    InterruptRx(DeviceDataPrv);        /* If yes, then invoke the internal service routine. This routine is inlined. */
  }
  if (DeviceDataPrv->SerFlag & ENABLED_TX_INT) { /* Is the transmitter interrupt enabled? */
    if (StatReg & UART_S1_TDRE_MASK) { /* Is the transmitter empty? */
      InterruptTx(DeviceDataPrv);      /* If yes, then invoke the internal service routine. This routine is inlined. */
    }
  }
}

/*
** ===================================================================
**     Method      :  UART_ESP8266_SetClockConfiguration (component Serial_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it`s setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void UART_ESP8266_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration)
{
  UART_ESP8266_TDeviceDataPtr DeviceDataPrv = (UART_ESP8266_TDeviceDataPtr)DeviceDataPtr;

  switch (ClockConfiguration) {
    case CPU_CLOCK_CONFIG_0:
      UART_PDD_SetBaudRateFineAdjust(UART3_BASE_PTR, 12u); /* Set baud rate fine adjust */
      UART_PDD_SetBaudRate(UART3_BASE_PTR, 11U); /* Set the baud rate register. */
      DeviceDataPrv->EnMode = TRUE;    /* Set the flag "device enabled" in the actual speed CPU mode */
      break;
    default:
      DeviceDataPrv->EnMode = FALSE;   /* Set the flag "device disabled" in the actual speed CPU mode */
      break;
  }
  HWEnDi(DeviceDataPtr);               /* Enable/disable device according to status flags */
}

/*lint -restore Enable MISRA rule (11.4,12.8) checking. */
/* END UART_ESP8266. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
