#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=devices/mpu9250.c devices/statusLED.c peripherals/motor.c devices/serialReceiver.c devices/24fc512.c peripherals/timers/timer1.c peripherals/timers/timer2.c peripherals/timers/timer3.c peripherals/timers/timer4.c peripherals/adc.c peripherals/i2c.c peripherals/pwm.c peripherals/vbatt.c peripherals/dma.c peripherals/uart.c utilities/conversion.c utilities/delay.c utilities/commandUI.c main.c watchDogTimer.c pid.c pidVar.c flightMode.c filters.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/devices/mpu9250.o ${OBJECTDIR}/devices/statusLED.o ${OBJECTDIR}/peripherals/motor.o ${OBJECTDIR}/devices/serialReceiver.o ${OBJECTDIR}/devices/24fc512.o ${OBJECTDIR}/peripherals/timers/timer1.o ${OBJECTDIR}/peripherals/timers/timer2.o ${OBJECTDIR}/peripherals/timers/timer3.o ${OBJECTDIR}/peripherals/timers/timer4.o ${OBJECTDIR}/peripherals/adc.o ${OBJECTDIR}/peripherals/i2c.o ${OBJECTDIR}/peripherals/pwm.o ${OBJECTDIR}/peripherals/vbatt.o ${OBJECTDIR}/peripherals/dma.o ${OBJECTDIR}/peripherals/uart.o ${OBJECTDIR}/utilities/conversion.o ${OBJECTDIR}/utilities/delay.o ${OBJECTDIR}/utilities/commandUI.o ${OBJECTDIR}/main.o ${OBJECTDIR}/watchDogTimer.o ${OBJECTDIR}/pid.o ${OBJECTDIR}/pidVar.o ${OBJECTDIR}/flightMode.o ${OBJECTDIR}/filters.o
POSSIBLE_DEPFILES=${OBJECTDIR}/devices/mpu9250.o.d ${OBJECTDIR}/devices/statusLED.o.d ${OBJECTDIR}/peripherals/motor.o.d ${OBJECTDIR}/devices/serialReceiver.o.d ${OBJECTDIR}/devices/24fc512.o.d ${OBJECTDIR}/peripherals/timers/timer1.o.d ${OBJECTDIR}/peripherals/timers/timer2.o.d ${OBJECTDIR}/peripherals/timers/timer3.o.d ${OBJECTDIR}/peripherals/timers/timer4.o.d ${OBJECTDIR}/peripherals/adc.o.d ${OBJECTDIR}/peripherals/i2c.o.d ${OBJECTDIR}/peripherals/pwm.o.d ${OBJECTDIR}/peripherals/vbatt.o.d ${OBJECTDIR}/peripherals/dma.o.d ${OBJECTDIR}/peripherals/uart.o.d ${OBJECTDIR}/utilities/conversion.o.d ${OBJECTDIR}/utilities/delay.o.d ${OBJECTDIR}/utilities/commandUI.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/watchDogTimer.o.d ${OBJECTDIR}/pid.o.d ${OBJECTDIR}/pidVar.o.d ${OBJECTDIR}/flightMode.o.d ${OBJECTDIR}/filters.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/devices/mpu9250.o ${OBJECTDIR}/devices/statusLED.o ${OBJECTDIR}/peripherals/motor.o ${OBJECTDIR}/devices/serialReceiver.o ${OBJECTDIR}/devices/24fc512.o ${OBJECTDIR}/peripherals/timers/timer1.o ${OBJECTDIR}/peripherals/timers/timer2.o ${OBJECTDIR}/peripherals/timers/timer3.o ${OBJECTDIR}/peripherals/timers/timer4.o ${OBJECTDIR}/peripherals/adc.o ${OBJECTDIR}/peripherals/i2c.o ${OBJECTDIR}/peripherals/pwm.o ${OBJECTDIR}/peripherals/vbatt.o ${OBJECTDIR}/peripherals/dma.o ${OBJECTDIR}/peripherals/uart.o ${OBJECTDIR}/utilities/conversion.o ${OBJECTDIR}/utilities/delay.o ${OBJECTDIR}/utilities/commandUI.o ${OBJECTDIR}/main.o ${OBJECTDIR}/watchDogTimer.o ${OBJECTDIR}/pid.o ${OBJECTDIR}/pidVar.o ${OBJECTDIR}/flightMode.o ${OBJECTDIR}/filters.o

