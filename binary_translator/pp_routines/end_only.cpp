// Generated by llvm2cpp - DO NOT MODIFY!


Function* define_pp_end(Module *mod) {

// Type Definitions
std::vector<Type*>FuncTy_0_args;
FuncTy_0_args.push_back(IntegerType::get(mod->getContext(), 64));
FuncTy_0_args.push_back(IntegerType::get(mod->getContext(), 32));
FunctionType* FuncTy_0 = FunctionType::get(
 /*Result=*/Type::getVoidTy(mod->getContext()),
 /*Params=*/FuncTy_0_args,
 /*isVarArg=*/false);

PointerType* PointerTy_1 = PointerType::get(IntegerType::get(mod->getContext(), 64), 0);

PointerType* PointerTy_2 = PointerType::get(IntegerType::get(mod->getContext(), 32), 0);

StructType *StructTy_struct_timespec = mod->getTypeByName("struct.timespec");
if (!StructTy_struct_timespec) {
StructTy_struct_timespec = StructType::create(mod->getContext(), "struct.timespec");
}
std::vector<Type*>StructTy_struct_timespec_fields;
StructTy_struct_timespec_fields.push_back(IntegerType::get(mod->getContext(), 64));
StructTy_struct_timespec_fields.push_back(IntegerType::get(mod->getContext(), 64));
if (StructTy_struct_timespec->isOpaque()) {
StructTy_struct_timespec->setBody(StructTy_struct_timespec_fields, /*isPacked=*/false);
}

PointerType* PointerTy_3 = PointerType::get(StructTy_struct_timespec, 0);

PointerType* PointerTy_4 = PointerType::get(PointerTy_3, 0);

PointerType* PointerTy_5 = PointerType::get(Type::getDoubleTy(mod->getContext()), 0);

std::vector<Type*>FuncTy_7_args;
FuncTy_7_args.push_back(IntegerType::get(mod->getContext(), 64));
FunctionType* FuncTy_7 = FunctionType::get(
 /*Result=*/IntegerType::get(mod->getContext(), 64),
 /*Params=*/FuncTy_7_args,
 /*isVarArg=*/true);

PointerType* PointerTy_6 = PointerType::get(FuncTy_7, 0);

ArrayType* ArrayTy_9 = ArrayType::get(IntegerType::get(mod->getContext(), 64), 128);

PointerType* PointerTy_8 = PointerType::get(ArrayTy_9, 0);

ArrayType* ArrayTy_11 = ArrayType::get(ArrayTy_9, 1024);

PointerType* PointerTy_10 = PointerType::get(ArrayTy_11, 0);

ArrayType* ArrayTy_13 = ArrayType::get(StructTy_struct_timespec, 128);

PointerType* PointerTy_12 = PointerType::get(ArrayTy_13, 0);

ArrayType* ArrayTy_15 = ArrayType::get(ArrayTy_13, 1024);

PointerType* PointerTy_14 = PointerType::get(ArrayTy_15, 0);

std::vector<Type*>FuncTy_17_args;
FuncTy_17_args.push_back(IntegerType::get(mod->getContext(), 32));
FuncTy_17_args.push_back(PointerTy_3);
FunctionType* FuncTy_17 = FunctionType::get(
 /*Result=*/IntegerType::get(mod->getContext(), 32),
 /*Params=*/FuncTy_17_args,
 /*isVarArg=*/false);

PointerType* PointerTy_16 = PointerType::get(FuncTy_17, 0);

PointerType* PointerTy_18 = PointerType::get(IntegerType::get(mod->getContext(), 8), 0);

ArrayType* ArrayTy_20 = ArrayType::get(IntegerType::get(mod->getContext(), 8), 22);

PointerType* PointerTy_19 = PointerType::get(ArrayTy_20, 0);

std::vector<Type*>FuncTy_22_args;
FuncTy_22_args.push_back(PointerTy_18);
FunctionType* FuncTy_22 = FunctionType::get(
 /*Result=*/Type::getVoidTy(mod->getContext()),
 /*Params=*/FuncTy_22_args,
 /*isVarArg=*/false);

PointerType* PointerTy_21 = PointerType::get(FuncTy_22, 0);

std::vector<Type*>FuncTy_24_args;
FuncTy_24_args.push_back(IntegerType::get(mod->getContext(), 32));
FunctionType* FuncTy_24 = FunctionType::get(
 /*Result=*/Type::getVoidTy(mod->getContext()),
 /*Params=*/FuncTy_24_args,
 /*isVarArg=*/false);

PointerType* PointerTy_23 = PointerType::get(FuncTy_24, 0);


// Function Declarations

Function* func_syscall = mod->getFunction("syscall");
if (!func_syscall) {
func_syscall = Function::Create(
 /*Type=*/FuncTy_7,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Name=*/"syscall", mod); // (external, no body)
func_syscall->setCallingConv(CallingConv::C);
}
AttributeSet func_syscall_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 func_syscall_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_syscall->setAttributes(func_syscall_PAL);

Function* func_clock_gettime = mod->getFunction("clock_gettime");
if (!func_clock_gettime) {
func_clock_gettime = Function::Create(
 /*Type=*/FuncTy_17,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Name=*/"clock_gettime", mod); // (external, no body)
func_clock_gettime->setCallingConv(CallingConv::C);
}
AttributeSet func_clock_gettime_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 func_clock_gettime_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_clock_gettime->setAttributes(func_clock_gettime_PAL);

Function* func_perror = mod->getFunction("perror");
if (!func_perror) {
func_perror = Function::Create(
 /*Type=*/FuncTy_22,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Name=*/"perror", mod); // (external, no body)
func_perror->setCallingConv(CallingConv::C);
}
AttributeSet func_perror_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 func_perror_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_perror->setAttributes(func_perror_PAL);

Function* func_exit = mod->getFunction("exit");
if (!func_exit) {
func_exit = Function::Create(
 /*Type=*/FuncTy_24,
 /*Linkage=*/GlobalValue::ExternalLinkage,
 /*Name=*/"exit", mod); // (external, no body)
func_exit->setCallingConv(CallingConv::C);
}
AttributeSet func_exit_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoReturn);
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 func_exit_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_exit->setAttributes(func_exit_PAL);

