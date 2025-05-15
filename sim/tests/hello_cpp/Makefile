src_dir := $(dir $(lastword $(MAKEFILE_LIST)))


cpp_src := hello.cpp

name := hello

ADD_ASM_MACRO ?= -D__ASSEMBLY__=1

FLAGS = 
FLAGS_STR = "$(FLAGS)"

CXXFLAGS_COMMON = -static -std=c++17 -fno-common -fno-builtin-printf -DTCM=$(TCM)
CXXFLAGS_ARCH = -Wa,-march=rv32$(ARCH)_zicsr_zifencei -march=rv32$(ARCH)_zicsr_zifencei -mabi=$(ABI)

CXXFLAGS := $(FLAGS) $(EXT_CXXFLAGS) \
$(CXXFLAGS_COMMON) \
$(CXXFLAGS_ARCH) \
-DFLAGS_STR=\"$(FLAGS_STR)\" \
$(ADD_CXXFLAGS)

LDFLAGS   ?= -nostartfiles -nostdlib -lc -lgcc -march=rv32$(ARCH)_zicsr_zifencei -mabi=$(ABI) --specs=nano.specs $(ADD_LDFLAGS)

ifeq (,$(findstring 0,$(TCM)))
ld_script ?= $(inc_dir)/link_tcm.ld
asm_src   ?= crt_tcm.S
else
ld_script ?= $(inc_dir)/link.ld
asm_src   ?= crt.S
endif

c_objs   := $(addprefix $(bld_dir)/,$(patsubst %.c, %.o, $(c_src)))
asm_objs := $(addprefix $(bld_dir)/,$(patsubst %.S, %.o, $(asm_src)))
cpp_objs   := $(addprefix $(bld_dir)/,$(patsubst %.cpp, %.o, $(cpp_src)))

VPATH += $(src_dir) $(inc_dir) $(ADD_VPATH)
incs  += -I$(src_dir) -I$(inc_dir) $(ADD_incs)

.PRECIOUS: $(bld_dir)/%.o

$(bld_dir)/%.o: %.S
	$(RISCV_CXX) $(CXXFLAGS) $(ADD_ASM_MACRO) -c $(incs) $< -o $@

$(bld_dir)/%.o: %.c
	$(RISCV_CXX) $(CXXFLAGS) -c $(incs) $< -o $@

$(bld_dir)/%.o: %.cpp
	$(RISCV_CXX) $(CXXFLAGS) -c $(incs) $< -o $@

$(bld_dir)/%.elf: $(ld_script) $(cpp_objs) $(c_objs) $(asm_objs)
	$(RISCV_CXX) -o $@ -T $^ $(LDFLAGS)

$(bld_dir)/%.hex: $(bld_dir)/%.elf
	$(RISCV_OBJCOPY) $^ $@

$(bld_dir)/%.dump: $(bld_dir)/%.elf
	$(RISCV_OBJDUMP) -D -w -x -S $^ > $@

default: log_requested_tgt $(bld_dir)/$(name).elf $(bld_dir)/$(name).hex $(bld_dir)/$(name).dump

log_requested_tgt:
	echo $(name).hex>> $(bld_dir)/test_info

clean:
	$(RM) $(c_objs) $(asm_objs) $(bld_dir)/$(name).elf $(bld_dir)/$(name).hex $(bld_dir)/$(name).dump