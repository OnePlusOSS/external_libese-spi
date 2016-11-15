/*
 * Copyright (C) 2010-2014 NXP Semiconductors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * OSAL header files related to Timer functions.
 */

#ifndef PHOSALESE_TIMER_H
#define PHOSALESE_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/*
************************* Include Files ****************************************
*/


/*
 * Timer callback interface which will be called once registered timer
 * time out expires.
 *        TimerId  - Timer Id for which callback is called.
 *        pContext - Parameter to be passed to the callback function
 */
typedef void (*pphOsalEse_TimerCallbck_t)(uint32_t TimerId, void *pContext);

/*
 * The Timer could not be created due to a
 * system error */
#define PH_OSALESE_TIMER_CREATE_ERROR                   (0X00E0)

/*
 * The Timer could not be started due to a
 * system error or invalid handle */
#define PH_OSALESE_TIMER_START_ERROR                    (0X00E1)

/*
 * The Timer could not be stopped due to a
 * system error or invalid handle */
#define PH_OSALESE_TIMER_STOP_ERROR                     (0X00E2)

/*
 * The Timer could not be deleted due to a
 * system error or invalid handle */
#define PH_OSALESE_TIMER_DELETE_ERROR                   (0X00E3)

/*
 * Invalid timer ID type.This ID used indicate timer creation is failed */
#define PH_OSALESE_TIMER_ID_INVALID                     (0xFFFF)

/*
 * OSAL timer message .This message type will be posted to
 * calling application thread.*/
#define PH_OSALESE_TIMER_MSG                            (0x315)

/*
***************************Globals,Structure and Enumeration ******************
*/

uint32_t phOsalEse_Timer_Create(void);
ESESTATUS phOsalEse_Timer_Start(uint32_t dwTimerId, uint32_t dwRegTimeCnt, pphOsalEse_TimerCallbck_t pApplication_callback, void *pContext);
ESESTATUS phOsalEse_Timer_Stop(uint32_t dwTimerId);
ESESTATUS phOsalEse_Timer_Delete(uint32_t dwTimerId);
void phOsalEse_Timer_Cleanup(void);
uint32_t phUtilEse_CheckForAvailableTimer(void);
ESESTATUS phOsalEse_CheckTimerPresence(void *pObjectHandle);


#ifdef __cplusplus
}
#endif /*  C++ Compilation guard */
#endif /* PHOSALESE_TIMER_H */