// Global Variable Declarations

GlobalVariable* gvar_array_active_pps = new GlobalVariable(/*Module=*/*mod, 
/*Type=*/ArrayTy_11,
/*isConstant=*/false,
/*Linkage=*/GlobalValue::ExternalLinkage,
/*Initializer=*/0, 
/*Name=*/"active_pps");

GlobalVariable* gvar_array_trust_pp_nos = new GlobalVariable(/*Module=*/*mod, 
/*Type=*/ArrayTy_9,
/*isConstant=*/false,
/*Linkage=*/GlobalValue::ExternalLinkage,
/*Initializer=*/0, 
/*Name=*/"trust_pp_nos");

GlobalVariable* gvar_array_duration_check_pp_nos = new GlobalVariable(/*Module=*/*mod, 
/*Type=*/ArrayTy_15,
/*isConstant=*/false,
/*Linkage=*/GlobalValue::ExternalLinkage,
/*Initializer=*/0, 
/*Name=*/"duration_check_pp_nos");

GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
/*Type=*/ArrayTy_20,
/*isConstant=*/true,
/*Linkage=*/GlobalValue::PrivateLinkage,
/*Initializer=*/0, // has initializer, specified below
/*Name=*/".str");
gvar_array__str->setAlignment(1);

// Constant Definitions
ConstantInt* const_int32_25 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("1"), 10));
ConstantInt* const_int64_26 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("186"), 10));
ConstantInt* const_int64_27 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("1023"), 10));
ConstantInt* const_int64_28 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("0"), 10));
ConstantInt* const_int32_29 = ConstantInt::get(mod->getContext(), APInt(32, StringRef("0"), 10));
ConstantFP* const_double_30 = ConstantFP::get(mod->getContext(), APFloat(1.000000e-09));
ConstantFP* const_double_31 = ConstantFP::get(mod->getContext(), APFloat(1.000000e-01));
ConstantInt* const_int64_32 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("-1"), 10));
ConstantInt* const_int64_33 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("1"), 10));
ConstantInt* const_int64_34 = ConstantInt::get(mod->getContext(), APInt(64, StringRef("330"), 10));
std::vector<Constant*> const_ptr_35_indices;
const_ptr_35_indices.push_back(const_int32_29);
const_ptr_35_indices.push_back(const_int32_29);
Constant* const_ptr_35 = ConstantExpr::getGetElementPtr(gvar_array__str, const_ptr_35_indices);
Constant *const_array_36 = ConstantDataArray::getString(mod->getContext(), "Syscall pp_end failed", true);

