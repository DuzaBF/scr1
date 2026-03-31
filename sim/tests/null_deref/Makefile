src_dir := $(dir $(lastword $(MAKEFILE_LIST)))

c_src := null_deref.c

include $(inc_dir)/common.mk

default: log_requested_tgt $(bld_dir)/null_deref.elf $(bld_dir)/null_deref.hex $(bld_dir)/null_deref.dump

log_requested_tgt:
	echo null_deref.hex>> $(bld_dir)/test_info

clean:
	$(RM) $(c_objs) $(asm_objs) $(bld_dir)/null_deref.elf $(bld_dir)/null_deref.hex $(bld_dir)/null_deref.dump