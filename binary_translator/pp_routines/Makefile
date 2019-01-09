PREFIX=/usr/local

BC_OPTS=-flto -Wl,-plugin-opt=emit-llvm

all: pp_begin_test.c pp_end_test.c pp_vars.c
	clang $(BC_OPTS) pp_begin_test.c -o begin_only.bc
	llc -march=cpp -cppgen=functions begin_only.bc
	clang $(BC_OPTS) pp_end_test.c -o end_only.bc
	llc -march=cpp -cppgen=functions end_only.bc
	clang $(BC_OPTS) pp_vars.c -o pp_vars.bc
	llc -march=cpp -cppgen=variable -cppfor=active_pps -o active_pps.cpp pp_vars.bc
	llc -march=cpp -cppgen=variable -cppfor=trust_pp_nos -o trust_pp_nos.cpp pp_vars.bc
	llc -march=cpp -cppgen=variable -cppfor=duration_check_pp_nos -o duration_check_pp_nos.cpp pp_vars.bc

tester: use_pp_functions.c pp_begin_test.c pp_end_test.c pp_vars.c
	gcc use_pp_functions.c pp_begin_test.c pp_end_test.c pp_vars.c -o xpp_begin_to_end -lrt -pthread

so: pp_begin_test.c pp_end_test.c pp_vars.c pp_call_impls.c
	gcc -shared -o libprogper.so -fPIC pp_begin_test.c pp_end_test.c pp_vars.c pp_call_impls.c
so_install: so
	sudo cp libprogper.so $(PREFIX)/lib64
	sudo cp progper.h $(PREFIX)/include

mock_so: pp_begin_test.c pp_end_test.c pp_vars.c pp_call_mocks.c
	gcc -shared -o libprogper_mock.so -fPIC pp_begin_test.c pp_end_test.c pp_vars.c pp_call_mocks.c
mock_so_install: mock_so
	sudo cp libprogper_mock.so $(PREFIX)/lib64
	sudo cp progper.h $(PREFIX)/include
	
notime_so: pp_begin_test_notime.c pp_end_test_notime.c pp_vars.c pp_call_impls.c
	gcc -shared -o libprogper_notime.so -fPIC pp_begin_test_notime.c pp_end_test_notime.c pp_vars.c pp_call_impls.c
notime_so_install: notime_so
	sudo cp libprogper_notime.so $(PREFIX)/lib64
	sudo cp progper.h $(PREFIX)/include

notime_mock_so: pp_begin_test_notime.c pp_end_test_notime.c pp_vars.c pp_call_mocks.c
	gcc -shared -o libprogper_notime_mock.so -fPIC pp_begin_test_notime.c pp_end_test_notime.c pp_vars.c pp_call_mocks.c
notime_mock_so_install: notime_mock_so
	sudo cp libprogper_notime_mock.so $(PREFIX)/lib64
	sudo cp progper.h $(PREFIX)/include

#	llc -march=cpp -cppgen=variable -cppfor=active_pps -o active_pps.cpp pp_vars.bc
#	llc -march=cpp -cppgen=variable -cppfor=trust_pp_nos -o trust_pp_nos.cpp pp_vars.bc
#	llc -march=cpp -cppgen=variable -cppfor=duration_check_pp_nos -o duration_check_pp_nos.cpp pp_vars.bc