// Global Variable Definitions
gvar_array__str->setInitializer(const_array_36);

Function* func_pp_end = mod->getFunction("pp_end");
if (!func_pp_end) {
func_pp_end = Function::Create(
 /*Type=*/FuncTy_0,
 /*Linkage=*/GlobalValue::InternalLinkage,
 /*Name=*/"pp_end", mod); 
func_pp_end->setCallingConv(CallingConv::C);
}
AttributeSet func_pp_end_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   B.addAttribute(Attribute::UWTable);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 func_pp_end_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
func_pp_end->setAttributes(func_pp_end_PAL);
Function::arg_iterator args = func_pp_end->arg_begin();
Value* int64_pp_id = args++;
int64_pp_id->setName("pp_id");
Value* int32_pp_no = args++;
int32_pp_no->setName("pp_no");

BasicBlock* label_entry = BasicBlock::Create(mod->getContext(), "entry",func_pp_end,0);
BasicBlock* label_land_lhs_true = BasicBlock::Create(mod->getContext(), "land.lhs.true",func_pp_end,0);
BasicBlock* label_if_then = BasicBlock::Create(mod->getContext(), "if.then",func_pp_end,0);
BasicBlock* label_if_then10 = BasicBlock::Create(mod->getContext(), "if.then10",func_pp_end,0);
BasicBlock* label_if_then26 = BasicBlock::Create(mod->getContext(), "if.then26",func_pp_end,0);
BasicBlock* label_if_else = BasicBlock::Create(mod->getContext(), "if.else",func_pp_end,0);
BasicBlock* label_if_end = BasicBlock::Create(mod->getContext(), "if.end",func_pp_end,0);
BasicBlock* label_if_end31 = BasicBlock::Create(mod->getContext(), "if.end31",func_pp_end,0);
BasicBlock* label_if_then33 = BasicBlock::Create(mod->getContext(), "if.then33",func_pp_end,0);
BasicBlock* label_if_end34 = BasicBlock::Create(mod->getContext(), "if.end34",func_pp_end,0);
BasicBlock* label_if_end39 = BasicBlock::Create(mod->getContext(), "if.end39",func_pp_end,0);

// Block entry (label_entry)
AllocaInst* ptr_pp_id_addr = new AllocaInst(IntegerType::get(mod->getContext(), 64), "pp_id.addr", label_entry);
ptr_pp_id_addr->setAlignment(8);
AllocaInst* ptr_pp_no_addr = new AllocaInst(IntegerType::get(mod->getContext(), 32), "pp_no.addr", label_entry);
ptr_pp_no_addr->setAlignment(4);
AllocaInst* ptr_tid = new AllocaInst(IntegerType::get(mod->getContext(), 32), "tid", label_entry);
ptr_tid->setAlignment(4);
AllocaInst* ptr_tend = new AllocaInst(StructTy_struct_timespec, "tend", label_entry);
ptr_tend->setAlignment(8);
AllocaInst* ptr_tstart = new AllocaInst(PointerTy_3, "tstart", label_entry);
ptr_tstart->setAlignment(8);
AllocaInst* ptr_diff = new AllocaInst(Type::getDoubleTy(mod->getContext()), "diff", label_entry);
ptr_diff->setAlignment(8);
AllocaInst* ptr_ret = new AllocaInst(IntegerType::get(mod->getContext(), 64), "ret", label_entry);
ptr_ret->setAlignment(8);
StoreInst* void_37 = new StoreInst(int64_pp_id, ptr_pp_id_addr, false, label_entry);
void_37->setAlignment(8);
StoreInst* void_38 = new StoreInst(int32_pp_no, ptr_pp_no_addr, false, label_entry);
void_38->setAlignment(4);
CallInst* int64_call = CallInst::Create(func_syscall, const_int64_26, "call", label_entry);
int64_call->setCallingConv(CallingConv::C);
int64_call->setTailCall(false);
AttributeSet int64_call_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 int64_call_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
int64_call->setAttributes(int64_call_PAL);

