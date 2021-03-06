# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Hazel_config = debug
  Sandbox_config = debug

else ifeq ($(config),release)
  Hazel_config = release
  Sandbox_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := Hazel Sandbox

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Hazel:
ifneq (,$(Hazel_config))
	@echo "==== Building Hazel ($(Hazel_config)) ===="
	@${MAKE} --no-print-directory -C Hazel -f Makefile config=$(Hazel_config)
endif

Sandbox: Hazel
ifneq (,$(Sandbox_config))
	@echo "==== Building Sandbox ($(Sandbox_config)) ===="
	@${MAKE} --no-print-directory -C Sandbox -f Makefile config=$(Sandbox_config)
endif

clean:
	@${MAKE} --no-print-directory -C Hazel -f Makefile clean
	@${MAKE} --no-print-directory -C Sandbox -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Hazel"
	@echo "   Sandbox"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"