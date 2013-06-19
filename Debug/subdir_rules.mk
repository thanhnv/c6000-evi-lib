################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
emac.obj: ../emac.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="emac.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

interrupt.obj: ../interrupt.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="interrupt.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

intvecs.obj: ../intvecs.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="intvecs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

pllc.obj: ../pllc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="pllc.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

psc.obj: ../psc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="psc.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

sdram.obj: ../sdram.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="sdram.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

systemConfigurations.obj: ../systemConfigurations.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="systemConfigurations.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: ../timer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="timer.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

uart.obj: ../uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6740 --abi=coffabi -g --include_path="/home/nvthanh/.texasinstrument/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/nvthanh/ti/sample/c6000-evi-lib" --gcc --define=c6745 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="uart.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