BinaryOperator* int64_and = BinaryOperator::Create(Instruction::And, int64_call, const_int64_27, "and", label_entry);
CastInst* int32_conv = new TruncInst(int64_and, IntegerType::get(mod->getContext(), 32), "conv", label_entry);
StoreInst* void_39 = new StoreInst(int32_conv, ptr_tid, false, label_entry);
void_39->setAlignment(4);
LoadInst* int64_40 = new LoadInst(ptr_pp_id_addr, "", false, label_entry);
int64_40->setAlignment(8);
ICmpInst* int1_cmp = new ICmpInst(*label_entry, ICmpInst::ICMP_SGT, int64_40, const_int64_28, "cmp");
BranchInst::Create(label_land_lhs_true, label_if_end39, int1_cmp, label_entry);

// Block land.lhs.true (label_land_lhs_true)
LoadInst* int32_42 = new LoadInst(ptr_pp_no_addr, "", false, label_land_lhs_true);
int32_42->setAlignment(4);
CastInst* int64_idxprom = new SExtInst(int32_42, IntegerType::get(mod->getContext(), 64), "idxprom", label_land_lhs_true);
LoadInst* int32_43 = new LoadInst(ptr_tid, "", false, label_land_lhs_true);
int32_43->setAlignment(4);
CastInst* int64_idxprom2 = new SExtInst(int32_43, IntegerType::get(mod->getContext(), 64), "idxprom2", label_land_lhs_true);
std::vector<Value*> ptr_arrayidx_indices;
ptr_arrayidx_indices.push_back(const_int32_29);
ptr_arrayidx_indices.push_back(int64_idxprom2);
Instruction* ptr_arrayidx = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx_indices, "arrayidx", label_land_lhs_true);
std::vector<Value*> ptr_arrayidx3_indices;
ptr_arrayidx3_indices.push_back(const_int32_29);
ptr_arrayidx3_indices.push_back(int64_idxprom);
Instruction* ptr_arrayidx3 = GetElementPtrInst::Create(ptr_arrayidx, ptr_arrayidx3_indices, "arrayidx3", label_land_lhs_true);
LoadInst* int64_44 = new LoadInst(ptr_arrayidx3, "", false, label_land_lhs_true);
int64_44->setAlignment(8);
LoadInst* int64_45 = new LoadInst(ptr_pp_id_addr, "", false, label_land_lhs_true);
int64_45->setAlignment(8);
ICmpInst* int1_cmp4 = new ICmpInst(*label_land_lhs_true, ICmpInst::ICMP_EQ, int64_44, int64_45, "cmp4");
BranchInst::Create(label_if_then, label_if_end39, int1_cmp4, label_land_lhs_true);

// Block if.then (label_if_then)
LoadInst* int32_47 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then);
int32_47->setAlignment(4);
CastInst* int64_idxprom6 = new SExtInst(int32_47, IntegerType::get(mod->getContext(), 64), "idxprom6", label_if_then);
std::vector<Value*> ptr_arrayidx7_indices;
ptr_arrayidx7_indices.push_back(const_int32_29);
ptr_arrayidx7_indices.push_back(int64_idxprom6);
Instruction* ptr_arrayidx7 = GetElementPtrInst::Create(gvar_array_trust_pp_nos, ptr_arrayidx7_indices, "arrayidx7", label_if_then);
LoadInst* int64_48 = new LoadInst(ptr_arrayidx7, "", false, label_if_then);
int64_48->setAlignment(8);
ICmpInst* int1_cmp8 = new ICmpInst(*label_if_then, ICmpInst::ICMP_EQ, int64_48, const_int64_28, "cmp8");
BranchInst::Create(label_if_then10, label_if_end31, int1_cmp8, label_if_then);

