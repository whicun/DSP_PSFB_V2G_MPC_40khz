################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
yssources/DABcontrol.obj: ../yssources/DABcontrol.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/DABcontrol.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/main.obj: ../yssources/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/main.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysADC.obj: ../yssources/ysADC.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysADC.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysCAN.obj: ../yssources/ysCAN.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysCAN.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysDAC.obj: ../yssources/ysDAC.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysDAC.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysECAP.obj: ../yssources/ysECAP.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysECAP.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysPORT.obj: ../yssources/ysPORT.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysPORT.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysPWM.obj: ../yssources/ysPWM.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysPWM.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysSCI.obj: ../yssources/ysSCI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysSCI.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

yssources/ysSPI.obj: ../yssources/ysSPI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/Program Files/CCS/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/Includes" --include_path="C:/Users/Itsys/workspace_v6_0/DAB_V2G_MPC_40khz/ysincludes" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="yssources/ysSPI.pp" --obj_directory="yssources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


