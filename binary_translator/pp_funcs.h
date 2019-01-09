#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"

using namespace llvm;

Function *define_pp_end(Module *  , GlobalVariable*, GlobalVariable*, GlobalVariable*);
Function *define_pp_begin(Module *, GlobalVariable*, GlobalVariable*, GlobalVariable*);
//Function *define_pp_end(Module *  );
//Function *define_pp_begin(Module *);
//GlobalVariable *makeActivePpsVariable(Module *);
GlobalVariable *define_active_pps(Module *);
GlobalVariable *define_trust_pp_nos(Module *);
GlobalVariable *define_duration_check_pp_nos(Module *);
