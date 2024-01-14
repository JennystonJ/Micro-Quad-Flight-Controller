/* 
 * File:   vbatt.h
 * Author: Jennyston
 *
 * Created on February 13, 2017, 4:37 PM
 */

#ifndef VBATT_H
#define	VBATT_H

#ifdef	__cplusplus
extern "C" {
#endif

    void InitVBatt();
    void InitLowVBattInterupt(float cutOffVoltage);
    void MeasureVBatt();
    float GetVBatt();


#ifdef	__cplusplus
}
#endif

#endif	/* VBATT_H */