// Block if.then10 (label_if_then10)
LoadInst* int32_50 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then10);
int32_50->setAlignment(4);
CastInst* int64_idxprom11 = new SExtInst(int32_50, IntegerType::get(mod->getContext(), 64), "idxprom11", label_if_then10);
LoadInst* int32_51 = new LoadInst(ptr_tid, "", false, label_if_then10);
int32_51->setAlignment(4);
CastInst* int64_idxprom12 = new SExtInst(int32_51, IntegerType::get(mod->getContext(), 64), "idxprom12", label_if_then10);
std::vector<Value*> ptr_arrayidx13_indices;
ptr_arrayidx13_indices.push_back(const_int32_29);
ptr_arrayidx13_indices.push_back(int64_idxprom12);
Instruction* ptr_arrayidx13 = GetElementPtrInst::Create(gvar_array_duration_check_pp_nos, ptr_arrayidx13_indices, "arrayidx13", label_if_then10);
std::vector<Value*> ptr_arrayidx14_indices;
ptr_arrayidx14_indices.push_back(const_int32_29);
ptr_arrayidx14_indices.push_back(int64_idxprom11);
Instruction* ptr_arrayidx14 = GetElementPtrInst::Create(ptr_arrayidx13, ptr_arrayidx14_indices, "arrayidx14", label_if_then10);
StoreInst* void_52 = new StoreInst(ptr_arrayidx14, ptr_tstart, false, label_if_then10);
void_52->setAlignment(8);
std::vector<Value*> int32_call15_params;
int32_call15_params.push_back(const_int32_29);
int32_call15_params.push_back(ptr_tend);
CallInst* int32_call15 = CallInst::Create(func_clock_gettime, int32_call15_params, "call15", label_if_then10);
int32_call15->setCallingConv(CallingConv::C);
int32_call15->setTailCall(false);
AttributeSet int32_call15_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 int32_call15_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
int32_call15->setAttributes(int32_call15_PAL);

