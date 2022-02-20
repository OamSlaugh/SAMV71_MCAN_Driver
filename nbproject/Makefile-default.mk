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
FINAL_IMAGE=${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
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
SOURCEFILES_QUOTED_IF_SPACED=startup_samv71q21b.c system_samv71q21b.c main.c mcan_driver.c can_scheduler.c can_logic.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/startup_samv71q21b.o ${OBJECTDIR}/system_samv71q21b.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcan_driver.o ${OBJECTDIR}/can_scheduler.o ${OBJECTDIR}/can_logic.o
POSSIBLE_DEPFILES=${OBJECTDIR}/startup_samv71q21b.o.d ${OBJECTDIR}/system_samv71q21b.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/mcan_driver.o.d ${OBJECTDIR}/can_scheduler.o.d ${OBJECTDIR}/can_logic.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/startup_samv71q21b.o ${OBJECTDIR}/system_samv71q21b.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcan_driver.o ${OBJECTDIR}/can_scheduler.o ${OBJECTDIR}/can_logic.o

# Source Files
SOURCEFILES=startup_samv71q21b.c system_samv71q21b.c main.c mcan_driver.c can_scheduler.c can_logic.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${DFP_DIR}/samv71b/include"  -I "${CMSIS_DIR}/CMSIS/Core/Include"



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=SAMV71Q21B
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
${OBJECTDIR}/startup_samv71q21b.o: startup_samv71q21b.c  .generated_files/flags/default/6024667f365c7f6ec23195685ee2072dbf99c3c3 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/startup_samv71q21b.o.d 
	@${RM} ${OBJECTDIR}/startup_samv71q21b.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/startup_samv71q21b.o.d" -o ${OBJECTDIR}/startup_samv71q21b.o startup_samv71q21b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/system_samv71q21b.o: system_samv71q21b.c  .generated_files/flags/default/64dc9214c1f0829d80a71cce553d9ee8187ca3f6 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system_samv71q21b.o.d 
	@${RM} ${OBJECTDIR}/system_samv71q21b.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/system_samv71q21b.o.d" -o ${OBJECTDIR}/system_samv71q21b.o system_samv71q21b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/4b232cf88bb86ce6277a1ac6e68e537103b5b9de .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcan_driver.o: mcan_driver.c  .generated_files/flags/default/c22eb27c99425a5f2feff6a4ba0af0b4802bdad3 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mcan_driver.o.d 
	@${RM} ${OBJECTDIR}/mcan_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/mcan_driver.o.d" -o ${OBJECTDIR}/mcan_driver.o mcan_driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/can_scheduler.o: can_scheduler.c  .generated_files/flags/default/1de8096a49b385dc4b9197ebca7c55e91f969cdb .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/can_scheduler.o.d 
	@${RM} ${OBJECTDIR}/can_scheduler.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/can_scheduler.o.d" -o ${OBJECTDIR}/can_scheduler.o can_scheduler.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/can_logic.o: can_logic.c  .generated_files/flags/default/5cf5d443a4421e63cc4c42f7ee47ae3565f57153 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/can_logic.o.d 
	@${RM} ${OBJECTDIR}/can_logic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7 -g -D__DEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/can_logic.o.d" -o ${OBJECTDIR}/can_logic.o can_logic.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/startup_samv71q21b.o: startup_samv71q21b.c  .generated_files/flags/default/ad192bde4574cf256c012f6f0d1763347e257003 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/startup_samv71q21b.o.d 
	@${RM} ${OBJECTDIR}/startup_samv71q21b.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/startup_samv71q21b.o.d" -o ${OBJECTDIR}/startup_samv71q21b.o startup_samv71q21b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/system_samv71q21b.o: system_samv71q21b.c  .generated_files/flags/default/c545919443858d8d2b38c58bc2411604661e6c91 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system_samv71q21b.o.d 
	@${RM} ${OBJECTDIR}/system_samv71q21b.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/system_samv71q21b.o.d" -o ${OBJECTDIR}/system_samv71q21b.o system_samv71q21b.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/5838120afc02ff7cd800c782711636d33a78d7f5 .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcan_driver.o: mcan_driver.c  .generated_files/flags/default/6b8a567a80baae9e3965ba4be3440b7a1d537cca .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mcan_driver.o.d 
	@${RM} ${OBJECTDIR}/mcan_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/mcan_driver.o.d" -o ${OBJECTDIR}/mcan_driver.o mcan_driver.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/can_scheduler.o: can_scheduler.c  .generated_files/flags/default/1455eba1cb3de6da43af0383203eb960ed39acaa .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/can_scheduler.o.d 
	@${RM} ${OBJECTDIR}/can_scheduler.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/can_scheduler.o.d" -o ${OBJECTDIR}/can_scheduler.o can_scheduler.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/can_logic.o: can_logic.c  .generated_files/flags/default/70a2defa3a8f4b1487a6cf910b6814df8cadf45a .generated_files/flags/default/70047b38e174f4f900106ad96232046bc9815e3b
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/can_logic.o.d 
	@${RM} ${OBJECTDIR}/can_logic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -mcpu=cortex-m7  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -mthumb ${PACK_COMMON_OPTIONS}  -Os -ffunction-sections -mlong-calls -Wall -MP -MMD -MF "${OBJECTDIR}/can_logic.o.d" -o ${OBJECTDIR}/can_logic.o can_logic.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    samv71q21b_flash.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=cortex-m7   -gdwarf-2  -D__$(MP_PROCESSOR_OPTION)__   -T"samv71q21b_flash.ld"  -mthumb --specs=nosys.specs -Wl,-Map="${DISTDIR}\SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.map"  -o ${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections  
	
	
	
	
	
	
else
${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   samv71q21b_flash.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=cortex-m7  -D__$(MP_PROCESSOR_OPTION)__   -T"samv71q21b_flash.ld"  -mthumb --specs=nosys.specs -Wl,-Map="${DISTDIR}\SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.map"  -o ${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections  
	
	${MP_CC_DIR}\\arm-none-eabi-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature "${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/SAMV71_MCAN_Driver.X.${IMAGE_TYPE}.hex"
	
	
	
	
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
