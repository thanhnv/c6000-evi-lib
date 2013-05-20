################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utilities/xprintf.obj: ../utilities/xprintf.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utilities/xprintf.pp" --obj_directory="utilities" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


