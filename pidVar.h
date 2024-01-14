/* 
 * File:   pidVar.h
 * Author: Jennyston
 *
 * Created on June 24, 2016, 5:31 PM
 */

#ifndef PIDVAR_H
#define	PIDVAR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define PITCH 0
#define ROLL 1
#define YAW 2
#define PITCH_ANGLE 3
#define ROLL_ANGLE 4
#define NUM_PID 5
    
#define DEFAULT_KP 180
#define DEFAULT_KI 5
#define DEFAULT_KD 40
    
#define DEFAULT_ANGLE_KP (1.0f)
#define DEFAULT_ANGLE_KI (0.4f)
#define DEFAULT_ANGLE_KD (3.0f)
    
    typedef struct
    {
        float kP;
        float kI;
        float kD;
        float integral;
        float preError;
    } PIDVar;

    void InitPIDVar();
    void SetPIDVar(PIDVar pid, unsigned int axis);
    void ResetPIDVarIntegral(unsigned int axis);
    void SetKP(float kP, unsigned int axis);
    void SetKI(float kI, unsigned int axis);
    void SetKD(float kD, unsigned int axis);
    PIDVar GetPIDVar(unsigned int axis);
    PIDVar *GetPIDVarPtr(unsigned int axis);
    float GetKP(unsigned int axis);
    float GetKI(unsigned int axis);
    float GetKD(unsigned int axis);

#ifdef	__cplusplus
}
#endif

#endif	/* PIDVAR_H */

