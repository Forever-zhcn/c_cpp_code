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


# Compiler flags 编译器标志
CFLAGS := -Wall -Wextra -g
# 禁用未使用参数的警告
CFLAGS += -Wno-unused-parameter
# 禁用未使用函数的警告
CFLAGS += -Wno-unused-function
# 禁用关于误导性缩进的警告。
CFLAGS += -Wno-misleading-indentation
# 禁用有关隐式控制流穿透的警告
# 当一个switch语句中的case标签没有显式地使用break语句时，编译器会发出隐式贯穿警告
# CFLAGS += -Wno-implicit-fallthrough

# 用于指定执行字符集为GBK
CFLAGS += -fexec-charset=GBK



BUILD_DIR = build

# Executable name 可执行文件名
TARGET_DIR := $(BUILD_DIR)
TARGET := $(TARGET_DIR)/app.exe


#######################################
# 添加头文件路径
#######################################
# VPATH 告诉 make 在哪里寻找源文件 VPATH是makefile中的特殊变量
# 通过 find 命令递归地搜索所有的(-type d)目录类型文件
VPATH := $(shell find $(SRC_DIRS) -type d)
C_PATH += $(VPATH)

# 添加 -I 标志来指定每个头文件目录
INCLUDES_FLAG := -I
C_INCLUDES += $(foreach dir,$(C_PATH),$(INCLUDES_FLAG)$(dir))

CFLAGS += $(C_INCLUDES)


#######################################
# 添加源文件路径
#######################################
# 通过 find 命令递归地搜索的更目录路径，可以是多个但别重复冲突
SRC_DIRS := ./

# 通过 find 命令递归地搜索所有的 .c文件
# Source files 源文件
# C_SRCS :=  $(wildcard src/*.c)
# C_SRCS += $(wildcard lib/**/*.c)
C_SRCS := $(shell find $(SRC_DIRS) -name "*.c")
C_SOURCES += $(C_SRCS)


# list of c objects    
# 这行代码的作用是将C_SOURCES中的所有.c文件名转换为.o文件名，并在每个文件名前添加$(BUILD_DIR)/前缀
OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# 这行代码的作用是设置%.c文件的搜索路径。
# vpath函数用于指定在哪些目录中查找指定的文件。
# sort函数用于对目录进行排序，以确保搜索顺序是一致的。

# Build rule for object files 目标文件的构建规则(编译)
# 通过c文件生成 .o 目标文件
# Makefile 作为依赖项表示Makefile若被修改那么这个规则会被重新执行，即使它所依赖的源文件（%.c）没有发生变化。
$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo Compiler $<

# Build rule for assembly files 编译生成汇编文件的规则
# 通过c文件生成汇编文件
$(BUILD_DIR)/%.s: %.c Makefile | $(BUILD_DIR)
	$(CC) -S $< -o $@




#######################################
# cpp的步骤
#######################################

#######################################
# 添加头文件路径
#######################################
# VPATH := $(shell find $(SRC_DIRS) -type d)
# CXX_PATH += $(VPATH)

# # 添加 -I 标志来指定每个头文件目录
# INCLUDES_FLAG := -I
# CXX_INCLUDES += $(foreach dir,$(CXX_PATH),$(INCLUDES_FLAG)$(dir))

# CXXFLAGS += $(CXX_INCLUDES)
CXXFLAGS += $(CFLAGS)


#######################################
# 添加源文件路径
#######################################
# 通过 find 命令递归地搜索所有的.cpp 文件
CXX_SRCS := $(shell find $(SRC_DIRS) -name "*.cpp")
CXX_SOURCES += $(CXX_SRCS)


# list of cpp objects 
CXX_OBJS += $(addprefix $(BUILD_DIR)/,$(notdir $(CXX_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CXX_SOURCES)))

# Build rule for object files 目标文件的构建规则(编译)
$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<
	@echo Compiler $<
# Build rule for assembly files 编译生成汇编文件的规则
$(BUILD_DIR)/%.s: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) -S $< -o $@


#######################################
# 可执行文件的构建
#######################################
# Build rule for the executable 可执行文件的构建规则（链接）

# c
# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^
#	@echo 
# 	@echo linking $@

# cpp
$(TARGET): $(CXX_OBJS) $(OBJS) | $(TARGET_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo 
	@echo linking $@

# $(TARGET): $(CXX_OBJS) $(OBJS)
# 	@$(CXX) $(CXXFLAGS) -o $@ $^
#	@echo 
# 	@echo linking $@


$(BUILD_DIR):
	$(MKDIR) $@



# Phony target to clean the project 伪目标，用于清理项目
.PHONY: clean
clean:
	$(RM) $(call FIXPATH,$(TARGET))
	$(RM) $(call FIXPATH,$(OBJS))
#	$(RM) $(BUILD_DIR)/*
