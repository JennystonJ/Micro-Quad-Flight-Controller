/* 
 * File:   watchDogTimer.h
 * Author: Jennyston
 *
 * Created on April 19, 2016, 9:13 PM
 */

#ifndef WATCHDOGTIMER_H
#define	WATCHDOGTIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

    void InitWatchDogTimer();
    void ResetWatchDogTimer();
    void ResumeWatchDogTimer();
    void StopWatchDogTimer();


#ifdef	__cplusplus
}
#endif

#endif	/* WATCHDOGTIMER_H */