# Source Files
SOURCEFILES=devices/mpu9250.c devices/statusLED.c peripherals/motor.c devices/serialReceiver.c devices/24fc512.c peripherals/timers/timer1.c peripherals/timers/timer2.c peripherals/timers/timer3.c peripherals/timers/timer4.c peripherals/adc.c peripherals/i2c.c peripherals/pwm.c peripherals/vbatt.c peripherals/dma.c peripherals/uart.c utilities/conversion.c utilities/delay.c utilities/commandUI.c main.c watchDogTimer.c pid.c pidVar.c flightMode.c filters.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX170F256D
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/devices/mpu9250.o: devices/mpu9250.c  .generated_files/flags/default/4af7080cb8af9674a4bff838597c7e218333ac37 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/mpu9250.o.d 
	@${RM} ${OBJECTDIR}/devices/mpu9250.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/mpu9250.o.d" -o ${OBJECTDIR}/devices/mpu9250.o devices/mpu9250.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/statusLED.o: devices/statusLED.c  .generated_files/flags/default/fe8ef6fb086851c22e8fa4e4aafa28ab5f681cc7 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/statusLED.o.d 
	@${RM} ${OBJECTDIR}/devices/statusLED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/statusLED.o.d" -o ${OBJECTDIR}/devices/statusLED.o devices/statusLED.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/motor.o: peripherals/motor.c  .generated_files/flags/default/9f495c5c686131da2269ea57e9d69bc4b77c6a66 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/motor.o.d 
	@${RM} ${OBJECTDIR}/peripherals/motor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/motor.o.d" -o ${OBJECTDIR}/peripherals/motor.o peripherals/motor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/serialReceiver.o: devices/serialReceiver.c  .generated_files/flags/default/ee749bae74de4350b167b78e76e47113f5d0f398 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/serialReceiver.o.d 
	@${RM} ${OBJECTDIR}/devices/serialReceiver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/serialReceiver.o.d" -o ${OBJECTDIR}/devices/serialReceiver.o devices/serialReceiver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/24fc512.o: devices/24fc512.c  .generated_files/flags/default/83b12e532a4c04f52a28d7cc1617440f3070248 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/24fc512.o.d 
	@${RM} ${OBJECTDIR}/devices/24fc512.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/24fc512.o.d" -o ${OBJECTDIR}/devices/24fc512.o devices/24fc512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer1.o: peripherals/timers/timer1.c  .generated_files/flags/default/497312e22e136ce41bfb2ff3d4de5a8b29bdec2f .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer1.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer1.o.d" -o ${OBJECTDIR}/peripherals/timers/timer1.o peripherals/timers/timer1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer2.o: peripherals/timers/timer2.c  .generated_files/flags/default/3d850d23303cae307ab534f3cb04c7cc3d30dd3b .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer2.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer2.o.d" -o ${OBJECTDIR}/peripherals/timers/timer2.o peripherals/timers/timer2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer3.o: peripherals/timers/timer3.c  .generated_files/flags/default/3a3cde8f71867dc409d3276e38fb131a7c64998d .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer3.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer3.o.d" -o ${OBJECTDIR}/peripherals/timers/timer3.o peripherals/timers/timer3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer4.o: peripherals/timers/timer4.c  .generated_files/flags/default/4ad99cdd71794f955f1746ceadd26c1efc772a38 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer4.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer4.o.d" -o ${OBJECTDIR}/peripherals/timers/timer4.o peripherals/timers/timer4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/adc.o: peripherals/adc.c  .generated_files/flags/default/20cae68c0354966f54185aade5b584ebc6a6f826 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/adc.o.d 
	@${RM} ${OBJECTDIR}/peripherals/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/adc.o.d" -o ${OBJECTDIR}/peripherals/adc.o peripherals/adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/i2c.o: peripherals/i2c.c  .generated_files/flags/default/9e7784de770157ecaca33568970af0bd9b24cce9 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o.d 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/i2c.o.d" -o ${OBJECTDIR}/peripherals/i2c.o peripherals/i2c.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/pwm.o: peripherals/pwm.c  .generated_files/flags/default/d8c9f930eaeec276417811f5d82ef39a13e03abc .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/pwm.o.d 
	@${RM} ${OBJECTDIR}/peripherals/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/pwm.o.d" -o ${OBJECTDIR}/peripherals/pwm.o peripherals/pwm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/vbatt.o: peripherals/vbatt.c  .generated_files/flags/default/eac8c0ff213b8d3444dbe7b92855d43262e64913 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/vbatt.o.d 
	@${RM} ${OBJECTDIR}/peripherals/vbatt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/vbatt.o.d" -o ${OBJECTDIR}/peripherals/vbatt.o peripherals/vbatt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/dma.o: peripherals/dma.c  .generated_files/flags/default/5cd503b7b8d49c3ffccf0608ed8da4808f420ec1 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/dma.o.d 
	@${RM} ${OBJECTDIR}/peripherals/dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/dma.o.d" -o ${OBJECTDIR}/peripherals/dma.o peripherals/dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/uart.o: peripherals/uart.c  .generated_files/flags/default/df00dbc9ae329ad523e68010f17c5139f591adf3 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/uart.o.d 
	@${RM} ${OBJECTDIR}/peripherals/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/uart.o.d" -o ${OBJECTDIR}/peripherals/uart.o peripherals/uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/conversion.o: utilities/conversion.c  .generated_files/flags/default/37d4efb48a871931c31a8252f78961693b0ae727 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/conversion.o.d 
	@${RM} ${OBJECTDIR}/utilities/conversion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/conversion.o.d" -o ${OBJECTDIR}/utilities/conversion.o utilities/conversion.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/delay.o: utilities/delay.c  .generated_files/flags/default/7c5ec8e405d59f1c286134512a187c193dce8f54 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/delay.o.d 
	@${RM} ${OBJECTDIR}/utilities/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/delay.o.d" -o ${OBJECTDIR}/utilities/delay.o utilities/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/commandUI.o: utilities/commandUI.c  .generated_files/flags/default/ca743f5cb53d85859b3f36bbef7e6d68eab9ba85 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/commandUI.o.d 
	@${RM} ${OBJECTDIR}/utilities/commandUI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/commandUI.o.d" -o ${OBJECTDIR}/utilities/commandUI.o utilities/commandUI.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/992fac43229837060fb574324d024e071b67cd16 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/watchDogTimer.o: watchDogTimer.c  .generated_files/flags/default/535f7b22e4db7d8c0bc6e10ae7eb4fb73bdfdbea .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watchDogTimer.o.d 
	@${RM} ${OBJECTDIR}/watchDogTimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/watchDogTimer.o.d" -o ${OBJECTDIR}/watchDogTimer.o watchDogTimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/pid.o: pid.c  .generated_files/flags/default/8345d35e7a8c6ab694261f06fc94f1e9cd5405d6 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pid.o.d 
	@${RM} ${OBJECTDIR}/pid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/pid.o.d" -o ${OBJECTDIR}/pid.o pid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/pidVar.o: pidVar.c  .generated_files/flags/default/4720dd4c932e69d6514b20e30d97410114bef4d1 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pidVar.o.d 
	@${RM} ${OBJECTDIR}/pidVar.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/pidVar.o.d" -o ${OBJECTDIR}/pidVar.o pidVar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/flightMode.o: flightMode.c  .generated_files/flags/default/42548a3b8ddb9fb627c3befc5513a8d25b5a098e .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flightMode.o.d 
	@${RM} ${OBJECTDIR}/flightMode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/flightMode.o.d" -o ${OBJECTDIR}/flightMode.o flightMode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/filters.o: filters.c  .generated_files/flags/default/1a232a9f5351ad0e7127f8a2d4b7bc13f06d2b8c .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filters.o.d 
	@${RM} ${OBJECTDIR}/filters.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/filters.o.d" -o ${OBJECTDIR}/filters.o filters.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/devices/mpu9250.o: devices/mpu9250.c  .generated_files/flags/default/5bca42ea14efd51f1a160c3f94e0bbe7f8456c8d .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/mpu9250.o.d 
	@${RM} ${OBJECTDIR}/devices/mpu9250.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/mpu9250.o.d" -o ${OBJECTDIR}/devices/mpu9250.o devices/mpu9250.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/statusLED.o: devices/statusLED.c  .generated_files/flags/default/4be121a592fdf72790c1378413e748bef8a3a76b .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/statusLED.o.d 
	@${RM} ${OBJECTDIR}/devices/statusLED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/statusLED.o.d" -o ${OBJECTDIR}/devices/statusLED.o devices/statusLED.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/motor.o: peripherals/motor.c  .generated_files/flags/default/99b3183ccba98c0a308211f4b9374738ef3b8c11 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/motor.o.d 
	@${RM} ${OBJECTDIR}/peripherals/motor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/motor.o.d" -o ${OBJECTDIR}/peripherals/motor.o peripherals/motor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/serialReceiver.o: devices/serialReceiver.c  .generated_files/flags/default/f75639e6f94180af927de7f4f4fd1bef7aa00f03 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/serialReceiver.o.d 
	@${RM} ${OBJECTDIR}/devices/serialReceiver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/serialReceiver.o.d" -o ${OBJECTDIR}/devices/serialReceiver.o devices/serialReceiver.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/devices/24fc512.o: devices/24fc512.c  .generated_files/flags/default/2d188b1bb6a591d4663d4c036e284c971dd052bd .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/devices" 
	@${RM} ${OBJECTDIR}/devices/24fc512.o.d 
	@${RM} ${OBJECTDIR}/devices/24fc512.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/devices/24fc512.o.d" -o ${OBJECTDIR}/devices/24fc512.o devices/24fc512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer1.o: peripherals/timers/timer1.c  .generated_files/flags/default/888c0f19f1f0c03b7be5fefe6f690adf37b456b4 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer1.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer1.o.d" -o ${OBJECTDIR}/peripherals/timers/timer1.o peripherals/timers/timer1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer2.o: peripherals/timers/timer2.c  .generated_files/flags/default/2f4ae00c5d0a6e206157219fe3a74001514a1707 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer2.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer2.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer2.o.d" -o ${OBJECTDIR}/peripherals/timers/timer2.o peripherals/timers/timer2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer3.o: peripherals/timers/timer3.c  .generated_files/flags/default/c49dc20c9dbb0aefaf27973ba4adec5e79076ccb .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer3.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer3.o.d" -o ${OBJECTDIR}/peripherals/timers/timer3.o peripherals/timers/timer3.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/timers/timer4.o: peripherals/timers/timer4.c  .generated_files/flags/default/4cd36d59ae8328df6af9bdccc300fbbd65ea08b4 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals/timers" 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer4.o.d 
	@${RM} ${OBJECTDIR}/peripherals/timers/timer4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/timers/timer4.o.d" -o ${OBJECTDIR}/peripherals/timers/timer4.o peripherals/timers/timer4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/adc.o: peripherals/adc.c  .generated_files/flags/default/5c796e16e74bf627486a591b3a0ea4988e15f01c .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/adc.o.d 
	@${RM} ${OBJECTDIR}/peripherals/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/adc.o.d" -o ${OBJECTDIR}/peripherals/adc.o peripherals/adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/i2c.o: peripherals/i2c.c  .generated_files/flags/default/d6f189001eb6bc1e56201eb3336b532fd79a20f1 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o.d 
	@${RM} ${OBJECTDIR}/peripherals/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/i2c.o.d" -o ${OBJECTDIR}/peripherals/i2c.o peripherals/i2c.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/pwm.o: peripherals/pwm.c  .generated_files/flags/default/1d43a1a3c61b75c23bc632bb2d3c3bd8d82c7f39 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/pwm.o.d 
	@${RM} ${OBJECTDIR}/peripherals/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/pwm.o.d" -o ${OBJECTDIR}/peripherals/pwm.o peripherals/pwm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/vbatt.o: peripherals/vbatt.c  .generated_files/flags/default/3d59b95149a8862017e6e37d0bf17df032c6df7c .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/vbatt.o.d 
	@${RM} ${OBJECTDIR}/peripherals/vbatt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/vbatt.o.d" -o ${OBJECTDIR}/peripherals/vbatt.o peripherals/vbatt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/dma.o: peripherals/dma.c  .generated_files/flags/default/398076f148771f7e5507f3a932b25824d52804b3 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/dma.o.d 
	@${RM} ${OBJECTDIR}/peripherals/dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/dma.o.d" -o ${OBJECTDIR}/peripherals/dma.o peripherals/dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/peripherals/uart.o: peripherals/uart.c  .generated_files/flags/default/152172a4381aea15ce0ae6084ed929f22106e7e .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/peripherals" 
	@${RM} ${OBJECTDIR}/peripherals/uart.o.d 
	@${RM} ${OBJECTDIR}/peripherals/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/peripherals/uart.o.d" -o ${OBJECTDIR}/peripherals/uart.o peripherals/uart.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/conversion.o: utilities/conversion.c  .generated_files/flags/default/e7899d2d98bbc9c24167264874782b03e5c3523c .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/conversion.o.d 
	@${RM} ${OBJECTDIR}/utilities/conversion.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/conversion.o.d" -o ${OBJECTDIR}/utilities/conversion.o utilities/conversion.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/delay.o: utilities/delay.c  .generated_files/flags/default/4921b4cd770770404e99fa8a4a2a60dffc65a811 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/delay.o.d 
	@${RM} ${OBJECTDIR}/utilities/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/delay.o.d" -o ${OBJECTDIR}/utilities/delay.o utilities/delay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/utilities/commandUI.o: utilities/commandUI.c  .generated_files/flags/default/a00327b488909434afc06135ee40a221671138c .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}/utilities" 
	@${RM} ${OBJECTDIR}/utilities/commandUI.o.d 
	@${RM} ${OBJECTDIR}/utilities/commandUI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/utilities/commandUI.o.d" -o ${OBJECTDIR}/utilities/commandUI.o utilities/commandUI.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f67c45292002960260930fc8334fcad46cf3c640 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/watchDogTimer.o: watchDogTimer.c  .generated_files/flags/default/d627f41b8d9be718ed35c994a567d03ab86671fe .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/watchDogTimer.o.d 
	@${RM} ${OBJECTDIR}/watchDogTimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/watchDogTimer.o.d" -o ${OBJECTDIR}/watchDogTimer.o watchDogTimer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/pid.o: pid.c  .generated_files/flags/default/de0981a3ef3c1f0b7ed589112c2ae25d86b9809b .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pid.o.d 
	@${RM} ${OBJECTDIR}/pid.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/pid.o.d" -o ${OBJECTDIR}/pid.o pid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/pidVar.o: pidVar.c  .generated_files/flags/default/405168f713382766f266eb6f38861aab93722037 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pidVar.o.d 
	@${RM} ${OBJECTDIR}/pidVar.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/pidVar.o.d" -o ${OBJECTDIR}/pidVar.o pidVar.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/flightMode.o: flightMode.c  .generated_files/flags/default/648f4cb4e5ce8beaf36d23eaa0720190b7102ad0 .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flightMode.o.d 
	@${RM} ${OBJECTDIR}/flightMode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/flightMode.o.d" -o ${OBJECTDIR}/flightMode.o flightMode.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/filters.o: filters.c  .generated_files/flags/default/a248882e99bc7dee9c1c017616163113a2ae800e .generated_files/flags/default/411a0bba36ae87630292d0c795f181b015b09521
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filters.o.d 
	@${RM} ${OBJECTDIR}/filters.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/filters.o.d" -o ${OBJECTDIR}/filters.o filters.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -std=gnu99 -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Micro_Quad_Flight_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
