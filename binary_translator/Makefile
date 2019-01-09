#CXX=clang++

LLVM_MODULES = native
#LLVM_MODULES = core jit native

CPPFLAGS = `llvm-config --cxxflags`
LDFLAGS = `llvm-config --ldflags`
LIBS = `llvm-config --libs`
SYSLIBS = `llvm-config --system-libs`

#FUNC_FILES = llvm_funcs/end_only.cpp llvm_funcs/begin_only.cpp llvm_funcs/active_pps_decl.cpp
PP_FILES = llvm_funcs/pp_functions/end_only.cpp llvm_funcs/pp_functions/begin_only.cpp 
MOCK_FILES = llvm_funcs/mock_functions/end_only.cpp llvm_funcs/mock_functions/begin_only.cpp 
HELPER_FILES = pp_ingest.cpp llvm_funcs/active_pps.cpp llvm_funcs/trust_pp_nos.cpp llvm_funcs/duration_check_pp_nos.cpp

all:
	$(CXX) ll_reader.cpp $(PP_FILES) $(HELPER_FILES) $(LDFLAGS) $(LIBS) $(SYSLIBS) -o xllvm_pp_writer -std=c++11 -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -frtti 
mocks:
	$(CXX) ll_reader.cpp $(MOCK_FILES) $(HELPER_FILES) $(LDFLAGS) $(LIBS) $(SYSLIBS) -o xllvm_pp_writer.mockprints -std=c++11 -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -frtti
main:
	find -name '*.cpp' -print0 | xargs -0 $(CC) -c $(CPPFLAGS)