std::vector<Value*> ptr_tv_sec_indices;
ptr_tv_sec_indices.push_back(const_int32_29);
ptr_tv_sec_indices.push_back(const_int32_29);
Instruction* ptr_tv_sec = GetElementPtrInst::Create(ptr_tend, ptr_tv_sec_indices, "tv_sec", label_if_then10);
LoadInst* int64_53 = new LoadInst(ptr_tv_sec, "", false, label_if_then10);
int64_53->setAlignment(8);
CastInst* double_conv16 = new SIToFPInst(int64_53, Type::getDoubleTy(mod->getContext()), "conv16", label_if_then10);
std::vector<Value*> ptr_tv_nsec_indices;
ptr_tv_nsec_indices.push_back(const_int32_29);
ptr_tv_nsec_indices.push_back(const_int32_25);
Instruction* ptr_tv_nsec = GetElementPtrInst::Create(ptr_tend, ptr_tv_nsec_indices, "tv_nsec", label_if_then10);
LoadInst* int64_54 = new LoadInst(ptr_tv_nsec, "", false, label_if_then10);
int64_54->setAlignment(8);
CastInst* double_conv17 = new SIToFPInst(int64_54, Type::getDoubleTy(mod->getContext()), "conv17", label_if_then10);
BinaryOperator* double_mul = BinaryOperator::Create(Instruction::FMul, const_double_30, double_conv17, "mul", label_if_then10);
BinaryOperator* double_add = BinaryOperator::Create(Instruction::FAdd, double_conv16, double_mul, "add", label_if_then10);
LoadInst* ptr_55 = new LoadInst(ptr_tstart, "", false, label_if_then10);
ptr_55->setAlignment(8);
std::vector<Value*> ptr_tv_sec18_indices;
ptr_tv_sec18_indices.push_back(const_int32_29);
ptr_tv_sec18_indices.push_back(const_int32_29);
Instruction* ptr_tv_sec18 = GetElementPtrInst::Create(ptr_55, ptr_tv_sec18_indices, "tv_sec18", label_if_then10);
LoadInst* int64_56 = new LoadInst(ptr_tv_sec18, "", false, label_if_then10);
int64_56->setAlignment(8);
CastInst* double_conv19 = new SIToFPInst(int64_56, Type::getDoubleTy(mod->getContext()), "conv19", label_if_then10);
LoadInst* ptr_57 = new LoadInst(ptr_tstart, "", false, label_if_then10);
ptr_57->setAlignment(8);
std::vector<Value*> ptr_tv_nsec20_indices;
ptr_tv_nsec20_indices.push_back(const_int32_29);
ptr_tv_nsec20_indices.push_back(const_int32_25);
Instruction* ptr_tv_nsec20 = GetElementPtrInst::Create(ptr_57, ptr_tv_nsec20_indices, "tv_nsec20", label_if_then10);
LoadInst* int64_58 = new LoadInst(ptr_tv_nsec20, "", false, label_if_then10);
int64_58->setAlignment(8);
CastInst* double_conv21 = new SIToFPInst(int64_58, Type::getDoubleTy(mod->getContext()), "conv21", label_if_then10);
BinaryOperator* double_mul22 = BinaryOperator::Create(Instruction::FMul, const_double_30, double_conv21, "mul22", label_if_then10);
BinaryOperator* double_add23 = BinaryOperator::Create(Instruction::FAdd, double_conv19, double_mul22, "add23", label_if_then10);
BinaryOperator* double_sub = BinaryOperator::Create(Instruction::FSub, double_add, double_add23, "sub", label_if_then10);
StoreInst* void_59 = new StoreInst(double_sub, ptr_diff, false, label_if_then10);
void_59->setAlignment(8);
LoadInst* double_60 = new LoadInst(ptr_diff, "", false, label_if_then10);
double_60->setAlignment(8);
FCmpInst* int1_cmp24 = new FCmpInst(*label_if_then10, FCmpInst::FCMP_OLT, double_60, const_double_31, "cmp24");
BranchInst::Create(label_if_then26, label_if_else, int1_cmp24, label_if_then10);

// Block if.then26 (label_if_then26)
LoadInst* int32_62 = new LoadInst(ptr_pp_no_addr, "", false, label_if_then26);
int32_62->setAlignment(4);
CastInst* int64_idxprom27 = new SExtInst(int32_62, IntegerType::get(mod->getContext(), 64), "idxprom27", label_if_then26);
std::vector<Value*> ptr_arrayidx28_indices;
ptr_arrayidx28_indices.push_back(const_int32_29);
ptr_arrayidx28_indices.push_back(int64_idxprom27);
Instruction* ptr_arrayidx28 = GetElementPtrInst::Create(gvar_array_trust_pp_nos, ptr_arrayidx28_indices, "arrayidx28", label_if_then26);
StoreInst* void_63 = new StoreInst(const_int64_32, ptr_arrayidx28, false, label_if_then26);
void_63->setAlignment(8);
BranchInst::Create(label_if_end, label_if_then26);

// Block if.else (label_if_else)
LoadInst* int32_65 = new LoadInst(ptr_pp_no_addr, "", false, label_if_else);
int32_65->setAlignment(4);
CastInst* int64_idxprom29 = new SExtInst(int32_65, IntegerType::get(mod->getContext(), 64), "idxprom29", label_if_else);
std::vector<Value*> ptr_arrayidx30_indices;
ptr_arrayidx30_indices.push_back(const_int32_29);
ptr_arrayidx30_indices.push_back(int64_idxprom29);
Instruction* ptr_arrayidx30 = GetElementPtrInst::Create(gvar_array_trust_pp_nos, ptr_arrayidx30_indices, "arrayidx30", label_if_else);
StoreInst* void_66 = new StoreInst(const_int64_33, ptr_arrayidx30, false, label_if_else);
void_66->setAlignment(8);
BranchInst::Create(label_if_end, label_if_else);

