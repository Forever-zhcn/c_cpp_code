# Makefile for your project

# 定义删除命令
ifdef SystemRoot
    RM = del /Q
    MKDIR = mkdir
    FIXPATH = $(subst /,\,$1)
else
    RM = rm -f
    MKDIR = mkdir -p
    FIXPATH = $1
endif

PREFIX = 

# Compiler 编译器
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
CXX = $(GCC_PATH)/$(PREFIX)g++
else
CC = $(PREFIX)gcc
CXX = $(PREFIX)g++
endif


BUILD_DIR = build

# Executable name 可执行文件名
TARGET_DIR := $(BUILD_DIR)
TARGET := $(TARGET_DIR)/app.exe

# 通过 find 命令递归地搜索所有的 .c .cpp 文件
SRC_DIRS := ./
C_SRCS := $(shell find $(SRC_DIRS) -name "*.c")
CXX_SRCS := $(shell find $(SRC_DIRS) -name "*.cpp")
# Source files 源文件
# C_SRCS :=  $(wildcard src/*.c)
# C_SRCS += $(wildcard lib/**/*.c)

# VPATH 告诉 make 在哪里寻找源文件 VPATH是makefile中的特殊变量
VPATH := $(shell find $(SRC_DIRS) -type d)
C_PATH += $(VPATH)

# 添加 -I 标志来指定每个头文件目录
INCLUDES_FLAG := -I
C_SOURCES += $(C_SRCS)
CXX_SOURCES += $(CXX_SRCS)
C_INCLUDES += $(foreach dir,$(C_PATH),$(INCLUDES_FLAG)$(dir))

# list of c objects
OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of cpp objects 
OBJS += $(addprefix $(BUILD_DIR)/,$(notdir $(CXX_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CXX_SOURCES)))



# Compiler flags 编译器标志
CFLAGS := -Wall -Wextra -g
# 禁用未使用参数的警告
CFLAGS += -Wno-unused-parameter
# 禁用关于误导性缩进的警告。
CFLAGS += -Wno-misleading-indentation
# 禁用有关隐式控制流穿透的警告
# CFLAGS += -Wno-implicit-fallthrough
CFLAGS += $(C_INCLUDES)
CXXFLAGS += $(CFLAGS)


# 每次创建了新目录下的文件都要对

# Build rule for the executable 可执行文件的构建规则（链接）
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^
#	@echo CC $<

# $(TARGET): $(OBJS) | $(TARGET_DIR)
$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo linking $@

# $(TARGET_DIR):
# 	$(MKDIR) $@

# Build rule for object files 目标文件的构建规则(编译)
$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo Compiler $<

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<
	@echo Compiler $<

# Build rule for assembly files 编译生成汇编文件的规则
$(BUILD_DIR)/%.s: %.c Makefile | $(BUILD_DIR)
	$(CC) -S $< -o $@
$(BUILD_DIR)/%.s: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) -S $< -o $@

$(BUILD_DIR):
	$(MKDIR) $@



# Phony target to clean the project 伪目标，用于清理项目
.PHONY: clean
clean:
	$(RM) $(call FIXPATH,$(TARGET))
	$(RM) $(call FIXPATH,$(OBJS))
#	$(RM) $(BUILD_DIR)/*
