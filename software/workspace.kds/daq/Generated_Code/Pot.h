/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Pot.h
**     Project     : daq
**     Processor   : MK64FN1M0VLL12
**     Component   : ADC_LDD
**     Version     : Component 01.183, Driver 01.08, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-31, 14:14, # CodeGen: 4
**     Abstract    :
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : Pot
**          A/D converter                                  : ADC0
**          Discontinuous mode                             : no
**          Interrupt service/event                        : Disabled
**          DMA                                            : Disabled
**          A/D channel list                               : 1
**            Channel 0                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : ADC0_DP1
**          Static sample groups                           : Enabled
**            Sample group list                            : 1
**              Group 0                                    : 
**                Sample list                              : 1
**                  Sample 0                               : Enabled
**                    Channel index                        : 0
**          Max. samples                                   : 8
**          A/D resolution                                 : 16 bits
**          Low-power mode                                 : Disabled
**          High-speed conversion mode                     : Disabled
**          Asynchro clock output                          : Disabled
**          Sample time                                    : 4 clock periods
**          Number of conversions                          : 1
**          Conversion time                                : 4.807692 µs
**          ADC clock                                      : 5.242 MHz (190.735 ns)
**          Single conversion time - Single-ended          : 5.96 us
**          Single conversion time - Differential          : 7.677 us
**          Additional conversion time - Single-ended      : 4.768 us
**          Additional conversion time - Differential      : 6.484 us
**          Result type                                    : unsigned 16 bits, left justified
**          Trigger                                        : Disabled
**          Voltage reference                              : 
**            High voltage reference                       : 
**              Volt. ref. pin                             : VREFH
**            Low voltage reference                        : 
**              Volt. ref. pin                             : VREFL
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnMeasurementComplete                      : Disabled
**              OnError                                    : Disabled
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
**         Init                   - LDD_TDeviceData* Pot_Init(LDD_TUserData *UserDataPtr);
**         StartSingleMeasurement - LDD_TError Pot_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         GetMeasuredValues      - LDD_TError Pot_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         SelectSampleGroup      - LDD_TError Pot_SelectSampleGroup(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         CreateSampleGroup      - LDD_TError Pot_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr,...
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
** @file Pot.h
** @version 01.08
** @brief
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
*/         
/*!
**  @addtogroup Pot_module Pot module documentation
**  @{
*/         

#ifndef __Pot_H
#define __Pot_H

/* MODULE Pot. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "IO_Map.h"
#include "Cpu.h"

#include "ADC_PDD.h"

#ifdef __cplusplus
extern "C" { 
#endif


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define Pot_PRPH_BASE_ADDRESS  0x4003B000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define Pot_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_Pot_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define Pot_Init_METHOD_ENABLED        /*!< Init method of the component Pot is enabled (generated) */
#define Pot_StartSingleMeasurement_METHOD_ENABLED /*!< StartSingleMeasurement method of the component Pot is enabled (generated) */
#define Pot_GetMeasuredValues_METHOD_ENABLED /*!< GetMeasuredValues method of the component Pot is enabled (generated) */
#define Pot_SelectSampleGroup_METHOD_ENABLED /*!< SelectSampleGroup method of the component Pot is enabled (generated) */
#define Pot_CreateSampleGroup_METHOD_ENABLED /*!< CreateSampleGroup method of the component Pot is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */


/* Component specific public constants */

/* Driver mode */

/* A/D resolution of the component (the count of bits) */
#define Pot_ADC_RESOLUTION              16

/* Name of AD channel. If the "A/D channel (pin) signal" property in the channel
   pin group is not empty the constant "ComponentName_Signal" with the value of the channel
   index is generated, where the ComponentName = value of the "Component name" property
   and "Signal" is the value of the " A/D channel (pin) signal" property. This constant
   can be used in the method CreateSampleGroup() to specify required channel.
   (See ComponentName_TSample struct) */

/* This constant contains the number of channels in the "A/D channel list"
   group */
#define Pot_CHANNEL_COUNT               1u

/* This constant can be used in the sample array to create a gap in sample group.
   It is intended to disable a measurement of a sample */
#define Pot_NO_CHANNEL                  0x1FU

/* This constant contains the number of static sample groups */
#define Pot_STATIC_GROUP_COUNT          1U

/* These constants contain the number of samples in each static sample group. */
#define Pot_STATIC_GROUP_0_SAMPLE_COUNT 1U

/* This constant contains the maximal size through all static sample groups */
#define Pot_MAX_STATIC_GROUP_SAMPLE_COUNT 1U

/* HW specific public constants */

/* Maximal number of samples in one sample group. This constant is HW specific.
   The CreateSampleGroup() method returns ERR_PARAM_SAMPLE_COUNT if the SampleCount parameter
   is greater then this constant. The value of this constant depends on the number
   of samples the HW is capable to measure in one measurement cycle. */
#define Pot_MAX_HW_SAMPLE_COUNT         1U

/* This constant informs about the actual width of results. */
#define Pot_RESULT_WIDTH                16U

/* This constant informs about the native size of result in bytes */
#define Pot_RESULT_WIDTH_BYTES          2U

/* This parameter informs about the type of results. */
#define Pot_RESULT_TYPE_UNSIGNED

/* Measurement result data type. Definition of the type depends
   on "Result type" property value. */
typedef uint16_t Pot_TResultData;


/*
** ===================================================================
**     Method      :  Pot_Init (component ADC_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* Pot_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  Pot_StartSingleMeasurement (component ADC_LDD)
*/
/*!
**     @brief
**         This method starts one measurement of the selected group of
**         samples and exits immediately. This is ADC SW trigger method.
**         The group of samples for measurement is specified by
**         preceding call to [SelectSampleGroup()] or
**         [CreateSampleGroup] method. 
**         DMA disabled: The [OnMeasurementComplete() ] event is
**         invoked after the measurement is done and if the event is
**         enabled. Results of the measurement can be read by the
**         [GetMeasuredValues()] method. 
**         DMA enabled: DMA request from configured ADC is enabled
**         automatically. The [OnMeasurementComplete() ] event is
**         invoked after the requested number of results are
**         transferred to destination buffer by DMA and if the event is
**         enabled. [GetMeasuredValues()] method is not available if
**         DMA mode is enabled. If the DMA transfer was completed
**         before and DMA is not recofingured, DMA error can occur. See
**         also [SetBuffer()] method. 
**         The state of the measurement can be also polled by the
**         [GetMeasurementCompleteStatus()] method. The [Discontinuous
**         mode] doesn't support this method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A measurement is in progress 
*/
/* ===================================================================*/
LDD_TError Pot_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  Pot_SelectSampleGroup (component ADC_LDD)
*/
/*!
**     @brief
**         This method selects one of the (design-time) predefined
**         [Static sample groups] for the next measurement. Each call
**         rewrites the preceding setting. Once any group is selected,
**         the measurement can be started multiple times. Note: This
**         method works only with the sample groups defined at design
**         time. For run-time defined groups use [CreateSampleGroup()]
**         method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         GroupIndex      - Group index.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_GROUP - SampleGroup parameter
**                           value is out of range
**                           ERR_BUSY - Measurement is in progress 
*/
/* ===================================================================*/
LDD_TError Pot_SelectSampleGroup(LDD_TDeviceData *DeviceDataPtr, uint8_t GroupIndex);

/*
** ===================================================================
**     Method      :  Pot_CreateSampleGroup (component ADC_LDD)
*/
/*!
**     @brief
**         This method prepares HW for next measurement according to
**         array of samples defined during run-time. The array of
**         samples should be prepared prior to calling this method.
**         Pointer to the array is passed into this method in parameter
**         SampleGroupPtr. The number of samples is defined by
**         parameter SampleCount. Once any group is prepared, the
**         measurement can be started multiple times. Note: This method
**         works only with the sample groups defined during run-time.
**         For design-time defined groups use [SelectSampleGroup()]
**         method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         SampleGroupPtr  - Pointer to the
**                           sample definition array. This array can be
**                           released as soon as the method ends.
**     @param
**         SampleCount     - Number of items in the
**                           sample definition array. Must be less than
**                           or equal to
**                           ComponentName_MAX_HW_SAMPLE_COUNT.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_INDEX - Channel index in
**                           SampleGroup structure is out of range
**                           ERR_PARAM_SAMPLE_COUNT - SampleCount
**                           variable value is out of range
**                           ERR_BUSY - Measurement is in progress 
*/
/* ===================================================================*/
LDD_TError Pot_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr, LDD_ADC_TSample *SampleGroupPtr, uint8_t SampleCount);

/*
** ===================================================================
**     Method      :  Pot_GetMeasuredValues (component ADC_LDD)
*/
/*!
**     @brief
**         This method copies results of the last measurement to the
**         user supplied buffer. Data size depends on the size of
**         measured sample group (see [SelectSampleGroup()] or
**         [CreateSampleGroup()] method). Data representation is
**         defined by the [Result type] property. Typically this method
**         is called from [OnMeasurementComplete] event to get results
**         of the last measurement. This method is not available if DMA
**         is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to the start of the
**                           buffer for new results. Count of stored
**                           measured values equals to the count of the
**                           samples in the active sample group. It is
**                           in the user responsibility to provide
**                           buffer with appropriate size.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
*/
/* ===================================================================*/
LDD_TError Pot_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr);

/*
** ===================================================================
**     Method      :  Pot_SetClockConfiguration (component ADC_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Pot_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);

/* END Pot. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Pot_H */
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