// Block if.end (label_if_end)
BranchInst::Create(label_if_end31, label_if_end);

// Block if.end31 (label_if_end31)
LoadInst* int64_69 = new LoadInst(ptr_pp_id_addr, "", false, label_if_end31);
int64_69->setAlignment(8);
std::vector<Value*> int64_call32_params;
int64_call32_params.push_back(const_int64_34);
int64_call32_params.push_back(int64_69);
CallInst* int64_call32 = CallInst::Create(func_syscall, int64_call32_params, "call32", label_if_end31);
int64_call32->setCallingConv(CallingConv::C);
int64_call32->setTailCall(false);
AttributeSet int64_call32_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 int64_call32_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
int64_call32->setAttributes(int64_call32_PAL);

StoreInst* void_70 = new StoreInst(int64_call32, ptr_ret, false, label_if_end31);
void_70->setAlignment(8);
LoadInst* int64_71 = new LoadInst(ptr_ret, "", false, label_if_end31);
int64_71->setAlignment(8);
ICmpInst* int1_tobool = new ICmpInst(*label_if_end31, ICmpInst::ICMP_NE, int64_71, const_int64_28, "tobool");
BranchInst::Create(label_if_then33, label_if_end34, int1_tobool, label_if_end31);

// Block if.then33 (label_if_then33)
CallInst* void_73 = CallInst::Create(func_perror, const_ptr_35, "", label_if_then33);
void_73->setCallingConv(CallingConv::C);
void_73->setTailCall(false);
AttributeSet void_73_PAL;
void_73->setAttributes(void_73_PAL);

CallInst* void_74 = CallInst::Create(func_exit, const_int32_25, "", label_if_then33);
void_74->setCallingConv(CallingConv::C);
void_74->setTailCall(false);
AttributeSet void_74_PAL;
{
 SmallVector<AttributeSet, 4> Attrs;
 AttributeSet PAS;
  {
   AttrBuilder B;
   B.addAttribute(Attribute::NoReturn);
   B.addAttribute(Attribute::NoUnwind);
   PAS = AttributeSet::get(mod->getContext(), ~0U, B);
  }
 
 Attrs.push_back(PAS);
 void_74_PAL = AttributeSet::get(mod->getContext(), Attrs);
 
}
void_74->setAttributes(void_74_PAL);

new UnreachableInst(mod->getContext(), label_if_then33);

// Block if.end34 (label_if_end34)
LoadInst* int32_76 = new LoadInst(ptr_pp_no_addr, "", false, label_if_end34);
int32_76->setAlignment(4);
CastInst* int64_idxprom35 = new SExtInst(int32_76, IntegerType::get(mod->getContext(), 64), "idxprom35", label_if_end34);
LoadInst* int32_77 = new LoadInst(ptr_tid, "", false, label_if_end34);
int32_77->setAlignment(4);
CastInst* int64_idxprom36 = new SExtInst(int32_77, IntegerType::get(mod->getContext(), 64), "idxprom36", label_if_end34);
std::vector<Value*> ptr_arrayidx37_indices;
ptr_arrayidx37_indices.push_back(const_int32_29);
ptr_arrayidx37_indices.push_back(int64_idxprom36);
Instruction* ptr_arrayidx37 = GetElementPtrInst::Create(gvar_array_active_pps, ptr_arrayidx37_indices, "arrayidx37", label_if_end34);
std::vector<Value*> ptr_arrayidx38_indices;
ptr_arrayidx38_indices.push_back(const_int32_29);
ptr_arrayidx38_indices.push_back(int64_idxprom35);
Instruction* ptr_arrayidx38 = GetElementPtrInst::Create(ptr_arrayidx37, ptr_arrayidx38_indices, "arrayidx38", label_if_end34);
StoreInst* void_78 = new StoreInst(const_int64_28, ptr_arrayidx38, false, label_if_end34);
void_78->setAlignment(8);
BranchInst::Create(label_if_end39, label_if_end34);

// Block if.end39 (label_if_end39)
ReturnInst::Create(mod->getContext(), label_if_end39);
return func_pp_end;
}
